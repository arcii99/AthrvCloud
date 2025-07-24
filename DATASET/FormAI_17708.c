//FormAI DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator

    // generate an array of random numbers
    int data[1000];
    for (int i = 0; i < 1000; i++) {
        data[i] = rand() % 100;
    }

    // calculate the average of the array
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        sum += data[i];
    }
    float average = (float) sum / 1000;

    // find the closest number to the average in the array
    int closest = data[0];
    for (int i = 1; i < 1000; i++) {
        if (abs(data[i] - average) < abs(closest - average)) {
            closest = data[i];
        }
    }

    // print out the results
    printf("The random data array is: [");
    for (int i = 0; i < 1000; i++) {
        printf("%d", data[i]);
        if (i < 999) {
            printf(", ");
        }
    }
    printf("]\n");
    printf("The average of the array is: %.2f\n", average);
    printf("The closest number to the average is: %d\n", closest);

    return 0;
}