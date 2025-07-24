//FormAI DATASET v1.0 Category: Data mining ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;
    float mean;
    int minimum = data[0];
    int maximum = data[0];

    // calculate sum of all elements
    for (int i = 0; i < 10; i++) {
        sum += data[i];
    }

    // calculate mean
    mean = (float)sum / 10;

    // find minimum and maximum
    for (int i = 0; i < 10; i++) {
        if (data[i] < minimum) {
            minimum = data[i];
        }
        if (data[i] > maximum) {
            maximum = data[i];
        }
    }

    printf("Sum = %d\n", sum);
    printf("Mean = %0.2f\n", mean);
    printf("Minimum = %d\n", minimum);
    printf("Maximum = %d\n", maximum);

    return 0;
}