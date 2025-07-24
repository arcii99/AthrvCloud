//FormAI DATASET v1.0 Category: Fractal Generation ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h> /* OpenGL Utility Toolkit headers */

int n;  /* Number of iterations */
double scale; /* Scaling factor */
double angle; /* Angle of rotation */
GLfloat vertices[3][3]={{-0.5,-0.5,0.5},{0.5,-0.5,0.5},{0,0.5,0}}; /* Initial triangle */

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); /* Clear color buffer */
    glBegin(GL_TRIANGLES); /* Start drawing triangle */
        fractal(vertices[0],vertices[1],vertices[2],n); /* Call fractal function */
    glEnd();
    glFlush(); /* Flush the buffer */
}

void fractal(GLfloat *a,GLfloat *b,GLfloat *c,int k)
{
    GLfloat v[3][3]; /* A new triangle to be created */
    int j;
    if(k>0) /* Iterate till k becomes 0*/
    {
        for(j=0;j<3;j++)
        {
            v[j][0]=(a[j]+b[j])/2; /* Find midpoints */
            v[j][1]=(a[j]+c[j])/2;
            v[j][2]=(b[j]+c[j])/2;
        }

        /* Recursively call fractal to form more triangles */
        fractal(a,v[0],v[1],k-1);
        fractal(v[0],b,v[2],k-1);
        fractal(v[1],v[2],c,k-1);
        fractal(v[0],v[1],v[2],k-1);
    }
    else
    {
        glVertex3fv(a); /* Draw triangle when k is 0 */
        glVertex3fv(b);
        glVertex3fv(c);
    }
}

int main(int argc,char **argv)
{
    printf("\nEnter number of iterations: ");
    scanf("%d",&n);
    printf("\nEnter scale factor: ");
    scanf("%lf",&scale);
    printf("\nEnter angle of rotation: ");
    scanf("%lf",&angle);
    glutInit(&argc,argv); /* Initialize GLUT library */
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); /* Use single buffer mode and RGB color mode */
    glutInitWindowSize(500,500); /* Specify window size as 500x500 */
    glutCreateWindow("Fractal Generation"); /* Create a window */
    glClearColor(0,0,0,1); /* Set background color to black */
    glMatrixMode(GL_PROJECTION); /* Set matrix mode to projection */
    glLoadIdentity(); /* Reset the current modelview matrix */
    gluOrtho2D(-1,1,-1,1); /* Set 2D orthographic view */
    glMatrixMode(GL_MODELVIEW); /* Set matrix mode to modelview */
    glLoadIdentity(); /* Reset the current modelview matrix */
    glRotatef(angle,0,0,1); /* Rotate the object */
    glScalef(scale,scale,scale); /* Scale the object */
    glutDisplayFunc(display); /* Register the display callback */
    glutMainLoop(); /* Enter the event processing loop */
    return 0;
}