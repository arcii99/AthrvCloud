//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265358979323846
#define DAYS_IN_YEAR 365.242
#define SCALE_FACTOR 5

typedef struct {
    double a;   // semi-major axis
    double e;   // eccentricity
    double i;   // inclination
    double f;   // argument of periapsis
    double o;   // longitude of the ascending node
    double p;   // orbital period
    double r;   // radius
} planet_t;

typedef struct {
    double x;
    double y;
    double z;
} vector_3d_t;

planet_t sun = {0, 0, 0, 0, 0, 0, 10};
planet_t mercury = {0.38710, 0.20563, 7.00500, 29.12400, 48.33100, 0.2408467 * DAYS_IN_YEAR, 1};
planet_t venus = {0.72333, 0.00677, 3.39456, 54.88400, 76.68000, 0.6151973 * DAYS_IN_YEAR, 1.2};
planet_t earth = {1, 0.01671, 0.00005, 288.06400, -11.26064, 1 * DAYS_IN_YEAR, 1.5};
planet_t mars = {1.52368, 0.09340, 1.84969, 286.50200, 49.55800, 1.8808476 * DAYS_IN_YEAR, 1.3};

double get_radius(planet_t p, double t) {
    return p.r;
}

vector_3d_t get_position(planet_t p, double t) {
    vector_3d_t pos;

    double M = 2 * PI * t / p.p;
    double E = M;
    double delta = 0.05;
    int i;
    for (i = 0; i < 10; i++) {
        double E1 = E - (E - p.e * sin(E) - M) / (1 - p.e * cos(E));
        if (fabs(E1 - E) < delta) {
            break;
        }
        E = E1;
    }
    double v = 2 * atan(sqrt((1 + p.e) / (1 - p.e)) * tan(E / 2));
    double r = p.a * (1 - p.e * cos(E));
    double x = r * (cos(p.o) * cos(p.f + v) - sin(p.o) * sin(p.f + v) * cos(p.i));
    double y = r * (sin(p.o) * cos(p.f + v) + cos(p.o) * sin(p.f + v) * cos(p.i));
    double z = r * sin(p.f + v) * sin(p.i);
    pos.x = x;
    pos.y = y;
    pos.z = z;
    return pos;
}

void draw_planet(planet_t p, double t) {
    vector_3d_t pos = get_position(p, t);
    double r = get_radius(p, t);

    glPushMatrix();
    glTranslatef(pos.x * SCALE_FACTOR, pos.y * SCALE_FACTOR, pos.z * SCALE_FACTOR);
    glutSolidSphere(r * SCALE_FACTOR, 20, 20);
    glPopMatrix();
}

void display() {
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0, 20, 150, 0, 0, 0, 0, 1, 0);

    glColor3f(1, 1, 0.5);
    draw_planet(sun, t);
    glColor3f(0.5, 0.5, 0.5);
    draw_planet(mercury, t);
    glColor3f(0.8, 0.5, 0.2);
    draw_planet(venus, t);
    glColor3f(0, 0.5, 1);
    draw_planet(earth, t);
    glColor3f(1, 0.2, 0.2);
    draw_planet(mars, t);

    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Solar System Simulation");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);

    glShadeModel(GL_SMOOTH);

    glutMainLoop();

    return 0;
}