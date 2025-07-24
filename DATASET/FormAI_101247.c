//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>

int main() {

    float threshold = 90; // Threshold RAM usage percentage
    float usage = 0; // Current RAM usage percentage
    struct sysinfo si;

    // Get the total amount of RAM in the system
    sysinfo(&si);
    long int total_ram = si.totalram / (1024*1024);

    // Main loop to constantly monitor RAM usage
    while(1) {

        // Get the current amount of RAM being used
        sysinfo(&si);
        long int used_ram = si.totalram - si.freeram;
        usage = ((float) used_ram / total_ram) * 100;

        // Check if usage is above the threshold
        if(usage > threshold) {
            printf("WARNING: RAM usage is above %f%%!\n", threshold);

            // Write to a log file for paranoia purposes
            FILE *log_file = fopen("ram_monitor.log", "a");
            if(log_file == NULL) {
                printf("Unable to open log file, quitting...\n");
                exit(1);
            }
            time_t current_time = time(NULL);
            fprintf(log_file, "%sWARNING: RAM usage is above %f%%!\n", asctime(localtime(&current_time)), threshold);
            fclose(log_file);
        } else {
            printf("RAM usage is currently %f%%\n", usage);
        }

        // Sleep for 30 seconds before checking again
        sleep(30);
    }

    return 0;
}