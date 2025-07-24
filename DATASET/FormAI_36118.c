//FormAI DATASET v1.0 Category: Audio processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512

float buffer[BUFFER_SIZE];
int write_pos = 0;

void process_buffer(float* buffer, int buffer_size) {
    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = sin((write_pos + i) * 440.0f * 2.0f * M_PI / SAMPLE_RATE);
    }

    write_pos += buffer_size;
}

int main() {
    printf("Initializing audio processing...\n");

    while (1) {
        process_buffer(buffer, BUFFER_SIZE);
        fwrite(buffer, sizeof(float), BUFFER_SIZE, stdout);
    }

    return 0;
}