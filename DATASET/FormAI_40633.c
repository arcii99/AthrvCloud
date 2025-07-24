//FormAI DATASET v1.0 Category: Audio processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main()
{
    float freq, phase, amplitude;
    int duration, sampleRate;

    printf("Enter the frequency in Hz: ");
    scanf("%f", &freq);

    printf("Enter the phase in degrees: ");
    scanf("%f", &phase);

    printf("Enter the amplitude: ");
    scanf("%f", &amplitude);

    printf("Enter the duration in seconds: ");
    scanf("%d", &duration);

    printf("Enter the sample rate in Hz: ");
    scanf("%d", &sampleRate);

    int numSamples = duration * sampleRate;
    float *sampleData = (float *)malloc(numSamples * sizeof(float));

    int i;
    for (i = 0; i < numSamples; i++)
    {
        float t = (float)i / sampleRate;
        float theta = 2 * PI * freq * t;
        float sampleValue = amplitude * sin(theta - phase * PI / 180.0);
        sampleData[i] = sampleValue;
    }

    FILE *audioFile = fopen("audio.raw", "wb");
    fwrite(sampleData, sizeof(float), numSamples, audioFile);
    fclose(audioFile);

    free(sampleData);

    return 0;
}