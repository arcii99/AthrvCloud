//FormAI DATASET v1.0 Category: Audio processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 4096

int main() {
    int16_t buffer[BUFFER_SIZE];
    double t = 0.0;
    double frequency = 440.0;
    double amplitude = 1.0;
    double angle_increment = 2.0 * M_PI * frequency / SAMPLE_RATE;

    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = amplitude * sin(t);
        t += angle_increment;
    }

    FILE* f = fopen("output.raw", "wb");
    fwrite(buffer, sizeof(int16_t), BUFFER_SIZE, f);
    fclose(f);

    return 0;
}