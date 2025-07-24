//FormAI DATASET v1.0 Category: Audio processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void applyDelay(float* input, float* output, int length, int delayTimeMs, float decay) {
    int delayTimeInSamples = (int)(delayTimeMs * 44.1);
    int outIdx = 0;

    for(int i = 0; i < length; i++) {
        if(i >= delayTimeInSamples) {
            output[i] += input[i] + output[i - delayTimeInSamples] * decay;
        } else {
            output[i] += input[i];
        }
        
        // Clipping
        if(output[i] > 1.0f) {
            output[i] = 1.0f;
        } else if(output[i] < -1.0f) {
            output[i] = -1.0f;
        }
    }
}

void applyLowPassFilter(float* input, float* output, int length, float cutoffFreq) {
    float RC = 1.0f / (2.0f * PI * cutoffFreq);
    float dt = 1.0f / 44100.0f;
    float alpha = dt / (RC + dt);

    output[0] = input[0];

    for(int i = 1; i < length; i++) {
        output[i] = (1.0f - alpha) * output[i - 1] + alpha * input[i];

        // Clipping
        if(output[i] > 1.0f) {
            output[i] = 1.0f;
        } else if(output[i] < -1.0f) {
            output[i] = -1.0f;
        }
    }
}

int main() {
    // Excitedly processing some audio!
    printf("Let's get started!\n");

    // Create some test audio
    float testInput[44100];
    float testOutput[44100];

    for(int i = 0; i < 44100; i++) {
        testInput[i] = sinf(2.0f * PI * 1000.0f * ((float)i / 44100.0f));
    }

    // Apply some delay
    applyDelay(testInput, testOutput, 44100, 500, 0.5f);
    printf("Applied delay with decay of 0.5!\n");

    // Apply low pass filter
    applyLowPassFilter(testOutput, testOutput, 44100, 3000.0f);
    printf("Applied low pass filter with cutoff frequency of 3000 Hz!\n");

    // Write test output to file
    FILE* outputFile = fopen("processed_audio.raw", "wb");

    if(outputFile) {
        fwrite(testOutput, sizeof(float), 44100, outputFile);
        printf("Wrote processed audio to file!\n");
        fclose(outputFile);
    } else {
        printf("Error opening file to write processed audio!\n");
    }

    // Excitedly end processing
    printf("All done! Let's go process some more audio!\n");

    return 0;
}