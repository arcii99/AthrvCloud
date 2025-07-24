//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define PROC_MEMINFO "/proc/meminfo" // path of the file to read memory information from
#define BUFFER_SIZE 1024 // size of buffer to read data into

int main()
{
    int fd = open(PROC_MEMINFO, O_RDONLY);
    if(fd < 0) // error opening file
    {
        printf("Failed to open " PROC_MEMINFO "\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = read(fd, buffer, BUFFER_SIZE); // reading memory information from file
    if(bytes_read < 0) // error reading file
    {
        printf("Failed to read " PROC_MEMINFO "\n");
        return 1;
    }

    // parsing memory information from buffer
    long total_memory = 0, free_memory = 0, available_memory = 0;
    char* line = strtok(buffer, "\n");
    while(line)
    {
        if(strncmp(line, "MemTotal:", 9) == 0)
            sscanf(line + 9, "%ld", &total_memory);
        else if(strncmp(line, "MemFree:", 8) == 0)
            sscanf(line + 8, "%ld", &free_memory);
        else if(strncmp(line, "MemAvailable:", 13) == 0)
            sscanf(line + 13, "%ld", &available_memory);

        line = strtok(NULL, "\n");
    }

    close(fd); // close file descriptor

    // calculating memory usage
    long used_memory = total_memory - free_memory;
    float usage_percent = ((float)used_memory / total_memory) * 100;

    // printing memory usage information on console
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB (%.2f %%)\n", used_memory, usage_percent);
    printf("Available Memory: %ld kB\n", available_memory);

    return 0;
}