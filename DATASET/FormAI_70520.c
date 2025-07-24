//FormAI DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512

void stereo_panning (short samps_l[BUFFER_SIZE], short samps_r[BUFFER_SIZE], float pan)
{
    short temp_samps[BUFFER_SIZE];

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        temp_samps[i] = samps_l[i];

        samps_l[i] = samps_l[i] * cos(pan) + samps_r[i] * sin(pan);
        samps_r[i] = temp_samps[i] * sin(pan) + samps_r[i] * cos(pan);
    }
}

void lowpass_filter (short samps[BUFFER_SIZE], float cutoff_freq)
{
    float RC = 1.0 / (cutoff_freq * 2 * M_PI);
    float dt = 1.0 / (float) SAMPLE_RATE;
    float alpha = dt / (RC + dt);

    float prev_out = (float) samps[0];

    for (int i = 1; i < BUFFER_SIZE; i++)
    {
        float curr_out = alpha * (float) samps[i] + (1 - alpha) * prev_out;

        prev_out = curr_out;

        samps[i] = (short) curr_out;
    }
}

int main()
{
    short audio_samples_l[BUFFER_SIZE];
    short audio_samples_r[BUFFER_SIZE];

    // initalise audio samples
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        audio_samples_l[i] = (rand() % 32767) + (-32768);
        audio_samples_r[i] = (rand() % 32767) + (-32768);
    }

    // apply stereo panning
    stereo_panning(audio_samples_l, audio_samples_r, 0.5 * M_PI);

    // apply lowpass filter
    lowpass_filter(audio_samples_l, 5000);

    // write audio samples to file
    FILE *fp = fopen("output.pcm", "wb");

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        fwrite(&audio_samples_l[i], sizeof(short), 1, fp);
        fwrite(&audio_samples_r[i], sizeof(short), 1, fp);
    }

    fclose(fp);

    return 0;
}