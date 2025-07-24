//FormAI DATASET v1.0 Category: Digital signal processing ; Style: visionary
#include <stdio.h>

void visionFilter(float* input, float* output, int length) {
    // Our visionary filter implementation
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            output[i] = input[i] * 2.0;
        } else {
            output[i] = input[i] * -1.0;
        }
    }
}

int main() {
    // Example usage of our visionary filter
    float input[] = {0.5, 1.0, 1.5, 2.0, 2.5};
    float output[5];
    int length = 5;

    visionFilter(input, output, length);

    printf("Input: ");
    for (int i = 0; i < length; i++) {
        printf("%f ", input[i]);
    }

    printf("\nOutput: ");
    for (int i = 0; i < length; i++) {
        printf("%f ", output[i]);
    }

    return 0;
}