//FormAI DATASET v1.0 Category: Audio processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define SAMPLE_RATE 44100

int main()
{
    int selection, duration;
    float frequency, amplitude;

    printf("Please select an audio processing option:\n");
    printf("1. Generate a sine wave\n");
    printf("2. Generate a square wave\n");
    printf("3. Generate a sawtooth wave\n");
    scanf("%d", &selection);

    printf("Enter the frequency of the wave (in Hz): ");
    scanf("%f", &frequency);

    printf("Enter the amplitude of the wave (between 0 and 1): ");
    scanf("%f", &amplitude);

    printf("Enter the duration of the wave (in seconds): ");
    scanf("%d", &duration);

    switch(selection)
    {
        case 1:
            sine_wave(frequency, amplitude, duration);
            break;
        case 2:
            square_wave(frequency, amplitude, duration);
            break;
        case 3:
            sawtooth_wave(frequency, amplitude, duration);
            break;
        default:
            printf("Invalid selection.\n");
            break;
    }

    return 0;
}

void sine_wave(float frequency, float amplitude, int duration)
{
    FILE *file_pointer;
    char filename[20];
    int i, samples;
    float time_step, sample_value, current_time;

    samples = SAMPLE_RATE * duration;
    time_step = 1.0 / SAMPLE_RATE;
    sprintf(filename, "sine_wave_%dHz_%dsec.raw", (int)frequency, duration);

    file_pointer = fopen(filename, "wb");

    for(i=0; i<samples; i++)
    {
        current_time = i * time_step;
        sample_value = amplitude * sin(2 * PI * frequency * current_time);
        fwrite(&sample_value, sizeof(sample_value), 1, file_pointer);
    }

    fclose(file_pointer);
    printf("Sine wave generated and saved to %s.\n", filename);
}

void square_wave(float frequency, float amplitude, int duration)
{
    FILE *file_pointer;
    char filename[20];
    int i, samples, half_period;
    float time_step, sample_value, current_time;

    half_period = (int)round(0.5 * SAMPLE_RATE / frequency);
    samples = SAMPLE_RATE * duration;
    time_step = 1.0 / SAMPLE_RATE;
    sprintf(filename, "square_wave_%dHz_%dsec.raw", (int)frequency, duration);

    file_pointer = fopen(filename, "wb");

    for(i=0; i<samples; i++)
    {
        current_time = i * time_step;
        sample_value = (fmod(current_time, 1.0/frequency) < (1.0/frequency)/2) ? amplitude : -amplitude;
        fwrite(&sample_value, sizeof(sample_value), 1, file_pointer);
    }

    fclose(file_pointer);
    printf("Square wave generated and saved to %s.\n", filename);
}

void sawtooth_wave(float frequency, float amplitude, int duration)
{
    FILE *file_pointer;
    char filename[20];
    int i, samples;
    float time_step, sample_value, current_time;

    samples = SAMPLE_RATE * duration;
    time_step = 1.0 / SAMPLE_RATE;
    sprintf(filename, "sawtooth_wave_%dHz_%dsec.raw", (int)frequency, duration);

    file_pointer = fopen(filename, "wb");

    for(i=0; i<samples; i++)
    {
        current_time = i * time_step;
        sample_value = amplitude * (2 * (fmod(current_time, 1.0/frequency) * frequency) - 1);
        fwrite(&sample_value, sizeof(sample_value), 1, file_pointer);
    }

    fclose(file_pointer);
    printf("Sawtooth wave generated and saved to %s.\n", filename);
}