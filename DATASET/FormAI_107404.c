//FormAI DATASET v1.0 Category: Audio processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLERATE 44100
#define CHANL 2
#define BUFFERSIZE 1024

float waveform(float frequency, float time) {
    return sin(frequency * 2 * M_PI * time);
}

void processAudio(float *inputBuffer, float *outputBuffer, int bufferSize) {
    float time = 0;
    for(int i = 0; i < bufferSize; i++) {
        outputBuffer[i*2] = waveform(440, time); // left channel
        outputBuffer[i*2+1] = waveform(554.37, time); // right channel
        time += 1.0 / SAMPLERATE;
    }
}

int main() {
    float inputBuffer[BUFFERSIZE * CHANL];
    float outputBuffer[BUFFERSIZE * CHANL];

    processAudio(inputBuffer, outputBuffer, BUFFERSIZE);

    for(int i = 0; i < BUFFERSIZE * CHANL; i++) {
        printf("%f ", outputBuffer[i]);
    }

    return 0;
}