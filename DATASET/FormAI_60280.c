//FormAI DATASET v1.0 Category: Temperature monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"

int main()
{
    int fd, temperature;
    char buffer[50];

    fd = open(TEMP_PATH, O_RDONLY);
    if (fd < 0) {
        printf("Failed to open file to read temperature.\n");
        return 1;
    }

    while (1) {
        lseek(fd, 0, SEEK_SET);
        if (read(fd, buffer, sizeof(buffer)) < 0) {
            printf("Failed to read temperature from file.\n");
            close(fd);
            return 1;
        }

        temperature = atoi(buffer) / 1000;
        printf("Current CPU temperature is: %d°C\n", temperature);

        sleep(1); // Wait for 1 second before reading temperature again
    }

    close(fd);

    return 0;
}