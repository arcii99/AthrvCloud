//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define SENSOR_PATH "/sys/class/thermal/thermal_zone0/temp"

int main() {
    int temperature = 0;
    char buffer[256];
    time_t now;
    struct tm *current_time;

    while(1) {
        int file_desc = open(SENSOR_PATH, O_RDONLY);
        if (file_desc < 0) {
            printf("Error: Failed to open the temperature sensor.\n");
            exit(1);
        }

        int bytes_read = read(file_desc, buffer, sizeof(buffer));
        if (bytes_read < 0) {
            printf("Error: Failed to read the temperature sensor.\n");
            exit(1);
        }

        close(file_desc);

        temperature = atoi(buffer) / 1000;

        printf("The current temperature is %dC.\n", temperature);

        now = time(NULL);
        current_time = localtime(&now);

        printf("Time: %02d:%02d:%02d\n", current_time->tm_hour, current_time->tm_min, current_time->tm_sec);

        sleep(1);
    }

    return 0;
}