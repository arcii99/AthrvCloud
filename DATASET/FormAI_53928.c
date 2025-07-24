//FormAI DATASET v1.0 Category: Fractal Generation ; Style: high level of detail
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>
#define MAX 100000 
#define SIZE 3 

//function to calculate the midpoint of two points 
void midpoint(float *a, float *b, float *mid) 
{  
    mid[0] = (a[0] + b[0]) / 2.0;  
    mid[1] = (a[1] + b[1]) / 2.0;    
}  

//function to recursively calculate new points  
void sierpinski(float *a, float *b, float *c, int n) 
{  
    float *ab = (float *)malloc(SIZE * sizeof(float));  
    float *bc = (float *)malloc(SIZE * sizeof(float));  
    float *ca = (float *)malloc(SIZE * sizeof(float));  
    if(n > 0)  
    {    
        midpoint(a, b, ab);    
        midpoint(b, c, bc);    
        midpoint(c, a, ca);    
        sierpinski(a, ab, ca, n - 1);    
        sierpinski(ab, b, bc, n - 1);    
        sierpinski(ca, bc, c, n - 1);    
    }  
    else  
    {    
         //drawing the triangle    
         glBegin(GL_TRIANGLES);    
         glVertex2fv(a);    
         glVertex2fv(b);    
         glVertex2fv(c);    
         glEnd();    
    }    
    free(ab);  
    free(bc);  
    free(ca);  
} 

//function to display graphics 
void display(void) 
{  
    /* clear all pixels  */  
    glClear(GL_COLOR_BUFFER_BIT);  

    /* set color for lines  */  
    glColor3f(1.0, 1.0, 1.0);  

    /* draw triangle */  
    float  vertices[3][2] = { {-0.5, 0.0}, {0.5, 0.0}, 
                                 {0.0, sqrt(3.0) / 2.0} };  
    sierpinski(vertices[0], vertices[1], vertices[2], 6);  
    glFlush();  
} 

//main function 
int main(int argc, char **argv) 
{  
    /* initialize mode, open a window */  
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(500, 500);  
    glutCreateWindow("Sierpinski Triangle");  
    glClearColor(0.0, 0.0, 0.0, 0.0);  
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();  
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);  

    /* call graphics library functions  */  
    glutDisplayFunc(display);  
    glutMainLoop();  

    return 0;  
}