//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"
#define BUF_SIZE 10

int main(int argc, char **argv) {
    int fd;
    char buf[BUF_SIZE];
    float temp;

    while (1) {
        fd = open(TEMP_PATH, O_RDONLY);
        if (fd < 0) {
            fprintf(stderr, "Error: cannot open %s\n", TEMP_PATH);
            exit(1);
        }

        if (read(fd, buf, BUF_SIZE) < 0) {
            fprintf(stderr, "Error: cannot read from %s\n", TEMP_PATH);
            exit(1);
        }

        temp = atoi(buf) / 1000.0f;

        printf("Current temperature: %.2fC\n", temp);

        close(fd);

        sleep(1);
    }
    
    return 0;
}