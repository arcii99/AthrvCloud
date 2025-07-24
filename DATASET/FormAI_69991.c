//FormAI DATASET v1.0 Category: Digital signal processing ; Style: authentic
#include <stdio.h>
#include <math.h>

#define SAMPLE_RATE     44100.0
#define FREQUENCY       440.0
#define AMPLITUDE       0.5
#define NUM_SAMPLES     88200

int main()
{
    double phase = 0.0;
    double delta = 2 * M_PI * FREQUENCY / SAMPLE_RATE;
    double sample;
    int i;

    for (i = 0; i < NUM_SAMPLES; i++)
    {
        // Generate a sine wave
        sample = AMPLITUDE * sin(phase);

        // Output the sample
        printf("%f\n", sample);

        // Update the phase
        phase += delta;

        // Wrap the phase if necessary
        if (phase > 2 * M_PI)
        {
            phase -= 2 * M_PI;
        }
    }

    return 0;
}