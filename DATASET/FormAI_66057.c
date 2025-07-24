//FormAI DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generateFractal(int x, int y, int length, int depth, char **fractal) {
    if(depth == 0) {
        fractal[x][y] = '*';
        return;
    }
    int l = length/(pow(3, depth - 1));
    for(int i=x; i<x+length; i++) {
        for(int j=y; j<y+length; j++) {
            if(i >= x+l && i < x+2*l && j >= y+l && j < y+2*l) {
                continue;
            }
            generateFractal(i,j,l,depth-1,fractal);
        }
    }
}

int main() {
    int depth;
    printf("Enter the depth of the fractal: ");
    scanf("%d", &depth);
    int length = pow(3,depth-1);
    char **fractal = (char**) malloc(length*sizeof(char*));
    for(int i=0; i<length; i++) {
        fractal[i] = (char*) malloc(length*sizeof(char));
    }
    for(int i=0; i<length; i++) {
        for(int j=0; j<length; j++) {
            fractal[i][j] = ' ';
        }
    }
    generateFractal(0,0,length,depth,fractal);
    printf("The generated fractal is shown below:\n");
    for(int i=0; i<length; i++) {
        for(int j=0; j<length; j++) {
            printf("%c", fractal[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<length; i++) {
        free(fractal[i]);
    }
    free(fractal);
    return 0;
}