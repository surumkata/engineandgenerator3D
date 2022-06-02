#include "points.cpp" 
#include "transformation.cpp"


class rgb {
public:
	//maybe tem de ser floats
	int r;
	int g;
	int b;
	rgb() {
		this->r = 0;
		this->g = 0;
		this->b = 0;
	}
	rgb(int r, int g, int b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}
	float* toFloatArr() {
		float rgb[4] = { r / 255,g / 255,b / 255,1};
		return rgb;
	}
};

class color {
public:
	rgb diffuse;
	rgb ambient;
	rgb specular;
	rgb emissive;
	int shininess; //maybe tem de ser float

	color(){
		this->diffuse = rgb(200,200,200);
		this->ambient = rgb(50,50,50);
		this->specular = rgb();
		this->emissive = rgb();
		this->shininess = 0;
	}
	void add_diffuse(int r, int g, int b) {
		this->diffuse = rgb(r, g, b);
	}

	float* get_diffuse() {
		return this->diffuse.toFloatArr();
	}

	void add_ambient(int r, int g, int b) {
		this->ambient = rgb(r, g, b);
	}

	float* get_ambient() {
		return this->ambient.toFloatArr();
	}

	void add_specular(int r, int g, int b) {
		this->specular = rgb(r, g, b);
	}

	float* get_specular() {
		return this->specular.toFloatArr();
	}

	void add_emissive(int r, int g, int b) {
		this->emissive = rgb(r, g, b);
	}

	float* get_emissive() {
		return this->emissive.toFloatArr();
	}

	void add_shininess(int shininess) {
		this->shininess = shininess;
	}
};

class model {
public:
	vector<float> ps;
	vector<unsigned int> idxs;
	GLuint indices, vertices;
	unsigned int indexCount;
	const char* texture;
	color c;

	model() {
		this->idxs;
		this->indexCount = 0;
		this->indices = 0;
		this->vertices = 0;
		this->texture = "";
		this->c = color();
	}

	void add_color(color c) {
		this->c = c;
	}

	void add_point(point p) {
		ps.push_back(p.getX());
		ps.push_back(p.getY());
		ps.push_back(p.getZ());
	}

	void add_index(int idx) {
		this->idxs.push_back(idx);
		this->indexCount += 1;
	}

	void add_texture(const char* texture) {
		this->texture = texture;
		//provavelmente nao funciona, tem que se fazer um copy da string qql
	}

	void prepare_data() {
		//criar o VBO
		glGenBuffers(1, &(this->vertices));
		// copiar o vector para a mem�ria gr�fica
		glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
		glBufferData(
			GL_ARRAY_BUFFER, // tipo do buffer, s� � relevante na altura do desenho
			sizeof(float) * this->ps.size(), // tamanho do vector em bytes
			this->ps.data(), // os dados do array associado ao vector
			GL_STATIC_DRAW); // indicativo da utiliza��o (est�tico e para desenho)
		//criar o VBO de indices
		glGenBuffers(1, &(this->indices));
		// copiar o vector dos indices
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			sizeof(unsigned int) * this->idxs.size(),
			this->idxs.data(),
			GL_STATIC_DRAW);
	}

	void render() {

		glMaterialfv(GL_FRONT, GL_DIFFUSE, c.get_diffuse());
		glMaterialfv(GL_FRONT, GL_AMBIENT, c.get_ambient());
		glMaterialfv(GL_FRONT, GL_EMISSION, c.get_emissive());
		glMaterialfv(GL_FRONT, GL_SPECULAR, c.get_specular());
		glMaterialf(GL_FRONT, GL_SHININESS, c.shininess);

		glBindBuffer(GL_ARRAY_BUFFER, this->vertices);
		glVertexPointer(3, GL_FLOAT, 0, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indices);
		glDrawElements(GL_TRIANGLES,
			this->indexCount, // n�mero de �ndices a desenhar
			GL_UNSIGNED_INT, // tipo de dados dos �ndices
			NULL);// par�metro n�o utilizado 
	}
};


class models {
public:
	vector<model> mds;

	models() {
		this->mds;
	}

	void add_model(model m) {
		this->mds.push_back(m);
	}


	void prepare_data() {
		for (vector<model>::iterator it = this->mds.begin(); it != this->mds.end(); ++it) {
			it->prepare_data();
		}
	}

	void render() {
		for (vector<model>::iterator it = this->mds.begin(); it != this->mds.end(); ++it) {
			it->render();
		}
	}
};

class transformations {
public:
	vector<transformation*> trs;

	transformations() {}

	void add_transformation(transformation* tr) {
		this->trs.push_back(tr);
	}

	void transform() {
		glPushMatrix();
		for (vector<transformation*>::iterator it = this->trs.begin(); it != this->trs.end(); ++it) {
			(*it)->transform();
		}
	}

	void destransform() {
		glPopMatrix();
	}

};


class group {
public:
	vector<group> gs;
	models ms;
	transformations trs;

	group(){
		this->ms = models();
	}

	void add_group(group g) {
		gs.push_back(g);
	}

	void add_models(models ms) {
		this->ms = ms;
	}

	void add_transformations(transformations trs) {
		this->trs = trs;
	}

	void prepare_data() {
		for (vector<group>::iterator it = this->gs.begin(); it != this->gs.end(); ++it) {
			it->prepare_data();
		}
		ms.prepare_data();
	}

	void render() {
		trs.transform();
		for (vector<group>::iterator it2 = this->gs.begin(); it2 != this->gs.end(); ++it2) {
			it2->render();
		}
		ms.render();
		trs.destransform();
	}
};