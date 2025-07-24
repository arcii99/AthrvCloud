//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid, cr_usage;
    char* cr_stat_path;
    FILE* cr_stat_file;

    // Get the process ID
    pid = getpid();

    // Get the path to the C RAM stats file for this process
    cr_stat_path = (char*) malloc(sizeof(char) * 50);
    sprintf(cr_stat_path, "/proc/%d/statm", pid);

    // Open the C RAM stats file
    cr_stat_file = fopen(cr_stat_path, "r");

    // Read the C RAM usage from the file
    fscanf(cr_stat_file, "%*d %d", &cr_usage);

    // Close the stat file and free up memory
    fclose(cr_stat_file);
    free(cr_stat_path);

    // Print the C RAM usage in KB
    printf("Current C RAM usage: %d KB\n", cr_usage * getpagesize() / 1024);

    // Sleep for 5 seconds
    sleep(5);

    return 0;
}