//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: active
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#define PI 3.14159265358979323846
#define G 6.67428e-11  // gravitational constant

// window size and position
#define WIDTH  600
#define HEIGHT 600
#define XPOS   50
#define YPOS   50
#define TITLE  "Solar System Simulation"

// time step for simulation
#define DT 86400  // one day (in seconds)

typedef struct {
    double m;  // mass
    double r[3];  // position
    double v[3];  // velocity
} Body;

Body sun = {1.9891e30, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};
Body earth = {5.9736e24, {147e9, 0.0, 0.0}, {0.0, 30300.0, 0.0}};
Body moon = {7.3477e22, {147e9 + 384400e3, 0.0, 0.0}, {0.0, 30300.0 + 1022.0, 0.0}};

void display();
void idle();
void reshape(int w, int h);
void init();
void drawBody(Body body);

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(XPOS, YPOS);
    glutCreateWindow(TITLE);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}

// draw the bodies
void drawBody(Body body) {
    double r = pow(body.m / (4.0 / 3.0 * PI), 1.0 / 3.0);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(body.r[0] / 1e9, body.r[1] / 1e9, body.r[2] / 1e9);
    glutSolidSphere(r / 1e9, 20, 20);
    glPopMatrix();
}

// display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -20.0);
    drawBody(sun);
    drawBody(earth);
    drawBody(moon);
    glutSwapBuffers();
}

// idle function
void idle() {
    // calculate new positions and velocities of the bodies
    double r[3], a[3], F[3];
    // compute the force on the earth due to the sun
    for (int i = 0; i < 3; i++) {
        r[i] = earth.r[i] - sun.r[i];
        F[i] = G * sun.m * earth.m / pow(sqrt(pow(r[0], 2) + pow(r[1], 2) + pow(r[2], 2)), 3) * r[i];
        a[i] = F[i] / earth.m;
        earth.v[i] += a[i] * DT;
        earth.r[i] += earth.v[i] * DT;
    }
    // compute the force on the moon due to the earth and the sun
    for (int i = 0; i < 3; i++) {
        r[i] = moon.r[i] - earth.r[i];
        F[i] = G * earth.m * moon.m / pow(sqrt(pow(r[0], 2) + pow(r[1], 2) + pow(r[2], 2)), 3) * r[i];
        r[i] = moon.r[i] - sun.r[i];
        F[i] += G * sun.m * moon.m / pow(sqrt(pow(r[0], 2) + pow(r[1], 2) + pow(r[2], 2)), 3) * r[i];
        a[i] = F[i] / moon.m;
        moon.v[i] += a[i] * DT;
        moon.r[i] += moon.v[i] * DT;
    }
    glutPostRedisplay();
}

// reshape function
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

// initialization function
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightPos[3] = {1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}