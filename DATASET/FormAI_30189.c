//FormAI DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLING_RATE 16000
#define BUFFER_SIZE 1024

int main() {
    float buffer[BUFFER_SIZE];
    int i, n;

    // Sample input audio (208 Hz sine wave)
    for (i=0; i<BUFFER_SIZE; i++) {
        buffer[i] = sin(2 * M_PI * 208 * i / SAMPLING_RATE);
    }

    // Low-pass filter the audio
    float a[3] = { 1, -1.1248945, 0.5095254495 };
    float b[3] = { 0.017288325260637187, 0.034576650521274374, 0.017288325260637187 };
    for (n=2; n<BUFFER_SIZE; n++) {
        buffer[n] = b[0]*buffer[n] + b[1]*buffer[n-1] + b[2]*buffer[n-2]
                  - a[1]*buffer[n-1] - a[2]*buffer[n-2];
    }

    // Amplify the audio
    float gain = 10;
    for (i=0; i<BUFFER_SIZE; i++) {
        buffer[i] *= gain;
    }

    // Write the audio to a file
    FILE *file = fopen("output.pcm", "wb");
    for (i=0; i<BUFFER_SIZE; i++) {
        short val = buffer[i] * 32767;
        fwrite(&val, sizeof(short), 1, file);
    }
    fclose(file);

    return 0;
}