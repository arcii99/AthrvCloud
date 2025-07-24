//FormAI DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>

// function to generate fractal
void generateFractal(int x, int y, int level, char fractal[][200]) {
    if(level == 1) {
        fractal[x][y] = '*'; // set center character
        return;
    }
    int step = 1 << (level-2); // calculate step size for current level
    generateFractal(x, y, level-1, fractal); // generate fractal for inner level
    generateFractal(x-step, y-step, level-1, fractal); // generate fractal for top-left quadrant
    generateFractal(x-step, y+step, level-1, fractal); // generate fractal for bottom-left quadrant
    generateFractal(x+step, y-step, level-1, fractal); // generate fractal for top-right quadrant
    generateFractal(x+step, y+step, level-1, fractal); // generate fractal for bottom-right quadrant
}

int main() {
    int level;
    printf("Enter level of fractal: ");
    scanf("%d", &level);
    char fractal[200][200] = {0}; // initialize array with 0's
    generateFractal(100, 100, level, fractal); // generate fractal
    for(int i=0; i<200; i++) {
        for(int j=0; j<200; j++) {
            printf("%c", fractal[i][j] == '*' ? fractal[i][j] : ' '); // print fractal
        }
        printf("\n");
    }
    return 0;
}