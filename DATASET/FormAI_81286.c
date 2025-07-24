//FormAI DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100.0

int main()
{
    double frequency = 440.0; // Starting frequency
    double amplitude = 0.25; // Starting amplitude
    double duration = 2.0; // How long to play the tone for
    int numSamples = duration * SAMPLE_RATE;

    // Generate sine wave for tone
    double phaseIncrement = 2.0 * M_PI * frequency / SAMPLE_RATE;
    double phase = 0.0;

    // Open output file
    FILE* outputFile;
    outputFile = fopen("output.raw", "wb");

    // Write header to output file
    char header[44];
    fwrite(header, sizeof(header), 1, outputFile);

    // Generate and write audio data to file
    int i;
    for (i = 0; i < numSamples; i++)
    {
        // Generate sample value
        double sample = sin(phase) * amplitude;

        // Write sample to output file
        fwrite(&sample, sizeof(sample), 1, outputFile);

        // Update phase for next sample
        phase += phaseIncrement;
        if (phase > 2.0 * M_PI)
        {
            phase -= 2.0 * M_PI;
        }
    }

    // Close output file
    fclose(outputFile);

    return 0;
}