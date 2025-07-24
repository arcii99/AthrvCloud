//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 50

// This function generates a random color for each pixel in the image 
int generate_color(){
    return rand() % 256;
}

int main()
{
    // We seed the random function with the current time 
    srand(time(0));
    
    // We create a 2D array containing the colors of each pixel 
    int pixels[WIDTH][HEIGHT];
    
    // We generate a random color for each pixel 
    for(int i=0; i<WIDTH; i++){
        for(int j=0; j<HEIGHT; j++){
            pixels[i][j] = generate_color();
        }
    }
    
    // We print the image using ASCII characters 
    for(int i=0; i<WIDTH; i++){
        for(int j=0; j<HEIGHT; j++){
            if(pixels[i][j] < 128){
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    
    return 0;
}