//FormAI DATASET v1.0 Category: Digital signal processing ; Style: light-weight
#include <stdio.h>

// function to perform three-point moving average filter on input data
void moving_avg(float* input, float* output, int size) {
    for (int i=1; i<size-1; i++) {
        output[i] = (input[i-1] + input[i] + input[i+1]) / 3.0;
    }
}

int main() {
    // input data
    float input_data[] = {1.5, 2.4, 3.6, 2.8, 4.9, 1.2, 2.7, 3.8};

    int size = sizeof(input_data) / sizeof(input_data[0]);

    // output data
    float output_data[size];

    // perform moving average filter
    moving_avg(input_data, output_data, size);

    // print input and output data
    printf("Input data:\n");
    for (int i=0; i<size; i++) {
        printf("%.1f ", input_data[i]);
    }

    printf("\nOutput data:\n");
    for (int i=0; i<size; i++) {
        printf("%.1f ", output_data[i]);
    }
    printf("\n");

    return 0;
}