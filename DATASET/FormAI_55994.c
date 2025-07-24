//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

/* Program Constants */
#define PI 3.1415926535897932384626433832795
#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define TIMER_INTERVAL 20
#define SOLAR_SYSTEM_SCALE 20.0
#define NUMBER_OF_PLANETS 7
#define SUN_RADIUS 2.0
#define MOON_RADIUS 0.5
#define EARTH_RADIUS 1.2
#define MAX_ORBITS 5

/* Planet Properties */
typedef struct Planet {
    GLfloat distanceFromSun;    // Distance from Sun (million Km)
    GLfloat radius;             // Radius of planet (Earth radii)
    GLfloat orbitSpeed;         // Speed of orbit (km/s)
    GLfloat rotationSpeed;      // Speed of self-rotation (deg/day)
    GLfloat axialTilt;          // Tilt of planet's axis (deg)
    GLfloat color[3];           // RGB Color of planet
    GLfloat orbitOffset;        // Orbit offset (deg)
    GLfloat angle;              // Current angle in orbit (deg)
    GLfloat x, y, z;            // Current position
    GLint numOrbits;            // Number of orbits planet has completed
} Planet;

/* Global Variables */
Planet planets[NUMBER_OF_PLANETS];
GLint windowWidth = WINDOW_WIDTH;
GLint windowHeight = WINDOW_HEIGHT;

/* Function Prototypes */
void initGL();
void display();
void timer(int duration);
void drawPlanet(GLfloat radius, GLfloat color[], GLfloat x, GLfloat y, GLfloat z);
void drawOrbit(GLfloat radius, GLint numOrbits);
void drawString(const char* str, GLfloat x, GLfloat y);

/* Initialization */
void initGL() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, (GLfloat)windowWidth/(GLfloat)windowHeight, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

/* Draw a planet */
void drawPlanet(GLfloat radius, GLfloat color[], GLfloat x, GLfloat y, GLfloat z) {
    glColor3f(color[0], color[1], color[2]);
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidSphere(radius, 50, 50);
    glPopMatrix();
}

/* Draw an orbit */
void drawOrbit(GLfloat radius, GLint numOrbits) {
    if (numOrbits > MAX_ORBITS) { return; }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    for(int i = 0; i < 360; i++) {
        glVertex3f(radius*cos(i*PI/180.0), radius*sin(i*PI/180.0), 0.0);
    }
    glEnd();
    drawOrbit(radius + planets[numOrbits].distanceFromSun/SOLAR_SYSTEM_SCALE, numOrbits+1);
}

