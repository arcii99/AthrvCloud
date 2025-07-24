//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd, temp;
    char buff[20];

    fd = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    if(fd == -1)
    {
        printf("Error reading temperature file\n");
        return -1;
    }

    while(1)
    {
        lseek(fd, 0L, SEEK_SET);
        read(fd, buff, 20);
        temp = atoi(buff) / 1000;

        printf("Current temperature: %d C\n", temp);
        sleep(1);
    }

    close(fd);

    return 0;
}