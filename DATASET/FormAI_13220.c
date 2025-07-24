//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
/* 
  "We may say most aptly that the Analytical Engine weaves algebraical patterns just as the Jacquard-loom weaves flowers and leaves."

  — Ada Lovelace, 1843
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <GL/glut.h>

#define MAX_ITERATIONS 1000
#define WIDTH 800 // Width of the screen
#define HEIGHT 800 // Height of the screen

typedef struct complex{
    double real, imag;
} complex;

int mandelbrotSet(complex c){
    int i;
    complex z;
    z.real = z.imag = 0;
    for(i = 0; i < MAX_ITERATIONS; i++){
        double temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp;
        if(z.real * z.real + z.imag * z.imag > 2 * 2) break;
    }
    return i;
}

void displayFunction(){
    int x, y;
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(x = 0; x < WIDTH; x++){
        for(y = 0; y < HEIGHT; y++){
            complex c;
            c.real = (2.5 * x - 2 * WIDTH) / (double) WIDTH;
            c.imag = (2 * HEIGHT - 2.5 * y) / (double) HEIGHT;
            int n = mandelbrotSet(c);
            if(n != MAX_ITERATIONS){
                glColor3f((double) n / MAX_ITERATIONS, (double) n / MAX_ITERATIONS, (double) n / MAX_ITERATIONS);
                glVertex2i(x, y);
            }
        }
    }
    glEnd();
    glFlush();
}

void reshapeFunction(GLsizei w, GLsizei h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Mandelbrot Set");
    glutDisplayFunc(displayFunction);
    glutReshapeFunc(reshapeFunction);
    glutMainLoop();
    return 0;
}