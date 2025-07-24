//FormAI DATASET v1.0 Category: Digital signal processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 100000

int main()
{
    FILE* in_file = fopen("sound.wav", "rb");
    FILE* out_file = fopen("filtered_sound.wav", "wb");

    if (in_file == NULL || out_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    // header of the wav file is skipped
    int bytes_to_skip = 44;
    fseek(in_file, bytes_to_skip, SEEK_SET);

    short int samples[MAX_SAMPLES];
    int sample_count = 0;

    while (fread(&samples[sample_count], 2, 1, in_file) == 1 && sample_count < MAX_SAMPLES) {
        sample_count++;
    }

    double cutoff_frequency = 1000.0; // in Hz
    double rc = 1.0 / (2.0 * M_PI * cutoff_frequency);
    double dt = 0.0005; // sampling time in seconds
    double alpha = rc / (rc + dt);

    double filtered_samples[MAX_SAMPLES];
    filtered_samples[0] = samples[0];

    // apply high-pass filter to samples
    for (int i = 1; i < sample_count; ++i) {
        filtered_samples[i] = alpha * (filtered_samples[i-1] + samples[i] - samples[i-1]);
    }

    fwrite(samples, 2, sample_count, out_file);
    fclose(in_file);
    fclose(out_file);

    return 0;
}