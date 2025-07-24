//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    // A Fractal tale of Romeo and Juliet
    int depth;
    printf("Enter the depth of the fractal: ");
    scanf("%d", &depth);
    int size = pow(2,depth);
    char fractal[size][size];
    // Initialize the fractal with spaces
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            fractal[i][j] = ' ';
        }
    }
    // Draw a line for Romeo
    int x = size/2, y = 0;
    fractal[y][x] = '/';
    for(int i=0; i<depth; i++){
        int dy = pow(2,i);
        int dx = dy*2;
        // Draw lines for Juliet
        for(int j=0; j<pow(2,i); j++){
            x -= dx;
            y += dy;
            fractal[y][x] = '/';
            x += dx;
            fractal[y][x] = '\\';
            x += dx;
            fractal[y][x] = '/';
        }
        // Draw lines for Romeo
        for(int j=0; j<pow(2,i); j++){
            x -= dx;
            y -= dy;
            fractal[y][x] = '\\';
            x -= dx;
            fractal[y][x] = '/';
            x += dx;
            fractal[y][x] = '\\';
        }
    }
    // Print the fractal
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%c", fractal[i][j]);
        }
        printf("\n");
    }
    return 0;
}