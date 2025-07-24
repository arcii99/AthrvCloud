//FormAI DATASET v1.0 Category: Fractal Generation ; Style: futuristic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/glut.h>

#define maxPoints   1000000
#define maxDepth    20
#define sqr(x)      ((x)*(x))
#define PI          3.14159265

float sinTable[360];
float cosTable[360];

float x[maxPoints];
float y[maxPoints];

int max_depth = maxDepth;
int num_points = 0;

float magnify = 20.0;
float rotateX = -20.0;
float rotateY = 0.0;

void calc_fractal(float cx, float cy, float size, float angle, int depth)
{
    if(depth == max_depth)
        return;

    float newsize = size / 3.0;

    float p1x = cx-size, p1y = cy-size;
    float p2x = cx+size, p2y = cy-size;
    float p3x = cx+size, p3y = cy+size;
    float p4x = cx-size, p4y = cy+size;

    // rotate fractal around z-axis
    p1x = cx + (p1x - cx)*cosTable[(int)angle] + (p1y - cy)*sinTable[(int)angle];
    p1y = cy - (p1x - cx)*sinTable[(int)angle] + (p1y - cy)*cosTable[(int)angle];
    p2x = cx + (p2x - cx)*cosTable[(int)angle] + (p2y - cy)*sinTable[(int)angle];
    p2y = cy - (p2x - cx)*sinTable[(int)angle] + (p2y - cy)*cosTable[(int)angle];
    p3x = cx + (p3x - cx)*cosTable[(int)angle] + (p3y - cy)*sinTable[(int)angle];
    p3y = cy - (p3x - cx)*sinTable[(int)angle] + (p3y - cy)*cosTable[(int)angle];
    p4x = cx + (p4x - cx)*cosTable[(int)angle] + (p4y - cy)*sinTable[(int)angle];
    p4y = cy - (p4x - cx)*sinTable[(int)angle] + (p4y - cy)*cosTable[(int)angle];

    if(depth == max_depth - 1)
    {
        x[num_points] = p1x;
        y[num_points] = p1y;
        num_points++;
    }

    calc_fractal(p1x, p1y, newsize, angle, depth+1);
    calc_fractal(p2x, p2y, newsize, angle, depth+1);
    calc_fractal(p3x, p3y, newsize, angle, depth+1);
    calc_fractal(p4x, p4y, newsize, angle, depth+1);
}

void get_color(float* r, float* g, float* b, int iter)
{
    float t = iter / (float)max_depth;

    float red = 9*(1-t)*t*t*t;
    float green = 15*(1-t)*(1-t)*t*t;
    float blue = 8.5*(1-t)*(1-t)*(1-t)*t;

    *r = red;
    *g = green;
    *b = blue;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    float curx, cury;
    int n = num_points;

    glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++)
    {
        curx = x[i];
        cury = y[i];

        glColor3ub(255, 0, 0);
        glVertex2f(curx, cury);
    }
    glEnd();

    glFlush();
}

void init(void)
{
    for(int i = 0; i < 360; i++)
    {
        cosTable[i] = cos(i*PI/180.0);
        sinTable[i] = sin(i*PI/180.0);
    }

    calc_fractal(0.0, 0.0, magnify*80, 0, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 'q')
        exit(0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Fractal Generation");

    init();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-magnify*80, magnify*80, -magnify*80, magnify*80);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}