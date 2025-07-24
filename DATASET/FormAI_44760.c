//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int width, height, i, j;
    
    printf("Please enter the width of the image: ");
    scanf("%d", &width);
    printf("Please enter the height of the image: ");
    scanf("%d", &height);
    
    char pixels[height][width];
    
    srand(time(0));
    
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            int color = rand() % 2;
            if(color == 0) {
                pixels[i][j] = '0';
            } else {
                pixels[i][j] = '1';
            }
        }
    }
    
    printf("Here is the generated image:\n");
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
}