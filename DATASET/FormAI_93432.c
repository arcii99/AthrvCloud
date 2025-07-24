//FormAI DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void drawFractal(int iterations, double x, double y, double size, double angle);

void moveTo(double x, double y) 
{
    printf("%lf %lf moveto\n", x, y);
}

void lineTo(double x, double y) 
{
    printf("%lf %lf lineto\n", x, y);
}

double degreesToRadians(double degrees) 
{
    return degrees * M_PI / 180;
}

void drawFractal(int iterations, double x, double y, double size, double angle) 
{
    if(iterations == 0) 
    {
        return;
    }
    
    double angle1 = angle + 10;
    double angle2 = angle - 10;
    
    double x1 = x + size * cos(degreesToRadians(angle1));
    double y1 = y + size * sin(degreesToRadians(angle1));
    
    double x2 = x + size * cos(degreesToRadians(angle2));
    double y2 = y + size * sin(degreesToRadians(angle2));
    
    moveTo(x, y);
    lineTo(x1, y1);
    lineTo(x2, y2);
    lineTo(x, y);
    
    drawFractal(iterations - 1, x1, y1, size * 0.7, angle1);
    drawFractal(iterations - 1, x2, y2, size * 0.7, angle2);
}

int main() 
{
    int iterations = 5;
    double x = 200;
    double y = 200;
    double size = 100;
    double angle = 90;
    
    printf("%%!PS-Adobe-3.0\n");
    printf("%%%%BoundingBox: 0 0 500 500\n");
    
    drawFractal(iterations, x, y, size, angle);

    printf("stroke\nshowpage\n");
    return 0;
}