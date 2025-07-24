//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random seed
    
    int width, height, color_num;
    
    printf("Enter width of image: ");
    scanf("%d", &width);
    printf("Enter height of image: ");
    scanf("%d", &height);
    printf("Enter number of colors (1-16): ");
    scanf("%d", &color_num);
    
    //check for valid input
    if (width <= 0 || height <= 0 || color_num <= 0 || color_num > 16) {
        printf("Invalid input.");
        return 1;
    }
    
    printf("P3\n"); //P3 specifies it is a RGB color image
    printf("%d %d\n", width, height); //dimensions of image
    printf("255\n"); //maximum color value
    
    int i, j, r, g, b;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            //generate random RGB values based on color_num
            r = rand() % (256/color_num) * color_num;
            g = rand() % (256/color_num) * color_num;
            b = rand() % (256/color_num) * color_num;
            //print RGB values for each pixel
            printf("%d %d %d ", r, g, b);
        }
        printf("\n");
    }
    
    return 0;
}