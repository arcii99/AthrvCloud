//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define CPU_LOAD_PATH "/proc/loadavg"

int main() {
    double cpu_load;
    pid_t pid = fork(); // Fork a new process
    if (pid == -1) { // Forking failed, exit with failure
        fprintf(stderr, "Error: Unable to fork a new process.\n");
        return EXIT_FAILURE;
    }
    else if (pid == 0) { // If we are in the child process
        char buffer[BUFFER_SIZE];
        FILE* file_ptr = fopen(CPU_LOAD_PATH, "r"); // Open /proc/loadavg for reading
        if (file_ptr == NULL) { // File did not open correctly, exit with failure
            fprintf(stderr, "Error: Unable to open %s\n", CPU_LOAD_PATH);
            exit(EXIT_FAILURE);
        }
        fscanf(file_ptr, "%lf", &cpu_load); // Read the first value from /proc/loadavg
        fclose(file_ptr); // Close the file pointer
        printf("The current CPU load is: %.2lf\n", cpu_load); // Output the current CPU load
    }
    else { // If we are in the parent process
        printf("Starting CPU usage monitor...\n");
        while (1) { // Loop indefinitely
            char buffer[BUFFER_SIZE];
            FILE* file_ptr = fopen(CPU_LOAD_PATH, "r"); // Open /proc/loadavg for reading
            if (file_ptr == NULL) { // File did not open correctly, exit with failure
                fprintf(stderr, "Error: Unable to open %s\n", CPU_LOAD_PATH);
                exit(EXIT_FAILURE);
            }
            fscanf(file_ptr, "%lf", &cpu_load); // Read the first value from /proc/loadavg
            fclose(file_ptr); // Close the file pointer
            printf("The current CPU load is: %.2lf\n", cpu_load); // Output the current CPU load
            sleep(2); // Wait for 2 seconds before reading again
        }
    }
    return EXIT_SUCCESS;
}