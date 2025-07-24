//FormAI DATASET v1.0 Category: Fractal Generation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum iterations for fractal generation
#define MAX_ITERATIONS 5000

// Define maximum size for fractal image
#define IMAGE_SIZE 500

// Define random parameters for fractal generation
#define RANDOM_PARAMETER_1 0.6
#define RANDOM_PARAMETER_2 0.7
#define RANDOM_PARAMETER_3 0.8
#define RANDOM_PARAMETER_4 0.9

// Define variable to store fractal image
int image[IMAGE_SIZE][IMAGE_SIZE];

// Generate random number between 0 and 1
double getRandom(){
    return (double) rand() / (double) RAND_MAX;
}

// Generate paranoid fractal
void generateFractal(){
    
    // Initialize seed for random number generation
    srand(time(NULL));
    
    // Generate initial point for fractal
    double x = getRandom();
    double y = getRandom();
    
    // Iterate over pixels in image
    for(int i=0; i<IMAGE_SIZE; i++){
        for(int j=0; j<IMAGE_SIZE; j++){
            
            // Initialize iteration count for pixel
            int count = 0;
            
            // Iterate over fractal function
            while(count < MAX_ITERATIONS){
                
                // Generate random parameter for fractal function
                double p = getRandom();
                
                // Apply paranoid fractal function
                if(p < RANDOM_PARAMETER_1){
                    x = 0.4 * x + 0.1;
                    y = 0.4 * y - 0.1;
                } else if(p < RANDOM_PARAMETER_2){
                    x = -0.5 * x + 0.45;
                    y = 0.5 * y + 0.5;
                } else if(p < RANDOM_PARAMETER_3){
                    x = 0.5 * x + 0.5;
                    y = 0.5 * y - 0.45;
                } else {
                    x = -0.6 * x - 0.4;
                    y = 0.3 * y + 0.3;
                }
                
                // Check if point has escaped
                if(x*x + y*y > 4){
                    break;
                }
                
                // Increment iteration count
                count++;
            }
            
            // Store pixel value in image
            image[i][j] = count;
        }
    }
}

// Print fractal image
void printFractal(){
    
    // Iterate over pixels in image
    for(int i=0; i<IMAGE_SIZE; i++){
        for(int j=0; j<IMAGE_SIZE; j++){
            
            // Print pixel value as char
            if(image[i][j] > MAX_ITERATIONS / 2){
                printf("#");
            } else if(image[i][j] > MAX_ITERATIONS / 10){
                printf("x");
            } else if(image[i][j] > 0){
                printf(".");
            } else {
                printf(" ");
            }
        }
        
        // Print newline character after each row of image
        printf("\n");
    }
}

// Main function
int main(){
    
    // Generate paranoid fractal
    generateFractal();
    
    // Print fractal image
    printFractal();
    
    // Exit program
    return 0;
}