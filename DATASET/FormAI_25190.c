//FormAI DATASET v1.0 Category: Audio processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

int main()
{
    int choice;
    float freq1, freq2, duration, sample_rate, amplitude;
    float time_period, t, max_amplitude;

    printf("Choose an audio effect operation:\n");
    printf("1. Generate a Sine Wave\n");
    printf("2. Generate a Square Wave\n");
    printf("3. Generate a Sawtooth Wave\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nEnter the frequency in Hz: ");
    scanf("%f", &freq1);

    if (choice == 1)
    {
        printf("\nEnter the duration in seconds: ");
        scanf("%f", &duration);

        printf("\nEnter the sample rate in Hz: ");
        scanf("%f", &sample_rate);

        printf("\nEnter the amplitude: ");
        scanf("%f", &amplitude);

        // Calculate the time period and maximum amplitude
        time_period = 1 / freq1;
        max_amplitude = amplitude * (2 * PI / time_period);

        // Generate the sine wave
        for (t = 0; t < duration; t += 1/sample_rate)
        {
            float value = amplitude * sin(2 * PI * freq1 * t);
            printf("%f\n", value);
        }
    }
    else if (choice == 2)
    {
        printf("\nEnter the duty cycle of the square wave (0 to 1): ");
        scanf("%f", &freq2);

        printf("\nEnter the duration in seconds: ");
        scanf("%f", &duration);

        printf("\nEnter the sample rate in Hz: ");
        scanf("%f", &sample_rate);

        printf("\nEnter the amplitude: ");
        scanf("%f", &amplitude);

        // Generate the square wave
        for (t = 0; t < duration; t += 1/sample_rate)
        {
            float value = amplitude * ((int)(freq1*t) % (int)(1/freq2) < (1/freq2)/2 ? 1 : -1);
            printf("%f\n", value);
        }
    }
    else if (choice == 3)
    {
        printf("\nEnter the duration in seconds: ");
        scanf("%f", &duration);

        printf("\nEnter the sample rate in Hz: ");
        scanf("%f", &sample_rate);

        printf("\nEnter the amplitude: ");
        scanf("%f", &amplitude);

        // Generate the sawtooth wave
        for (t = 0; t < duration; t += 1/sample_rate)
        {
            float value = amplitude * fmod(freq1 * t, 1);
            printf("%f\n", value);
        }
    }
    else
    {
        printf("Invalid choice.");
        exit(0);
    }

    return 0;
}