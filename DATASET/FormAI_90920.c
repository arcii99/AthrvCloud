//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_MEM 8192 // max memory usage in MB

int main() {
    int interval = 1; // interval in seconds
    char command[256];
    char output[1024];
    double mem_usage;
    int paranoid_threshold = MAX_MEM / 2;
    int num_violations = 0;

    while (1) {
        // construct the system command to get memory usage
        sprintf(command, "ps -o rss= -p %d", getpid());

        // run the command and get the output
        FILE* fp = popen(command, "r");
        fgets(output, sizeof(output), fp);
        mem_usage = atof(output) / 1024.0; // convert from KB to MB
        pclose(fp);

        // check if usage is above paranoid threshold
        if (mem_usage > paranoid_threshold) {
            num_violations++;
            printf("Paranoid threshold exceeded! (Violations: %d)\n", num_violations);

            // terminate program if too many violations
            if (num_violations >= 3) {
                printf("Too many violations, terminating program.\n");
                exit(-1);
            }

            // sleep for a bit to prevent spamming
            sleep(5);
        }

        printf("Current memory usage: %.2f MB\n", mem_usage);

        // sleep for interval seconds
        sleep(interval);
    }

    return 0;
}