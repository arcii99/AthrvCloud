//FormAI DATASET v1.0 Category: Graph representation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80 // width of the graph
#define HEIGHT 20 // height of the graph
#define MAX_VALUE 50 // max value of data points

int main() {
    srand(time(NULL)); // initialize random seed

    // create a 2D array to store data points
    int data[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            data[i][j] = rand() % MAX_VALUE;
        }
    }

    // print the graph
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (data[i][j] > (j * MAX_VALUE) / WIDTH) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}