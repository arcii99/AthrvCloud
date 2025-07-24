//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: intelligent
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.14159265358979323846

// Declare global variables
GLfloat angle = 0.0f;
GLfloat distance = 20.0f;
GLfloat angleSun = 0.0f;
GLfloat angleEarth = 0.0f;
GLfloat angleMoon = 0.0f;

// Declare functions
void initGL();
void display();
void keyboard(unsigned char key, int x, int y);
void timer(int id);

// Main function
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Solar System Simulation");
  initGL();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(0, timer, 0);
  glutMainLoop();
  return 0;
}

// Initialize OpenGL
void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// Draw the planets and sun
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Draw sun
  glPushMatrix();
  glRotatef(angleSun, 0.0f, 1.0f, 0.0f);
  glColor3f(1.0f, 1.0f, 0.0f);
  glutSolidSphere(3.0f, 50, 50);
  glPopMatrix();

  // Draw earth
  glPushMatrix();
  glRotatef(angleEarth, 0.0f, 1.0f, 0.0f);
  glTranslatef(distance, 0.0f, 0.0f);
  glColor3f(0.0f, 0.0f, 1.0f);
  glutSolidSphere(1.0f, 50, 50);
  
  // Draw moon
  glPushMatrix();
  glRotatef(angleMoon, 0.0f, 1.0f, 0.0f);
  glTranslatef(2.0f, 0.0f, 0.0f);
  glColor3f(0.5f, 0.5f, 0.5f);
  glutSolidSphere(0.5f, 50, 50);
  glPopMatrix();

  glPopMatrix();

  glutSwapBuffers();
}

// Handle keyboard input
void keyboard(unsigned char key, int x, int y) {
  switch(key) {
    case 'a':
      angleSun += 2.0f;
      break;
    case 'd':
      angleSun -= 2.0f;
      break;
    case 'w':
      angleEarth += 2.0f;
      break;
    case 's':
      angleEarth -= 2.0f;
      break;
    case 'q':
      angleMoon += 2.0f;
      break;
    case 'e':
      angleMoon -= 2.0f;
      break;
    case '+':
      distance -= 1.0f;
      break;
    case '-':
      distance += 1.0f;
      break;
    case 'x':
      exit(0);
      break;
  }
  glutPostRedisplay();
}

// Update position of planets and moon
void timer(int id) {
  angle += 0.2f;
  angleEarth -= 0.5f;
  angleMoon -= 1.0f;
  glutPostRedisplay();
  glutTimerFunc(10, timer, 0);
}