//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CPU 8

int main()
{
    int cpu_usage[MAX_CPU];
    memset(cpu_usage, 0, sizeof(cpu_usage));

    while(1)
    {
        int fd;
        char buffer[1024];
        ssize_t nbytes;

        fd = open("/proc/stat", O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening /proc/stat");
            exit(EXIT_FAILURE);
        }

        nbytes = read(fd, buffer, sizeof(buffer));
        if (nbytes < 0)
        {
            perror("Error reading /proc/stat");
            exit(EXIT_FAILURE);
        }

        char *sptr = buffer;
        while (*sptr != '\n')
        {
            if (strncmp(sptr, "cpu", 3) == 0)
            {
                sptr += 3;
                int cpu_id = atoi(sptr);
                if (cpu_id >= MAX_CPU)
                {
                    printf("WARNING: Only %d CPUs are supported, "
                           "but found %d CPUs in /proc/stat\n", MAX_CPU, cpu_id + 1);
                }
                else
                {
                    sptr = strtok(sptr, " \t\r\n");
                    cpu_usage[cpu_id] = 0;
                    for (int i = 0; i < 10; i++)
                    {
                        sptr = strtok(NULL, " \t\r\n");
                        cpu_usage[cpu_id] += atoi(sptr);
                    }
                }
            }
            else
            {
                sptr = strchr(sptr, '\n');
                if (sptr != NULL)
                {
                    sptr++;
                }
            }
        }

        close(fd);
        sleep(1);

        printf("CPU usage:\n");
        for (int i = 0; i < MAX_CPU; i++)
        {
            printf("CPU %d: %d%%\n", i, cpu_usage[i]);
        }
    }

    return 0;
}