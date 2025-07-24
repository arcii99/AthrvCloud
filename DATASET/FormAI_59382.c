//FormAI DATASET v1.0 Category: Digital signal processing ; Style: configurable
#include <stdio.h>

#define MAX_LENGTH 1000

int main() {
    // Initialize variables and arrays
    int input[MAX_LENGTH];
    int output[MAX_LENGTH];
    int filter[] = {1, -1, 0}; // Example filter coefficients
    int filter_length = 3; // Length of filter

    // Get input signal from user
    int i = 0;
    printf("Enter input signal (-999 to stop):\n");
    while (1) {
        scanf("%d", &input[i]);
        if (input[i] == -999) {
            break;
        }
        i++;
    }
    int input_length = i;

    // Apply filter to input signal
    for (i = 0; i < input_length; i++) {
        int sum = 0;
        for (int j = 0; j < filter_length; j++) {
            if (i - j >= 0) {
                sum += filter[j] * input[i - j];
            }
        }
        output[i] = sum;
    }

    // Print output signal
    printf("Output signal:\n");
    for (i = 0; i < input_length; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");

    return 0;
}