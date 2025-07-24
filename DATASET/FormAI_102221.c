//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate random number within given range
int generateRandom(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    int dim; //size of canvas
    printf("Enter dimension of canvas: ");
    scanf("%d", &dim);
    printf("\n");

    int pixels[dim][dim]; //2D array to store pixel values
    srand(time(NULL)); //seed for random number generation

    printf("Generated pixel art:\n");
    for(int i=0; i<dim; i++) {
        for(int j=0; j<dim; j++) {
            pixels[i][j] = generateRandom(0, 1); //generate random pixel value (0 or 1)
            if(pixels[i][j] == 1) { //if pixel value is 1, print a block character
                printf("█ ");
            }
            else { //if pixel value is 0, print a space character
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}