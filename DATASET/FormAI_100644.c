//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void generate_pixel_art(char pixels[HEIGHT][WIDTH]) {
    srand(time(NULL)); // seed RNG with current time
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int rand_num = rand() % 4; // generate random number from 0 to 3
            switch(rand_num) {
                case 0:
                    pixels[i][j] = ' ';
                    break;
                case 1:
                    pixels[i][j] = '.';
                    break;
                case 2:
                    pixels[i][j] = ':';
                    break;
                case 3:
                    pixels[i][j] = 'o';
                    break;
                default:
                    pixels[i][j] = ' ';
                    break;
            }
        }
    }
}

void print_pixel_art(char pixels[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixels[HEIGHT][WIDTH];
    generate_pixel_art(pixels);
    print_pixel_art(pixels);
    return 0;
}