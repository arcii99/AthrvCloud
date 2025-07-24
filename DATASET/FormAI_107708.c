//FormAI DATASET v1.0 Category: Audio processing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265359

int main() {
    printf("Program for generating a sine wave.\n");
    printf("Enter the frequency of the sine wave in Hz: ");
    float frequency;
    scanf("%f", &frequency);
    printf("Enter the duration of the sine wave in seconds: ");
    float duration;
    scanf("%f", &duration);

    float amplitude = 0.5;
    int numSamples = SAMPLE_RATE * duration;
    int i;

    FILE *fp;
    fp = fopen("sine_wave.raw", "wb");

    short sampleValue;

    for (i = 0; i < numSamples; i++) {
        float time = (float)i / (float)SAMPLE_RATE;
        float sineValue = amplitude * sin(2 * PI * frequency * time);

        sampleValue = (short)(sineValue * 32767.0f);
        fwrite(&sampleValue, sizeof(sampleValue), 1, fp);
    }

    fclose(fp);

    printf("Sine wave file generated successfully!\n");

    return 0;
}