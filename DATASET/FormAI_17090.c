//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Touring
#include<stdlib.h>
#include<stdio.h>

#define WIDTH 50
#define HEIGHT 25

int main(){

    int frame[HEIGHT][WIDTH];
    int colors[4] = {0, 64, 128, 255};

    srand(time(NULL));

    // Initialize frame with random colors
    for (int i=0; i<HEIGHT; i++){
        for (int j=0; j<WIDTH; j++){
            frame[i][j] = colors[rand() % 4];
        }
    }

    // Print frame in color-coded format
    for (int i=0; i<HEIGHT; i++){
        for (int j=0; j<WIDTH; j++){
            printf("\x1b[48;2;%d;%d;%dm ", frame[i][j], frame[i][j], frame[i][j]);
        }
        printf("\n");
    }

    return 0;
}