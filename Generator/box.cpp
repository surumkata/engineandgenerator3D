#include <stdio.h>
#include <stdlib.h>
#include "box.h"

void write_faceOxz_down(float size, int div, points* ps) {
    float x, z, y;

    x = -size / 2;
    z = size / 2;
    y = -size / 2;

    float initz = z;
    float part = size / div;

    int i1 = 0;

    while (i1 < div) {
        int i2 = 0;
        while (i2 < div) {
            float ax = x + part;
            float az = z - part;            
            
            point p1 = point(x, y, z,0,-1,0);
            point p2 = point(x, y, az, 0, -1, 0);
            point p3 = point(ax, y, z, 0, -1, 0);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            p1 = point(ax, y, az, 0, -1, 0);
            p2 = point(ax, y, z, 0, -1, 0);
            p3 = point(x, y, az, 0, -1, 0);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            i2 = i2 + 1;
            z = az;
        }
        x = x + part;
        z = initz;
        i1 = i1 + 1;
    }
}

void write_faceOxz_up(float size, int div, points* ps) {
    float x, z, y;

    x = -size / 2;
    z = size / 2;
    y = size / 2;

    float initz = z;
    float part = size / div;

    int i1 = 0;

    while (i1 < div) {
        int i2 = 0;
        while (i2 < div) {
            float ax = x + part;
            float az = z - part;
            
            point p1 = point(x, y, az, 0, 1, 0);
            point p2 = point(x, y, z, 0, 1, 0);
            point p3 = point(ax, y, z, 0, 1, 0);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);

            p1 = point(ax, y, z, 0, 1, 0);
            p2 = point(ax, y, az, 0, 1, 0);
            p3 = point(x, y, az, 0, 1, 0);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            i2 = i2 + 1;
            z = az;
        }
        x = x + part;
        z = initz;
        i1 = i1 + 1;
    }
}

void write_faceOyz_front(float size, int div, points* ps) {
    float x, z, y;

    x = size / 2;
    z = size / 2;
    y = -size / 2;

    float initz = z;
    float part = size / div;

    int i1 = 0;

    while (i1 < div) {
        int i2 = 0;
        while (i2 < div) {
            float ay = y + part;
            float az = z - part;
            
            point p1 = point(x, y, z, 1, 0, 0);
            point p2 = point(x, y, az, 1, 0, 0);
            point p3 = point(x, ay, z, 1, 0, 0);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            p1 = point(x, ay, az, 1, 0, 0);
            p2 = point(x, ay, z, 1, 0, 0);
            p3 = point(x, y, az, 1, 0, 0);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            i2 = i2 + 1;
            z = az;
        }
        y = y + part;
        z = initz;
        i1 = i1 + 1;
    }
}

void write_faceOyz_back(float size, int div, points* ps) {
    float x, z, y;

    x = -size / 2;
    z = size / 2;
    y = -size / 2;

    float initz = z;
    float part = size / div;

    int i1 = 0;

    while (i1 < div) {
        int i2 = 0;
        while (i2 < div) {
            float ay = y + part;
            float az = z - part;
            
            point p1 = point(x, y, az, -1, 0, 0);
            point p2 = point(x, y, z, -1, 0, 0);
            point p3 = point(x, ay, z, -1, 0, 0);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            p1 = point(x, ay, z, -1, 0, 0);
            p2 = point(x, ay, az, -1, 0, 0);
            p3 = point(x, y, az, -1, 0, 0);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            i2 = i2 + 1;
            z = az;
        }
        y = y + part;
        z = initz;
        i1 = i1 + 1;
    }
}

void write_faceOxy_back(float size, int div, points* ps) {
    float x, z, y;

    x = -size / 2;
    z = -size / 2;
    y = size / 2;

    float inity = y;
    float part = size / div;

    int i1 = 0;

    while (i1 < div) {
        int i2 = 0;
        while (i2 < div) {
            float ax = x + part;
            float ay = y - part;
            
            point p1 = point(x, ay, z, 0, 0, 1);
            point p2 = point(x, y, z, 0, 0, 1);
            point p3 = point(ax, y, z, 0, 0, 1);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);

            p1 = point(ax, y, z, 0, 0, 1);
            p2 = point(ax, ay, z, 0, 0, 1);
            p3 = point(x, ay, z, 0, 0, 1);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            i2 = i2 + 1;
            y = ay;
        }
        x = x + part;
        y = inity;
        i1 = i1 + 1;
    }
}

void write_faceOxy_front(float size, int div, points* ps) {
    float x, z, y;

    x = -size / 2;
    z = size / 2;
    y = size / 2;

    float inity = y;
    float part = size / div;

    int i1 = 0;

    while (i1 < div) {
        int i2 = 0;
        while (i2 < div) {
            float ax = x + part;
            float ay = y - part;
            
            point p1 = point(x, y, z, 0, 0, -1);
            point p2 = point(x, ay, z, 0, 0, -1);
            point p3 = point(ax, y, z, 0, 0, -1);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            p1 = point(ax, ay, z, 0, 0, -1);
            p2 = point(ax, y, z, 0, 0, -1);
            p3 = point(x, ay, z, 0, 0, -1);
            ps->add_point(p1);
            ps->add_point(p2);
            ps->add_point(p3);
            
            i2 = i2 + 1;
            y = ay;
        }
        x = x + part;
        y = inity;
        i1 = i1 + 1;
    }
}


int write_box(float size, int div, char* fname) {
    FILE* file = fopen(fname, "w+");
    points ps = points();

    write_faceOxz_down(size, div, &ps);
    write_faceOxz_up(size, div, &ps);
    write_faceOyz_front(size, div, &ps);
    write_faceOyz_back(size, div, &ps);
    write_faceOxy_front(size, div, &ps);
    write_faceOxy_back(size, div, &ps);

    write_points(ps,file);
    fclose(file);
    return 0;
}
