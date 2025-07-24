//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to extract CPU usage percentage from "/proc/stat" file
float get_cpu_usage() {
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    char* line;

    // Open "/proc/stat" file
    int file = open("/proc/stat", O_RDONLY);
    if (file == -1) {
        fprintf(stderr, "Error opening CPU stats file\n");
        exit(1);
    }

    // Read first line of file
    int bytes_read = read(file, buffer, BUFFER_SIZE);
    if (bytes_read == -1) {
        fprintf(stderr, "Error reading from CPU stats file\n");
        exit(1);
    }

    // Parse first line to extract user and system CPU usage time
    line = strtok(buffer, "\n");
    line = strtok(line, " ");
    float user_time = atof(strtok(NULL, " "));
    float system_time = atof(strtok(NULL, " "));

    // Compute total CPU usage time and percentage
    float total_time = user_time + system_time;
    float idle_time = atof(strtok(NULL, " "));
    float usage_time = total_time - idle_time;
    float usage_percentage = 100.0 * usage_time / total_time;

    // Close file and return CPU usage percentage
    close(file);
    return usage_percentage;
}

int main() {
    const int INTERVAL_SECONDS = 1;
    int total_seconds = 0;
    float total_usage = 0.0;

    // Print header
    printf("%5s %10s %10s\n", "Time", "Usage", "Average");

    // Loop indefinitely
    while (1) {
        // Wait for interval
        sleep(INTERVAL_SECONDS);

        // Get CPU usage percentage
        float usage = get_cpu_usage();
        total_usage += usage;
        total_seconds += INTERVAL_SECONDS;

        // Compute average usage percentage
        float average = total_usage / total_seconds;

        // Print current and average usage percentages
        printf("%5d %10.2f %10.2f\n", total_seconds, usage, average);
    }
}