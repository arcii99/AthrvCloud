//FormAI DATASET v1.0 Category: Temperature monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"

int main() {
    int fd;
    char buf[256];
    float temp;

    fd = open(TEMP_PATH, O_RDONLY);
    if (fd < 0) {
        printf("Could not open temperature file\n");
        return -1;
    }

    while (1) {
        lseek(fd, 0, SEEK_SET);
        read(fd, buf, 256);
        sscanf(buf, "%f", &temp);
        printf("Current temperature: %.1f°C\n", temp / 1000);
        sleep(5);
    }

    close(fd);

    return 0;
}