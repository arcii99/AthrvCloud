//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers within a certain range
int random_number(int min, int max){
    return (rand() % max) + min;
}

// Function to generate a pixel art
void generate_pixel_art(int height, int width){

    // Array declaration for storing pixel values
    int pixels[height][width];

    // Seed for random number generation
    srand(time(NULL));

    // Generating random pixel values
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            pixels[i][j] = random_number(0, 255);
        }
    }

    // Displaying the pixel art
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            printf("%d ",pixels[i][j]);
        }
        printf("\n");
    }
}

// Driver function
int main(){
    int height, width;

    printf("Enter height of pixel art: ");
    scanf("%d",&height);

    printf("Enter width of pixel art: ");
    scanf("%d",&width);

    generate_pixel_art(height, width);

    return 0;
}