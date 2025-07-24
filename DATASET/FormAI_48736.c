//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>

#define BUFFER_SIZE 512
#define DELIMITER " "

// Function to get the current RAM usage
long int get_ram_usage() {
    char buffer[BUFFER_SIZE];
    long int ram_usage = 0;
    FILE* file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char* token = strtok(buffer, DELIMITER);
        if (token != NULL) {
            if (strcmp(token, "MemAvailable:") == 0) {
                token = strtok(NULL, DELIMITER);
                if (token != NULL) {
                    ram_usage = strtol(token, NULL, 10);
                }
                break;
            }
        }
    }
    fclose(file);
    return ram_usage;
}

int main() {

    while (true) {
        long int curr_ram_usage = get_ram_usage();
        printf("Current RAM usage: %ld kB\n", curr_ram_usage);
        sleep(1);
    }

    return 0;
}