/* Draw a string */
void drawString(const char* str, GLfloat x, GLfloat y) {
    glRasterPos2f(x, y);
    const char* c;
    for (c = str; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}

/* Display function */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    /* Camera Position */
    gluLookAt(0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    /* Sun */
    drawPlanet(SUN_RADIUS, planets[0].color, planets[0].x, planets[0].y, planets[0].z);

    /* Planets */
    for (int i = 1; i < NUMBER_OF_PLANETS; i++) {
        drawOrbit(planets[i].distanceFromSun/SOLAR_SYSTEM_SCALE, 0);
        drawPlanet(planets[i].radius, planets[i].color, planets[i].x, planets[i].y, planets[i].z);
    }

    /* Draw Planet Names */
    drawString("Sun", planets[0].x - SUN_RADIUS*2, planets[0].y - SUN_RADIUS*2);
    drawString("Mercury", planets[1].x - 1.5*planets[1].radius, planets[1].y - 1.5*planets[1].radius);
    drawString("Venus", planets[2].x - 1.5*planets[2].radius, planets[2].y - 1.5*planets[2].radius);
    drawString("Earth", planets[3].x - 1.5*planets[3].radius, planets[3].y - 1.5*planets[3].radius);
    drawString("Mars", planets[4].x - 1.5*planets[4].radius, planets[4].y - 1.5*planets[4].radius);
    drawString("Jupiter", planets[5].x - 1.5*planets[5].radius, planets[5].y - 1.5*planets[5].radius);
    drawString("Saturn", planets[6].x - 1.5*planets[6].radius, planets[6].y - 1.5*planets[6].radius);

    glutSwapBuffers();
}

/* Update the planet positions for the next frame */
void updatePlanetPositions() {
    for (int i = 1; i < NUMBER_OF_PLANETS; i++) {
        // Update angle of rotation
        planets[i].angle += (planets[i].orbitSpeed / 365.0) * 360.0 * TIMER_INTERVAL / 1000.0;
        if (planets[i].angle > 360.0) { planets[i].angle -= 360.0; planets[i].numOrbits++; }
        // Reset rotation angle if exceeds 360 degrees
        planets[i].rotationSpeed = (6.0 / 24.0) * 360.0 / 365.0;
        planets[i].orbitOffset = 90.0 - planets[i].axialTilt;
        GLfloat distance = planets[i].distanceFromSun/SOLAR_SYSTEM_SCALE;
        GLfloat currentAngle = planets[i].angle + planets[i].orbitOffset;
        planets[i].x = distance * cos(currentAngle * PI/180.0);
        planets[i].y = distance * sin(currentAngle * PI/180.0);
        planets[i].rotationSpeed = planets[i].rotationSpeed * TIMER_INTERVAL / 1000.0;
        glRotatef(planets[i].angle, 0.0, 0.0, 1.0);
        glTranslatef(distance * cos(planets[i].angle * PI/180.0), distance * sin(planets[i].angle * PI/180.0), 0.0);
        glRotatef(-planets[i].axialTilt, 1.0, 0.0, 0.0);
        glRotatef(planets[i].rotationSpeed, 1.0, 0.0, 0.0);
    }
}


/* Timer function */
void timer(int duration) {
    glutPostRedisplay();
    updatePlanetPositions();
    glutTimerFunc(TIMER_INTERVAL, timer, 0);
}

/* Main function */
int main(int argc, char** argv) {
    /* Initialize Planet Properties */
    Planet sun = {0.0, SUN_RADIUS, 0.0, 0.0, 0.0, {1.0, 1.0, 0.0}, 0.0, 0.0, 0.0, 0};
    Planet mercury = {57.91, 0.383, 47.87, 0.0, 0.01, {0.95, 0.36, 0.09}, 0.0, 0.0, 0.0, 0};
    Planet venus = {108.2, 0.949, 35.02, 0.0, 177.36, {0.75, 0.44, 0.13}, 0.0, 0.0, 0.0, 0};
    Planet earth = {149.6, EARTH_RADIUS, 29.78, 0.0, 23.44, {0.0, 0.0, 1.0}, 0.0, 0.0, 0.0, 0};
    Planet mars = {227.9, 0.532, 24.1, 0.0, 25.19, {0.86, 0.08, 0.24}, 0.0, 0.0, 0.0, 0};
    Planet jupiter = {778.6, 11.21, 13.06, 0.0, 3.13, {0.93, 0.64, 0.30}, 0.0, 0.0, 0.0, 0};
    Planet saturn = {1433.5, 9.45, 9.64, 0.0, 26.73, {0.7, 0.67, 0.19}, 0.0, 0.0, 0.0, 0};

    /* Add planets to array */
    planets[0] = sun;
    planets[1] = mercury;
    planets[2] = venus;
    planets[3] = earth;
    planets[4] = mars;
    planets[5] = jupiter;
    planets[6] = saturn;

    /* Initialize the window */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Solar System");

    /* Register callbacks */
    glutDisplayFunc(display);
    glutTimerFunc(TIMER_INTERVAL, timer, 0);

    /* Initialize OpenGL */
    initGL();

    /* Run the GLUT loop */
    glutMainLoop();

    return 0;
}