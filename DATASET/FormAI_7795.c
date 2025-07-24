//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define WIDTH 400
#define HEIGHT 400
#define MAX_DEPTH 5

double angle = 0;

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);
}

void draw_fractal(int depth) {
    if (depth == MAX_DEPTH) {
        return;
    }

    glPushMatrix();

    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0, 1);
    glEnd();

    glTranslatef(0, 1, 0);
    glRotatef(angle, 0, 0, 1);
    glScalef(0.5, 0.5, 1);
    draw_fractal(depth + 1);

    glPopMatrix();
    glPushMatrix();

    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(1, 0);
    glEnd();

    glTranslatef(1, 0, 0);
    glRotatef(angle, 0, 0, 1);
    glScalef(0.5, 0.5, 1);
    draw_fractal(depth + 1);

    glPopMatrix();
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 1);
    glLineWidth(2);
    draw_fractal(0);

    glutSwapBuffers();
}

void update(int value) {
    angle += 5;
    angle = fmod(angle, 360);
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Fractal Generation");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    glutMainLoop();
    return 0;
}