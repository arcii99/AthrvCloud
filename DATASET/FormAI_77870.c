//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define DEG_TO_RAD 0.017453293

GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
GLfloat light_position[] = {0.0, 0.0, 0.0, 1.0};
GLfloat mat_specular[] = {0.7, 0.7, 0.7, 1.0};
GLfloat mat_shininess[] = {100.0};

static GLfloat year = 0, day = 0;
static GLint yearSpeed = 1, daySpeed = 5;

static void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    // Draw Sun
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glTranslatef(0.0f, 0.0f, 0.0f);
    glutSolidSphere(2.0, 20, 16);

    // Draw Earth
    glRotatef(year, 0.0, 1.0, 0.0);
    glTranslatef(6.0, 0.0, 0.0);
    glRotatef(day, 0.0, 1.0, 0.0);
    glutSolidSphere(0.4, 10, 8);

    // Draw Moon
    glTranslatef(1.0, 0.0, 0.0);
    glutSolidSphere(0.1, 5, 4);

    glPopMatrix();
    glutSwapBuffers();
}

static void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

static void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
      case 'd':
         daySpeed += 1;
         break;
      case 'D':
         daySpeed -= 1;
         break;
      case 'y':
         yearSpeed += 1;
         break;
      case 'Y':
         yearSpeed -= 1;
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

static void idle(void)
{
    year += yearSpeed;

    if (daySpeed != 0)
    {
        day += (360/((float)daySpeed))/365;
        if (day > 360)
        {
            day = 0;
        }
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Solar System");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}