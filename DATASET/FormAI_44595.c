//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define SEED 1024

typedef struct {
    int data[ROWS][COLS];
    int watermark[ROWS][COLS];
} Image;

void embedWatermark(Image *image) {
    srand(SEED);
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int randNum = rand() % 2;
            if(randNum == 1) {
                image->data[i][j]++;
            }
            image->watermark[i][j] = randNum;   
        }
    }
}

int retrieveWatermark(Image *image) {
    int total = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(image->data[i][j] % 2 != 0) {
                total += image->watermark[i][j]; 
            }
        }
    }
    return total;
}

int main() {
    Image *image = malloc(sizeof(Image));
    embedWatermark(image);
    int retrieved = retrieveWatermark(image);
    printf("Retrieved watermark value: %d\n", retrieved);
    free(image);
    return 0;
}