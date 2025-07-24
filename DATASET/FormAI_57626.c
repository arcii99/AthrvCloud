//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse the output of the `free` command and return the amount of used RAM in bytes
unsigned long long get_ram_usage()
{
    FILE *fp;
    char buffer[256];
    char *token;
    unsigned long long used_ram;

    // Execute the `free` command and capture its output
    fp = popen("free", "r");
    if (fp == NULL)
    {
        printf("Error: failed to execute the `free` command.");
        exit(1);
    }

    // Read the output of the `free` command line by line until the line containing "Mem:" is found
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (strstr(buffer, "Mem:") != NULL)
        {
            // Parse the line containing "Mem:" and extract the amount of used RAM in bytes
            token = strtok(buffer, " ");
            token = strtok(NULL, " ");
            used_ram = strtoull(token, NULL, 10) * 1024;

            pclose(fp);
            return used_ram;
        }
    }

    printf("Error: failed to parse the output of the `free` command.");
    exit(1);
}

int main()
{
    unsigned long long prev_ram_usage = 0;
    unsigned long long curr_ram_usage;

    while (1)
    {
        // Sleep for 1 second
        sleep(1);

        // Get the current RAM usage
        curr_ram_usage = get_ram_usage();

        // Calculate the change in RAM usage
        long long ram_usage_change = curr_ram_usage - prev_ram_usage;

        // Print the current RAM usage and the change in RAM usage
        printf("Current RAM usage: %llu bytes (change: %lld bytes)\n", curr_ram_usage, ram_usage_change);

        // Update the previous RAM usage to the current value
        prev_ram_usage = curr_ram_usage;
    }

    return 0;
}