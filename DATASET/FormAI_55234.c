//FormAI DATASET v1.0 Category: Digital signal processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100 // sample rate in Hz
#define BUFFER_SIZE 512 // buffer size in samples
#define PI 3.14159265358979323846 // PI
#define FREQUENCY1 440 // frequency of sine wave 1
#define FREQUENCY2 220 // frequency of sine wave 2

int main() {
    float buffer[BUFFER_SIZE];
    float phase1 = 0; // starting phase of sine wave 1
    float phase2 = 0; // starting phase of sine wave 2
    float frequency1 = FREQUENCY1; // current frequency of sine wave 1
    float frequency2 = FREQUENCY2; // current frequency of sine wave 2
    float amplitude1 = 0.5; // amplitude of sine wave 1
    float amplitude2 = 0.5; // amplitude of sine wave 2
    float phase_increment1 = 2 * PI * frequency1 / SAMPLE_RATE; // phase increment for sine wave 1
    float phase_increment2 = 2 * PI * frequency2 / SAMPLE_RATE; // phase increment for sine wave 2
    int i;

    // infinite loop
    while (1) {
        // generate sine waves and write to buffer
        for (i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] = amplitude1 * sin(phase1) + amplitude2 * sin(phase2);
            phase1 += phase_increment1;
            phase2 += phase_increment2;

            // wrap phase values between 0 and 2*pi
            if (phase1 >= 2 * PI) {
                phase1 -= 2 * PI;
            }
            if (phase2 >= 2 * PI) {
                phase2 -= 2 * PI;
            }

            // randomly change frequencies and amplitudes
            if (rand() % 1000 == 0) {
                frequency1 = FREQUENCY1 + rand() % 200 - 100;
                frequency2 = FREQUENCY2 + rand() % 200 - 100;
                phase_increment1 = 2 * PI * frequency1 / SAMPLE_RATE;
                phase_increment2 = 2 * PI * frequency2 / SAMPLE_RATE;
                amplitude1 = (float) rand() / RAND_MAX;
                amplitude2 = (float) rand() / RAND_MAX;
            }
        }

        // do some post-apocalyptic digital signal processing on the buffer here...
        // for example, you could implement bitcrushing, distortion, filtering, etc.

        // send audio to audio output device here...
        // for example, you could use ALSA or PortAudio to output the audio to speakers

    }
    return 0;
}