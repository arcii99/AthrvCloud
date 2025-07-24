//FormAI DATASET v1.0 Category: Audio processing ; Style: statistical
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int sample_rate = 44100; // sample rate in Hz
    int num_samples = 88200; // duration in samples (2 seconds)
    float freq = 440.0; // frequency of sine wave
    float volume = 0.5; // volume (range from 0 to 1)

    float *audio_buffer = malloc(num_samples * sizeof(float)); // allocate memory for audio buffer

    for (int i = 0; i < num_samples; i++) {
        // generate sine wave at specified frequency
        audio_buffer[i] = volume * sin(2 * M_PI * freq * i / sample_rate);
    }

    // calculate mean and standard deviation of audio buffer
    float sum = 0.0, mean = 0.0, variance = 0.0, std_dev = 0.0;
    for (int i = 0; i < num_samples; i++) {
        sum += audio_buffer[i];
    }
    mean = sum / num_samples;
    for (int i = 0; i < num_samples; i++) {
        variance += pow(audio_buffer[i] - mean, 2);
    }
    variance /= num_samples;
    std_dev = sqrt(variance);

    // output mean and standard deviation
    printf("Mean: %f\n", mean);
    printf("Standard deviation: %f\n", std_dev);

    // write audio buffer to file
    FILE *fp = fopen("audio.raw", "wb");
    fwrite(audio_buffer, sizeof(float), num_samples, fp);
    fclose(fp);

    free(audio_buffer); // free memory

    return 0;
}