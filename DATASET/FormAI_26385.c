//FormAI DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

#define NUM_ROWS 10
#define NUM_ATTRS 5

int main() {
    int data[NUM_ROWS][NUM_ATTRS] = {{12, 33, 45, 54, 67},
                                      {5, 98, 56, 23, 12},
                                      {40, 60, 21, 78, 90},
                                      {70, 42, 33, 21, 54},
                                      {24, 53, 37, 81, 29},
                                      {60, 70, 44, 20, 12},
                                      {29, 56, 89, 12, 33},
                                      {77, 21, 55, 32, 67},
                                      {34, 49, 65, 86, 90},
                                      {54, 12, 79, 19, 33}};

    float means[NUM_ATTRS];
    for (int i = 0; i < NUM_ATTRS; i++) {
        float sum = 0;
        for (int j = 0; j < NUM_ROWS; j++) {
            sum += data[j][i];
        }
        means[i] = sum / NUM_ROWS;
    }
    for (int i = 0; i < NUM_ATTRS; i++) {
        printf("Mean of Attribute %d: %f\n", i+1, means[i]);
    }

    return 0;
}