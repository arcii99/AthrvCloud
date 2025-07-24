//FormAI DATASET v1.0 Category: Audio processing ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SRATE 44100 /* Sample rate in Hz */
#define DUR   5     /* Duration of sound in seconds */
#define FREQ  440   /* Frequency of sound in Hz */

/* Function to generate an audio wave given frequency and duration */
void generate_wave(double freq, double duration, short *buffer, int buffer_size)
{
    int t;
    for (t = 0; t < buffer_size; t++) 
    {
        double relative_time = (double)t / SRATE;
        buffer[t] = 32767 * sin(2 * M_PI * freq * relative_time);
    }
}

/* Main function to generate and play a tone */
int main(int argc, char** argv)
{
    printf("Generating and playing a %.1f Hz tone for %d seconds...\n", FREQ, DUR);

    /* Allocate buffer for sound samples */
    int buffer_size = DUR * SRATE;
    short *buffer = (short*) malloc(sizeof(short) * buffer_size);

    /* Generate tone */
    generate_wave(FREQ, DUR, buffer, buffer_size);

    /* Open audio device */
    // CODE FOR OPENING AUDIO DEVICE GOES HERE

    /* Write samples to audio device */
    // CODE FOR WRITING SAMPLES TO AUDIO DEVICE GOES HERE

    /* Close audio device */
    // CODE FOR CLOSING AUDIO DEVICE GOES HERE

    /* Free buffer */
    free(buffer);

    printf("Done.\n");
    return 0;
}