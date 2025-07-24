//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>

// Global variable to store the current RAM usage
int current_ram_usage = 0;

// Function to handle CTRL+C signal
void handle_sigint(int sig)
{
    printf("\nCurrent RAM usage: %dMB\n", current_ram_usage);
    exit(0);
}

// Function to update current RAM usage
void update_ram_usage()
{
    FILE* fp;
    char path[1024];

    sprintf(path, "/proc/%d/status", getpid());

    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Error: Failed to open file /proc/%d/status\n", getpid());
        return;
    }

    char line[128];
    int ram_usage = 0;

    while (fgets(line, 128, fp) != NULL){
        if (strncmp(line, "VmRSS:", 6) == 0){
            ram_usage = atoi(&line[6]);
            break;
        }
    }

    fclose(fp);

    current_ram_usage = ram_usage / 1024;
}

int main()
{
    // Set signal handler for CTRL+C
    signal(SIGINT, handle_sigint);

    while (1) {
        update_ram_usage();
        printf("Current RAM usage: %dMB\n", current_ram_usage);
        sleep(1);
    }

    return 0;
}