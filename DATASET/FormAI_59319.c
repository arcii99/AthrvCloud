//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_HEIGHT 144
#define SCREEN_WIDTH 160

unsigned char screen_buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

unsigned char get_pixel_value(int x, int y, unsigned char color){
    for(int i = 0; i < 8; i++){
        if(color & 1){
            if(screen_buffer[y + i/4][x + i%4*4] == 1){
                color = 0;
            }
        }
        color = color >> 1;
    }
    return color;
}

void set_pixel(int x, int y, unsigned char color){
    color = get_pixel_value(x, y, color);
    for(int i = 0; i < 8; i++){
        if(color & 1){
            screen_buffer[y + i/4][x + i%4*4] = 1;
        }
        color = color >> 1;
    }
}

int main(){
    srand(time(NULL));
    for(int y = 0; y < SCREEN_HEIGHT; y += 8){
        for(int x = 0; x < SCREEN_WIDTH; x += 4){
            unsigned char color = rand() % 256;
            set_pixel(x, y, color);
        }
    }

    printf("P1\n");
    printf("%d %d\n", SCREEN_WIDTH, SCREEN_HEIGHT);
    for(int y = 0; y < SCREEN_HEIGHT; y++){
        for(int x = 0; x < SCREEN_WIDTH; x++){
            printf("%d ", screen_buffer[y][x]);
        }
        printf("\n");
    }

    return 0;
}