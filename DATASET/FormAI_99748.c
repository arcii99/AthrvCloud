//FormAI DATASET v1.0 Category: Digital signal processing ; Style: future-proof
#include <stdio.h>

#define BUFFER_SIZE 64
#define COEFFICIENTS_LENGTH 5

const float coefficients[COEFFICIENTS_LENGTH] = {1.0, 2.0, 3.0, 4.0, 5.0};

float buffer[BUFFER_SIZE];
int buffer_head = 0;

float filter(float input) {
    buffer[buffer_head] = input;
    float output = 0;
    for (int i = 0; i < COEFFICIENTS_LENGTH; ++i) {
        int buffer_index = buffer_head - i;
        if (buffer_index < 0) {
            buffer_index += BUFFER_SIZE;
        }
        output += coefficients[i] * buffer[buffer_index];
    }
    buffer_head = (buffer_head + 1) % BUFFER_SIZE;
    return output;
}

int main() {
    float input = 1.0;
    for (int i = 0; i < 10; ++i) {
        float output = filter(input);
        printf("Input: %f, output: %f\n", input, output);
        input += 1.0;
    }
    return 0;
}