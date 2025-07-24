//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: expert-level
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

#define sun_radius 1.009

GLfloat sun=1;
GLfloat mercury=3;
GLfloat venus=4;
GLfloat earth=5;
GLfloat mars=6;
GLfloat jupiter=7;
GLfloat saturn=8;
GLfloat uranus=9;
GLfloat neptune=10;
GLfloat pluto=11;

GLfloat year=0,day=0;

void init(void)
{
glClearColor(0.0,0.0,0.0,0.0);
glShadeModel(GL_FLAT);
}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,1.0,0.0);
glPushMatrix();
glRotatef(sun,0.0,1.0,0.0);
glTranslatef(0.0,0.0,0.0);
glutWireSphere(sun_radius,20,16);
glPopMatrix();
glColor3f(0.4,0.7,0.9);
glPushMatrix();
glRotatef(mercury,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-2.0);
glutWireSphere(0.05,10,8);
glPopMatrix();
glColor3f(0.5,0.5,0.5);
glPushMatrix();
glRotatef(earth,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-2.5);
glutWireSphere(0.1,12,10);
glPopMatrix();
glColor3f(0.7,0.3,0.0);
glPushMatrix();
glRotatef(mars,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-3.0);
glutWireSphere(0.06,10,8);
glPopMatrix();
glColor3f(0.9,0.0,0.3);
glPushMatrix();
glRotatef(jupiter,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-3.5);
glutWireSphere(0.15,15,12);
glPopMatrix();
glColor3f(0.3,0.2,0.1);
glPushMatrix();
glRotatef(saturn,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-4.0);
glutWireSphere(0.12,12,10);
glPopMatrix();
glColor3f(0.2,0.6,0.9);
glPushMatrix();
glRotatef(uranus,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-4.5);
glutWireSphere(0.09,9,8);
glPopMatrix();
glColor3f(0.1,0.3,0.5);
glPushMatrix();
glRotatef(neptune,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-5.0);
glutWireSphere(0.08,8,6);
glPopMatrix();
glColor3f(0.3,0.2,0.1);
glPushMatrix();
glRotatef(pluto,0.0,1.0,0.0);
glTranslatef(0.0,0.0,-5.5);
glutWireSphere(0.06,6,4);
glPopMatrix();
glutSwapBuffers();
}

void reshape(int w,int h)
{
glViewport(0,0,(GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1.0,20.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0,0.0,-10.0);
}

void timer(int)
{
glutPostRedisplay();
glutTimerFunc(1000/60,timer,0);

day=(day+0.05);
year=(year+0.01);
sun=(sun+0.005);
mercury=(mercury+2.5);
venus=(venus+1.8);
earth=(earth+1.5);
mars=(mars+1.2);
jupiter=(jupiter+0.8);
saturn=(saturn+0.5);
uranus=(uranus+0.2);
neptune=(neptune+0.1);
pluto=(pluto+0.05);

if(day==360) day=0;
if(year==360) year=0;
if(sun==360) sun=0;
if(mercury==360) mercury=0;
if(venus==360) venus=0;
if(earth==360) earth=0;
if(mars==360) mars=0;
if(jupiter==360) jupiter=0;
if(saturn==360) saturn=0;
if(uranus==360) uranus=0;
if(neptune==360) neptune=0;
if(pluto==360) pluto=0;
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(600,600);
glutInitWindowPosition(100,100);
glutCreateWindow("Solar System");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glEnable(GL_DEPTH_TEST);
glutTimerFunc(0,timer,0);
glutMainLoop();
return 0;
}