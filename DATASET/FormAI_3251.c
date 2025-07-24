//FormAI DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 100

typedef struct {
    int x;
    int y;
} data_point;

int main() {
    srand((unsigned) time(NULL));

    data_point data[DATA_SIZE];

    int i;
    for (i = 0; i < DATA_SIZE; i++) {
        data[i].x = rand() % 100;
        data[i].y = rand() % 100;
    }

    int dist = 0;
    for (i = 0; i < DATA_SIZE; i++) {
        dist += data[i].x * data[i].y;
    }

    int mean_dist = dist / DATA_SIZE;

    printf("Mean distance of the data points: %d\n", mean_dist);

    return 0;
}