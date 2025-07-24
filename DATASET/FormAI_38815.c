//FormAI DATASET v1.0 Category: Digital signal processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define N 100

/*
 * This program uses digital signal processing techniques to play a unique sound.
 * The sound is a combination of two sine waves of different frequencies. 
 * One sine wave is high-pitched, while the other is low-pitched. 
 * The two waves are played together, creating a complex sound that is pleasing to the ear.
 */

int main()
{
    int i;
    double freq1 = 440.0; /* Frequency of the first sine wave */
    double freq2 = 660.0; /* Frequency of the second sine wave */
    double wav[N]; /* Array to hold the wave samples */
    double maxamp = 0.999969482421875; /* Maximum amplitude allowed by the sound card */
    double pi = 3.14159265358979323846;
    double sample_rate = 44100.0; /* The sample rate used by the sound card */

    /* Calculate the samples for the first wave */
    for (i = 0; i < N; i++) {
        wav[i] = maxamp * sin(2 * pi * freq1 * i / sample_rate);
    }

    /* Add the second wave to the first wave */
    for (i = 0; i < N; i++) {
        wav[i] += maxamp * sin(2 * pi * freq2 * i / sample_rate);
    }

    /* Output the wave samples */
    for (i = 0; i < N; i++) {
        printf("%f\n", wav[i]);
    }

    return 0;
}