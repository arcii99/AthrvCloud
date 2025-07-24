//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int total_idle_time, total_cpu_time;
    double cpu_usage;
    FILE* file_pointer;
    char file_name[20] = "/proc/stat";
    char read_buffer[50];

    while (1)
    {
        file_pointer = fopen(file_name, "r");
        if (file_pointer == NULL)
        {
            fprintf(stderr, "Error opening file!\n");
            exit(EXIT_FAILURE);
        }

        fgets(read_buffer, sizeof(read_buffer), file_pointer);
        sscanf(read_buffer, "cpu %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %d %d", &total_idle_time, &total_cpu_time);

        fclose(file_pointer);
        cpu_usage = (1-((double)total_idle_time)/total_cpu_time) * 100.0;
        printf("CPU Usage: %0.2f%%\n", cpu_usage);
        sleep(1);
    }

    return 0;
}