//FormAI DATASET v1.0 Category: Fractal Generation ; Style: creative
#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <complex.h>  
#define WIDTH 80  
#define HEIGHT 24  
  
int main()  
{  
    double complex z, c;  
    int i, j, k;  
    char a[WIDTH][HEIGHT];  
    double x1 = -WIDTH/HEIGHT*1.5;  
    double x2 = WIDTH/HEIGHT*1.5;  
    double y1 = -1.5;  
    double y2 = 1.5;  
    double dx = (x2 - x1) / (WIDTH - 1);  
    double dy = (y2 - y1) / (HEIGHT - 1);  
    
    //generate fractal  
    for (i = 0; i < HEIGHT; i++)  
    {  
        for (j = 0; j < WIDTH; j++)  
        {  
            z = 0;  
            c = x1 + j * dx + (y1 + i * dy) * I;  
            k = 0;  
            while (cabs(z) < 2 && k++ < 100)  
                z = cpow(z, 2) + c;  
            a[j][i] = k % 10 + '0';  
        }  
    }  
    
    //print fractal  
    for (i = 0; i < HEIGHT; i++)  
    {  
        for (j = 0; j < WIDTH; j++)  
        {  
            printf("%c", a[j][i]);  
        }  
        printf("\n");  
    }  
    
    return 0;  
}