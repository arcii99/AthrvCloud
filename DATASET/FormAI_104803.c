//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define NUM_CORES 4

int main()
{
    float cpu_usage[NUM_CORES];
    char buffer[BUFFER_SIZE];
    FILE* file = fopen("/proc/stat", "r");

    if (!file)
    {
        fprintf(stderr, "Unable to open /proc/stat\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, file))
    {
        if (strncmp(buffer, "cpu ", 4) == 0)
        {
            char* token = strtok(buffer + 4, " ");
            int i = 0;

            while (token != NULL && i < NUM_CORES)
            {
                cpu_usage[i++] = atof(token);
                token = strtok(NULL, " ");
            }
            break;
        }
    }

    fclose(file);

    for (int i = 0; i < NUM_CORES; i++)
    {
        printf("CPU%d: %2.1f%%\n", i, cpu_usage[i] * 100);
    }

    return 0;
}