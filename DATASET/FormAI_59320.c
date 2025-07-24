//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main(void) {

    char buf[256];
    int temp, fd, len;
    time_t now;

    fd = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    if (fd == -1) {
        perror("Could not open thermal_zone0");
        exit(EXIT_FAILURE);
    }

    while (1) {
        len = read(fd, &buf, 256);
        if (len == -1) {
            perror("Could not read temperature");
            exit(EXIT_FAILURE);
        }
        temp = atoi(buf) / 1000;
        now = time(NULL);
        printf("Temperature at %s is %dC\n", ctime(&now), temp);
        sleep(10);
    }

    return 0;
}