//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<GL/glut.h>

GLfloat PI = 3.14159265358979323846;

GLfloat rot, rplanet, angle, velocity, dist;

GLfloat mercuryrad = 0.05;
GLfloat venusrad = 0.075;
GLfloat earthrad = 0.08;  //Radius of each planet in astronomical units
GLfloat marsrad = 0.07;
GLfloat jupiterrad = 0.15;
GLfloat saturnrad = 0.13;
GLfloat uranusrad = 0.1;
GLfloat neptunerad = 0.09;

GLfloat mercurydist = 0.387;  //Distance of each planet from sun in astronomical units
GLfloat venusdist = 0.723;
GLfloat earthdist = 1;
GLfloat marsdist = 1.524;
GLfloat jupiterdist = 5.2;
GLfloat saturndist =9.5;
GLfloat uranusdist = 19.18;
GLfloat neptunedist = 30.07;

GLfloat mercuryvel = 4.1477;  //Velocity of each planet
GLfloat venusvel = 1.62;
GLfloat earthvel = 1;
GLfloat marsvel = 0.5315;
GLfloat jupitervel = 0.0843;
GLfloat saturnvel = 0.0339;
GLfloat uranusvel = 0.0119;
GLfloat neptunevel = 0.0061;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2,2,-2,2);
}

void sun(void)
{
    glColor3f(1.0,1.0,0.0);
    glutWireSphere(0.15,100,100);
}

void mercury()
{
    glColor3f(1.0,0.0,0.0);
    glutWireSphere(mercuryrad,20,20);
}

void venus()
{
    glColor3f(0.0,1.0,0.0);
    glutWireSphere(venusrad,20,20);
}

void earth()
{
    glColor3f(0.0,0.0,1.0);
    glutWireSphere(earthrad,20,20);
}

void mars()
{
    glColor3f(1.0,0.0,1.0);
    glutWireSphere(marsrad,20,20);
}

void jupiter()
{
    glColor3f(0.5,0.5,0.5);
    glutWireSphere(jupiterrad,20,20);
}

void saturn()
{
    glColor3f(0.3,0.2,0.1);
    glutWireSphere(saturnrad,20,20);
}

void uranus()
{
    glColor3f(0.5,1.0,1.0);
    glutWireSphere(uranusrad,20,20);
}

void neptune()
{
    glColor3f(0.2,0.25,0.75);
    glutWireSphere(neptunerad,20,20);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    sun();

    glPushMatrix();

    angle = 0.0;
    rplanet = mercurydist;
    velocity = mercuryvel;
    dist = mercurydist;

    glRotatef(rot, 0.0, 1.0, 0.0);

    glTranslatef(rplanet, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    mercury();

    glPopMatrix();

    angle = 0.0;
    rplanet = venusdist;
    velocity = venusvel;
    dist = venusdist;

    glPushMatrix();

    glRotatef(rot, 0.0, 1.0, 0.0);

    glTranslatef(rplanet, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    venus();

    glPopMatrix();

    angle = 0.0;
    rplanet = earthdist;
    velocity = earthvel;
    dist = earthdist;

    glPushMatrix();

    glRotatef(rot,0.0,1.0,0.0);

    glTranslatef(rplanet,0.0,0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    earth();

    glPopMatrix();

    angle = 0.0;
    rplanet = marsdist;
    velocity = marsvel;
    dist = marsdist;

    glPushMatrix();

    glRotatef(rot, 0.0, 1.0, 0.0);

    glTranslatef(rplanet, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    mars();

    glPopMatrix();

    angle = 0.0;
    rplanet = jupiterdist;
    velocity = jupitervel;
    dist = jupiterdist;

    glPushMatrix();

    glRotatef(rot, 0.0, 1.0, 0.0);

    glTranslatef(rplanet, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    jupiter();

    glPopMatrix();

    angle = 0.0;
    rplanet = saturndist;
    velocity = saturnvel;
    dist = saturndist;

    glPushMatrix();

    glRotatef(rot, 0.0, 1.0, 0.0);

    glTranslatef(rplanet, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    saturn();

    glPopMatrix();

    angle = 0.0;
    rplanet = uranusdist;
    velocity = uranusvel;
    dist = uranusdist;

    glPushMatrix();

    glRotatef(rot,0.0,1.0,0.0);

    glTranslatef(rplanet,0.0,0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    uranus();

    glPopMatrix();

    angle = 0.0;
    rplanet = neptunedist;
    velocity = neptunevel;
    dist = neptunedist;

    glPushMatrix();

    glRotatef(rot, 0.0, 1.0, 0.0);

    glTranslatef(rplanet, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    neptune();

    glPopMatrix();

    rot -= velocity;

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Solar System Simulation");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}