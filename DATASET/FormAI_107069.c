//FormAI DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <math.h>

int main()
{
    printf("Welcome to the Audio Processing Puzzle!\n");

    int sampleRate = 44100;
    int duration = 5;
    int numSamples = sampleRate * duration;
    float maxAmplitude = 0.5;

    float signal[numSamples];
    float filteredSignal[numSamples];

    // Generate a sine wave with frequency of 1000 Hz
    for (int i = 0; i < numSamples; i++)
    {
        float time = (float)i / sampleRate;
        signal[i] = sin(2 * M_PI * 1000 * time);
    }

    // Apply a simple high-pass filter
    float RC = 1.0 / (2 * M_PI * 100); // cutoff frequency of 100 Hz
    float alpha = RC / (RC + 1.0 / sampleRate);
    float prevOut = 0.0;

    for (int i = 0; i < numSamples; i++)
    {
        filteredSignal[i] = alpha * (prevOut + signal[i] - signal[i-1]);
        prevOut = filteredSignal[i];
    }

    // Normalize the signal
    float maxAbsValue = 0.0;
    for (int i = 0; i < numSamples; i++)
    {
        if (fabs(filteredSignal[i]) > maxAbsValue)
        {
            maxAbsValue = fabs(filteredSignal[i]);
        }
    }
    float scaleFactor = maxAmplitude / maxAbsValue;
    for (int i = 0; i < numSamples; i++)
    {
        filteredSignal[i] *= scaleFactor;
    }

    // Output the results
    printf("Generated a sine wave of 1000 Hz for %d seconds at a sample rate of %d.\n", duration, sampleRate);
    printf("Applied a high-pass filter with a cutoff frequency of 100 Hz.\n");
    printf("Normalized the signal to the maximum amplitude of %f.\n", maxAmplitude);

    for (int i = 0; i < numSamples; i++)
    {
        printf("%f\n", filteredSignal[i]);
    }

    return 0;
}