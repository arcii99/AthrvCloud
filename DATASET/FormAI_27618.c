//FormAI DATASET v1.0 Category: Audio processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <pthread.h>

#define SAMPLE_RATE 44100
#define BUFSIZE 512

double sin_lut[360];

/* This function initializes the sine lookup table. */
void init_lut() {
    for (int i = 0; i < 360; i++) {
        sin_lut[i] = sin(i * M_PI / 180.0);
    }
}

/* This function generates a sine wave of the given frequency and length. */
void *generate_sin(void *args) {
    double frequency = *(double*)args;
    int length = SAMPLE_RATE / frequency;
    short *buffer = malloc(length * sizeof(short));
    for (int i = 0; i < length; i++) {
        buffer[i] = (short)(sin_lut[(int)((double)i / length * 360)] * 32767);
    }
    pthread_exit(buffer);
}

/* This function applies a fade in/out effect to the given buffer. */
void *apply_fade(void *args) {
    short *buffer = (short*)args;
    int fade_length = SAMPLE_RATE / 10;
    for (int i = 0; i < fade_length; i++) {
        double fade = i / (double)fade_length;
        buffer[i] *= fade;
        buffer[BUFSIZE - fade_length + i] *= fade;
    }
    pthread_exit(buffer);
}

int main() {
    init_lut();

    double freq = 440.0;
    void *result1, *result2;
    pthread_t thread1, thread2;

    /* Create thread 1 to generate a sine wave. */
    pthread_create(&thread1, NULL, generate_sin, &freq);

    /* Create thread 2 to apply a fade effect to the sine wave. */
    pthread_create(&thread2, NULL, apply_fade, pthread_join(&thread1, &result1));

    /* Play the resulting audio. */
    int dev = open("/dev/dsp", O_WRONLY);
    while (1) {
        if (write(dev, result2, BUFSIZE * sizeof(short)) != BUFSIZE * sizeof(short)) {
            perror("write");
            exit(1);
        }
    }
    close(dev);
    free(result1);
    free(result2);

    return 0;
}