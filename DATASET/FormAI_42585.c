//FormAI DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

int main()
{
    int fd;
    char c[30];
    time_t t;
    struct tm *tmp;
    char buff[16];
    char temp[6];
    float current_temp;


    fd = open("/sys/bus/w1/devices/28-01131c5184ff/w1_slave", O_RDONLY);

    if(fd == -1)
    {
        perror("Error in opening file");
        return -1;
    }

    while(1)
    {
        // Resetting strings and buffers
        memset(temp, 0, 6);
        memset(buff, 0, 16);
        lseek(fd, 0, SEEK_SET);

        if(read(fd, c, 30) == -1)
        {
            perror("Error in reading file");
            return -1;
        }

        // Extracting required temperature data from the file
        strncpy(temp, strstr(c, "t=") + 2, 5);
        current_temp = atof(temp) / 1000;

        // Getting current local time
        t = time(NULL);
        tmp = localtime(&t);
        strftime(buff, 16, "%H:%M:%S", tmp);

        printf("Current temperature: %.2f C \t Time: %s\n", current_temp, buff);

        // Wait for 5 seconds
        sleep(5);
    }

    return 0;
}