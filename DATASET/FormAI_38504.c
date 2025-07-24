//FormAI DATASET v1.0 Category: Audio processing ; Style: scalable
#include <stdio.h>

#define SAMPLE_RATE 44100 /* Sample rate of audio */
#define BUFFER_SIZE 2048 /* Size of audio buffer */

int main() {

    /* Allocate memory for audio buffer */
    float buffer[BUFFER_SIZE];

    /* Process audio buffer */
    for (int i=0; i<BUFFER_SIZE; i++) {
        buffer[i] = buffer[i] * 0.5; /* Half the amplitude of the audio */
    }

    /* Print out audio buffer */
    printf("Audio buffer:\n");
    for (int i=0; i<BUFFER_SIZE; i++) {
        printf("%.2f ", buffer[i]);
    }

    return 0;
}