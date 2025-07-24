//FormAI DATASET v1.0 Category: Audio processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE (44100)
#define SAMPLE_COUNT (SAMPLE_RATE * 2)
#define FREQUENCY_FIRST (440)
#define FREQUENCY_SECOND (880)
#define MAX_AMPLITUDE (32760)

int main() {
    short data[SAMPLE_COUNT];
    int i;

    for(i=0; i<SAMPLE_COUNT; i++) {
        double t = (double)i / SAMPLE_RATE;
        double t1 = fmod(t, 1.0 / FREQUENCY_SECOND) * FREQUENCY_SECOND;
        double t2 = fmod(t, 1.0 / FREQUENCY_FIRST) * FREQUENCY_FIRST;
        double value = (sin(2 * M_PI * t1) + sin(2 * M_PI * t2)) * 0.5 * MAX_AMPLITUDE;

        if (value > MAX_AMPLITUDE) {
            value = MAX_AMPLITUDE;
        } else if (value < -MAX_AMPLITUDE) {
            value = -MAX_AMPLITUDE;
        }

        data[i] = (short)value;
    }

    FILE *file = fopen("output.bin", "wb");
    fwrite(data, sizeof(short), SAMPLE_COUNT, file);
    fclose(file);

    printf("The program has completed the audio processing.\n");

    return 0;
}