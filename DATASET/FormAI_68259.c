//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_LOAD_AVG 100

void display_header() {
    printf("\n+--------------------------+\n");
    printf("| CPU USAGE MONITOR        |\n");
    printf("+--------------------------+\n\n");
}

void display_usage(double usage) {
    int bar_length = (int)(usage * MAX_LOAD_AVG);
    printf("| CPU Usage: %7.3f %% |", usage * 100);
    printf("\n| [%.*s%*s] |", bar_length, "==================", MAX_LOAD_AVG - bar_length, "");
}

int main() {
    double usage = 0.0;

    display_header();

    while (1) {
        system("clear");
        display_header();
        printf("\nPress Ctrl+C to exit...\n");

        // Use rand() to simulate CPU usage
        usage = (double)rand() / (double)RAND_MAX;

        display_usage(usage);
        usleep(1000000);
    }

    return 0;
}