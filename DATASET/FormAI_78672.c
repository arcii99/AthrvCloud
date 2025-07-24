//FormAI DATASET v1.0 Category: Temperature monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

void printTemperature(float temp) {
    printf("Current temperature is: %.2f°C\n", temp);
}

int main() {
    int fd, temp;
    char buf[256];
    time_t t;
    float currentTemp;

    fd = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open the file");
        return 1;
    }

    while (1) {
        lseek(fd, 0, SEEK_SET);
        read(fd, buf, sizeof(buf));
        temp = atoi(buf);
        currentTemp = (float)temp/1000;
        printTemperature(currentTemp);

        time(&t);
        struct tm *timeinfo = localtime(&t);

        printf("As of %s", asctime(timeinfo));
        sleep(1);
    }

    return 0;
}