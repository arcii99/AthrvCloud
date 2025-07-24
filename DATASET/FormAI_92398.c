//FormAI DATASET v1.0 Category: Temperature monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define TEMP_FILE_PATH "/sys/class/thermal/thermal_zone0/temp"
#define SLEEP_TIME 5 // in seconds

int main(void) {
    int fd;
    double temp;
    char buffer[256];
    time_t current_time;
    struct tm * time_info;

    while(1) {
        fd = open(TEMP_FILE_PATH, O_RDONLY);
        if (fd == -1) {
            fprintf(stderr, "Failed to open the temperature file.\n");
            exit(EXIT_FAILURE);
        }

        if (read(fd, buffer, sizeof(buffer)) == -1) {
            fprintf(stderr, "Failed to read from the temperature file.\n");
            close(fd);
            exit(EXIT_FAILURE);
        }

        close(fd);

        temp = atoi(buffer) / 1000.0;

        current_time = time(NULL);
        time_info = localtime(&current_time);

        printf("Current Temperature: %.2lf°C\tTime: %.2d:%.2d:%.2d\n", temp, time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
        sleep(SLEEP_TIME);
    }

    return 0;
}