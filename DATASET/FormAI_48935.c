//FormAI DATASET v1.0 Category: Temperature monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"
#define TEMP_THRESHOLD 60000

int main() {
    int temp_fd, temp;
    char buffer[6];
    while (1) {
        temp_fd = open(TEMP_FILE, O_RDONLY);
        if (temp_fd < 0) {
            perror("Failed to open the temperature file");
            exit(EXIT_FAILURE);
        }
        if (read(temp_fd, buffer, sizeof(buffer)) < 0) {
            perror("Failed to read the temperature");
            exit(EXIT_FAILURE);
        }
        close(temp_fd);
        temp = atoi(buffer);
        temp /= 1000;
        printf("Current temperature: %dC\n", temp);
        if (temp > TEMP_THRESHOLD) {
            printf("Temperature threshold exceeded!\n");
            // Trigger an alarm here
        }
        sleep(1);
    }
    return 0;
}