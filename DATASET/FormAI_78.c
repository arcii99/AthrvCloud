//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: intelligent
#include <stdio.h>

int main() {
    int width, height;
    printf("Enter width and height of image: ");
    scanf("%d %d", &width, &height);
    int art[height][width];
    //initialize all pixels to black
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            art[i][j] = 0;
        }
    }
    //draw the pixel art
    art[1][4] = 1;
    art[1][5] = 1;
    art[2][3] = 1;
    art[2][6] = 1;
    art[3][2] = 1;
    art[3][7] = 1;
    art[4][2] = 1;
    art[4][7] = 1;
    art[5][3] = 1;
    art[5][6] = 1;
    art[6][4] = 1;
    art[6][5] = 1;
    //print the pixel art
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(art[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}