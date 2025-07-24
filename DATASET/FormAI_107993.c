//FormAI DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* A peaceful C program to play with audio data */

/* Define our sample rate */
#define SAMPLE_RATE 44100

/* Define the maximum amplitude */
#define AMP_MAX 32767

/* Define the frequency of our sine wave */
#define SINE_FREQ 440

/* Define the length of our sine wave in seconds */
#define SINE_LENGTH 2

/* Define our audio buffer size */
#define BUFFER_SIZE SAMPLE_RATE * SINE_LENGTH

/* Function to generate a sine wave */
void generate_sine_wave(short* buffer, double freq, int length) {
    double phase = 0;
    double increment = 2 * M_PI * freq / SAMPLE_RATE;
    int i;
    for (i = 0; i < length; i++) {
        buffer[i] = (short)(AMP_MAX * sin(phase));
        phase += increment;
        if (phase >= 2 * M_PI) {
            phase -= 2 * M_PI;
        }
    }
}

int main() {
    /* Allocate memory for our audio buffer */
    short* buffer = (short*)malloc(sizeof(short) * BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Failed to allocate memory for audio buffer\n");
        return 1;
    }

    /* Generate a sine wave in our audio buffer */
    generate_sine_wave(buffer, SINE_FREQ, BUFFER_SIZE);

    /* Write the audio buffer to a file */
    FILE* fp;
    fp = fopen("sine_wave.raw", "wb");
    fwrite(buffer, sizeof(short), BUFFER_SIZE, fp);
    fclose(fp);
    
    /* Free the memory allocated to our audio buffer */
    free(buffer);

    return 0;
}