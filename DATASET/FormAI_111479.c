//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: lively
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <GL/glut.h>

#define pi 3.14159265358979323846
#define DEG2RAD(deg) (deg * pi / 180)

float win_width = 1000;
float win_height = 600;

double year_count = 1;
double year_days = 365.25;

double rotate_x = 0.0;
double rotate_y = 0.0;

double zoom = 30.0;

double sun_radius = 20.0;
double sun_color[] = {1.0, 1.0, 0.0};

double mercury_radius = 3.0;
double mercury_color[] = {0.5, 0.5, 0.5};
double mercury_distance = 35.0;
double mercury_rotation = 58.64;
double mercury_orbit = 0.24;

double venus_radius = 6.0;
double venus_color[] = {1.0, 0.6, 0.0};
double venus_distance = 45.0;
double venus_rotation = 243.0;
double venus_orbit = 0.62;

double earth_radius = 7.0;
double earth_color[] = {0.0, 0.7, 1.0};
double earth_distance = 60.0;
double earth_rotation = 1.0;
double earth_orbit = 1.0;

double mars_radius = 4.0;
double mars_color[] = {1.0, 0.5, 0.0};
double mars_distance = 70.0;
double mars_rotation = 1.03;
double mars_orbit = 1.88;

double jupiter_radius = 10.0;
double jupiter_color[] = {0.7, 0.4, 0.0};
double jupiter_distance = 85.0;
double jupiter_rotation = 0.41;
double jupiter_orbit = 11.86;

double saturn_radius = 9.0;
double saturn_color[] = {1.0, 0.8, 0.0};
double saturn_distance = 100.0;
double saturn_rotation = 0.42;
double saturn_orbit = 29.46;

double uranus_radius = 8.0;
double uranus_color[] = {0.0, 0.8, 1.0};
double uranus_distance = 115.0;
double uranus_rotation = -0.72;
double uranus_orbit = 84.01;

double neptune_radius = 8.0;
double neptune_color[] = {0.0, 0.4, 1.0};
double neptune_distance = 130.0;
double neptune_rotation = 0.67;
double neptune_orbit = 164.79;

void draw_circle(double radius) {
    glBegin(GL_POLYGON);
        for(int i=0; i<360; i++) {
            double rad = DEG2RAD(i);
            glVertex3f(radius*cos(rad), 0.0, radius*sin(rad));
        }
    glEnd();
}

void draw_sphere(double radius, double color[]) {
    glColor3f(color[0], color[1], color[2]);
    glutSolidSphere(radius, 50, 50);
}

void draw_orbit(double distance) {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
        for(int i=0; i<360; i++) {
            double rad = DEG2RAD(i);
            glVertex3f(distance*cos(rad), 0.0, distance*sin(rad));
        }
    glEnd();
}

void draw_planet(double radius, double color[], double distance, double rotation, double orbit, double year) {
    glPushMatrix();
        glRotatef(rotation, 0.0, 1.0, 0.0);
        glTranslatef(distance, 0.0, 0.0);
        glRotatef(year_count*360/year, 0.0, 1.0, 0.0);
        draw_sphere(radius, color);
        draw_orbit(distance);
    glPopMatrix();
}

void draw_sun() {
    draw_sphere(sun_radius, sun_color);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 20.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    draw_sun();

    draw_planet(mercury_radius, mercury_color, mercury_distance, 0.0, mercury_orbit, 88.0);
    draw_planet(venus_radius, venus_color, venus_distance, 0.0, venus_orbit, 225.0);
    draw_planet(earth_radius, earth_color, earth_distance, 0.0, earth_orbit, 365.0);
    draw_planet(mars_radius, mars_color, mars_distance, 0.0, mars_orbit, 687.0);
    draw_planet(jupiter_radius, jupiter_color, jupiter_distance, 0.0, jupiter_orbit, 4329.0);
    draw_planet(saturn_radius, saturn_color, saturn_distance, 0.0, saturn_orbit, 10747.0);
    draw_planet(uranus_radius, uranus_color, uranus_distance, 0.0, uranus_orbit, 30589.0);
    draw_planet(neptune_radius, neptune_color, neptune_distance, 0.0, neptune_orbit, 59800.0);

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if(key == 'q' || key == 'Q')
        exit(0);
}

void specialKeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT:
            rotate_y -= 5;
            break;
        case GLUT_KEY_RIGHT:
            rotate_y += 5;
            break;
        case GLUT_KEY_UP:
            rotate_x -= 5;
            break;
        case GLUT_KEY_DOWN:
            rotate_x += 5;
            break;
        case GLUT_KEY_PAGE_UP:
            zoom -= 1.0;
            break;
        case GLUT_KEY_PAGE_DOWN:
            zoom += 1.0;
            break;
    }
    glutPostRedisplay();
}

void timer(int value) {
    year_count += 1;
    glutPostRedisplay();
    glutTimerFunc(10, timer, 0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(win_width, win_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Solar System Simulation");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(reshape);
    glEnable(GL_DEPTH_TEST);
    glutTimerFunc(10, timer, 0);
    glutMainLoop();
    return 0;
}