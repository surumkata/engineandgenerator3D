#include <fstream>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

class translation {
public:
    float x;
    float y;
    float z;
    bool have;
    translation() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->have = false;
    }
    translation(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->have = true;
    }
    void translate() {
        if (this->have) {
            printf("a fazer translate\n");
            glTranslatef(this->x, this->y, this->z);
        }
    }
};