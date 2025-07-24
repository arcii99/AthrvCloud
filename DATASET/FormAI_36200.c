//FormAI DATASET v1.0 Category: Temperature monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define TEMP_PATH "/sys/class/thermal/thermal_zone0/temp"

int main() {
    int fd, temp;
    char buf[256];
    size_t len = sizeof(buf);
    fd = open(TEMP_PATH, O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Failed to open %s: %s\n", TEMP_PATH, strerror(errno));
        exit(1);
    }
    while (1) {
        len = sizeof(buf) - 1;
        if (pread(fd, buf, len, 0) < 0) {
            fprintf(stderr, "Failed to read temperature: %s\n", strerror(errno));
        }
        buf[len] = '\0';
        temp = atoi(buf) / 1000;
        printf("Current CPU temperature: %d°C\n", temp);
        sleep(1);
    }
    close(fd);
    return 0;
}