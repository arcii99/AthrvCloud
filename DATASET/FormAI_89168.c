//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

int main(void) {
    int pixel[HEIGHT][WIDTH];
    srand(time(NULL));
    
    // generate random pixel values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixel[i][j] = rand() % 5; // generate values from 0 to 4
        }
    }
    
    // print the pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            switch(pixel[i][j]) {
                case 0:
                    printf("~ "); // water pixel
                    break;
                case 1:
                    printf("O "); // island pixel
                    break;
                case 2:
                    printf("* "); // star pixel
                    break;
                case 3:
                    printf("- "); // boat pixel
                    break;
                case 4:
                    printf("# "); // rock pixel
                    break;
                default:
                    printf("? "); // error pixel
                    break;
            }
        }
        printf("\n");
    }
    
    return 0;
}