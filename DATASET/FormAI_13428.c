//FormAI DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LEN 50
#define MAX_SAMPLES 10000

int main()
{
    char filename[MAX_FILENAME_LEN];
    int samples[MAX_SAMPLES];
    int num_samples, option;

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    printf("Enter the number of samples: ");
    scanf("%d", &num_samples);

    for (int i = 0; i < num_samples; i++)
    {
        fscanf(fp, "%d", &samples[i]);
    }

    fclose(fp);

    printf("Select an option: \n");
    printf("1. Normalize audio\n");
    printf("2. Add an echo\n");
    printf("3. Reverse audio\n");
    printf("4. Exit\n");

    printf("Enter option: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        // normalize audio
        int max = 0;
        for (int i = 0; i < num_samples; i++)
        {
            if (abs(samples[i]) > max)
            {
                max = abs(samples[i]);
            }
        }
        for (int i = 0; i < num_samples; i++)
        {
            samples[i] = samples[i] * (32767.0 / max);
        }
        break;

    case 2:
        // add an echo
        int delay;
        printf("Enter delay (in ms): ");
        scanf("%d", &delay);

        int delay_samples = (delay * 44100) / 1000;
        for (int i = delay_samples; i < num_samples; i++)
        {
            samples[i] = samples[i] + (0.5 * samples[i-delay_samples]);
        }
        break;

    case 3:
        // reverse audio
        int temp;
        for (int i = 0; i < num_samples / 2; i++)
        {
            temp = samples[i];
            samples[i] = samples[num_samples - i - 1];
            samples[num_samples - i - 1] = temp;
        }
        break;

    case 4:
        // exit
        exit(0);
        break;

    default:
        printf("Invalid option!");
        break;
    }

    // write processed audio to file
    char out_filename[MAX_FILENAME_LEN] = "processed_";
    strcat(out_filename, filename);

    fp = fopen(out_filename, "w");

    for (int i = 0; i < num_samples; i++)
    {
        fprintf(fp, "%d\n", samples[i]);
    }

    fclose(fp);

    return 0;
}