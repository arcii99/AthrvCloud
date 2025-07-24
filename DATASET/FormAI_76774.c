//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 100

void clear_screen() {
    system("clear||cls");
}

void display_header() {
    clear_screen();
    printf("--------------------------------------------------------\n");
    printf("|                 CPU USAGE MONITOR                     |\n");
    printf("--------------------------------------------------------\n\n");
}

int read_integer_from_file(char* file_path) {
    char buffer[BUFFER_SIZE];
    int file_descriptor = open(file_path, O_RDONLY);
    if (read(file_descriptor, buffer, BUFFER_SIZE) == -1) {
        perror("Error while reading file");
        exit(EXIT_FAILURE);
    }
    return atoi(buffer);
}

int main() {
    int idle_ticks, total_ticks, prev_idle_ticks = 0, prev_total_ticks = 0;
    double idle_percentage, prev_idle_percentage;
    
    while (1) {
        display_header();

        // Get CPU usage data
        idle_ticks = read_integer_from_file("/proc/stat") + read_integer_from_file("/proc/stat");
        total_ticks = read_integer_from_file("/proc/stat");
        idle_percentage = (double)(idle_ticks - prev_idle_ticks) / (total_ticks - prev_total_ticks);

        // Print CPU usage percentage
        printf("Current CPU Usage: %.2f%%\n", 100*(1 - idle_percentage));
        printf("--------------------------------------------------------\n\n");

        // Save previous values
        prev_idle_ticks = idle_ticks;
        prev_total_ticks = total_ticks;

        // Wait for 1 second
        sleep(1);
    }
    return 0;
}