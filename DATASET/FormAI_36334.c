//FormAI DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define AMPLITUDE 30000
#define PI 3.14159265358979323846

void generateSineWave(int frequency, float duration, short *buffer) {
    int samples = duration * SAMPLE_RATE;
    float increment = 2.0 * PI * frequency / SAMPLE_RATE;
    float angle = 0.0;
    for(int i=0; i<samples; i++) {
        buffer[i] = (short) (AMPLITUDE * sin(angle));
        angle += increment;
    }
}

void addDelay(short *inputBuffer, short *outputBuffer, int delay) {
    for (int i=0; i<SAMPLE_RATE; i++) {
        outputBuffer[i] = (inputBuffer[i] + inputBuffer[i-delay]) / 2;
    }
}

int main() {
    short *buffer = (short *) malloc(SAMPLE_RATE * sizeof(short));
    generateSineWave(440, 2.0, buffer);
    addDelay(buffer, buffer, 0.5 * SAMPLE_RATE);
    FILE* filePointer = fopen("output.wav", "wb");
    int dataLength = SAMPLE_RATE * sizeof(short);
    fwrite(buffer, sizeof(short), dataLength, filePointer);
    fclose(filePointer);
    free(buffer);
    return 0;
}