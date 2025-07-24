//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 20 // size of the pixel art
#define MAX_COLORS 5 // maximum number of colors in the art

int main() {
    int art[SIZE][SIZE]; // matrix to hold the art
    int colors[MAX_COLORS] = {0, 1, 2, 3, 4}; // array of available colors
    int n_colors; // number of colors to be used in the art
    int i, j, k; // loop variables
    
    srand(time(0)); // initialize random number generator
    
    printf("Welcome to the C Pixel Art Generator!\n");
    printf("How many colors would you like to use? (up to %d)\n", MAX_COLORS);
    scanf("%d", &n_colors);
    
    if(n_colors > MAX_COLORS) {
        printf("Sorry, you can only use up to %d colors.\n", MAX_COLORS);
        return 0;
    }
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            art[i][j] = rand() % n_colors; // randomly assign a color to each pixel
        }
    }
    
    printf("Your art:\n");
    
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            printf("%d ", art[i][j]); // print the value of each pixel
        }
        printf("\n"); // move to the next line
    }
    
    printf("Color key:\n");
    
    for(k = 0; k < n_colors; k++) {
        printf("%d -> color %d\n", colors[k], k); // print the color key
    }
    
    return 0;
}