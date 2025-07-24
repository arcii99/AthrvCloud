//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main()
{
    char buffer[BUFFER_SIZE];
    int fd, n;
    fd = open("/proc/stat", O_RDONLY, 0);
    if (fd < 0)
    {
        perror("Could not open /proc/stat");
        exit(1);
    }
    while (1)
    {
        lseek(fd, 0, SEEK_SET);
        n = read(fd, buffer, BUFFER_SIZE - 1);
        if (n < 0)
        {
            perror("Could not read /proc/stat");
            exit(1);
        }
        buffer[n] = '\0';
        char* cpu_line = strtok(buffer, "\n");
        double total_jiffies = 0, idle_jiffies = 0;
        while (cpu_line != NULL)
        {
            if (strncmp(cpu_line, "cpu ", 4) == 0)
            {
                char* tokens = strtok(cpu_line, " ");
                tokens = strtok(NULL, " ");
                for (int i = 0; i < 7; ++i)
                {
                    tokens = strtok(NULL, " ");
                    total_jiffies += atof(tokens);
                    if (i == 3)
                    {
                        idle_jiffies = atof(tokens);
                    }
                }
                break;
            }
            cpu_line = strtok(NULL, "\n");
        }
        double cpu_use = 100.0 * (1 - (idle_jiffies / total_jiffies));
        printf("%f%% CPU usage\n", cpu_use);
        sleep(1);
    }
    close(fd);
    return 0;
}