//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int cpuusage = 0;
    double totaltime, idletime, prevtotaltime = 0, previdletime = 0;
    char line[100], cpu[10];
    int i, fd;

    while(1)
    {
        fd = open("/proc/stat", O_RDONLY);

        if(fd < 0)
        {
            printf("Error in opening the file\n");
            exit(1);
        }

        read(fd, line, sizeof(line));
        close(fd);

        for(i = 0; i < strlen(line); i++)
        {
            if(line[i] == ' ')
            {
                break;
            }
        }

        strncpy(cpu, line, i);

        sscanf(line+i+1, "%lf %*lf %lf", &totaltime, &idletime);

        if(prevtotaltime != 0 && previdletime != 0)
        {
            cpuusage = 100 - ((idletime - previdletime) / (totaltime - prevtotaltime)) * 100;
        }
        
        printf("CPU Usage: %d%%\n", cpuusage);

        prevtotaltime = totaltime;
        previdletime = idletime;

        sleep(2); // Refresh rate of 2 seconds
    }
    
    return 0;
}