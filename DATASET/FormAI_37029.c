//FormAI DATASET v1.0 Category: Temperature monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#define TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"
#define TEMP_WARNING_THRESHOLD 70000 // 70°C, warning threshold temperature

int main() {

    int fd, temp, warn_flag = 0;
    char buffer[1024];

    // System signal handling
    signal(SIGINT, SIG_DFL);

    // Open the temperature monitor file
    fd = open(TEMP_FILE, O_RDONLY);
    if(fd == -1) {
        fprintf(stderr, "Error: Cannot open file %s\n", TEMP_FILE);
        return 1;
    }

    // Continuously read the temperature and display it
    while(1) {
        // Read the current temperature
        lseek(fd, 0L, SEEK_SET);
        if(read(fd, buffer, 1024) < 0) {
            fprintf(stderr, "Error: Cannot read from file %s\n", TEMP_FILE);
            close(fd);
            return 1;
        }
        temp = atoi(buffer) / 1000;

        // Check if the temperature has crossed the warning threshold
        if(temp >= TEMP_WARNING_THRESHOLD) {
            if(!warn_flag) {
                warn_flag = 1;
                printf("Warning: Temperature has reached %d°C\n", temp);
            }
        } else {
            warn_flag = 0;
        }

        // Display the current temperature
        printf("Current temperature: %d°C\n", temp);

        // Sleep for 1 second before reading the temperature again
        sleep(1);
    }

    close(fd);
    return 0;
}