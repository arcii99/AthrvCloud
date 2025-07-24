//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MAX_BUFF_SIZE 256

/* Function to get CPU usage percentage */
float get_cpu_usage() {
    FILE *fp;
    char buff[MAX_BUFF_SIZE], *token;
    float cpu_usage = 0;
    int cpu_count = 0;

    /* Open /proc/stat file */
    fp = fopen("/proc/stat", "r");
    if(fp == NULL) {
        fprintf(stderr, "Error opening /proc/stat\n");
        return -1;
    }

    /* Read first line of /proc/stat */
    fgets(buff, MAX_BUFF_SIZE, fp);

    /* Extract first token */
    token = strtok(buff, " ");
    if(strcmp(token, "cpu") != 0) {
        fprintf(stderr, "Error in parsing /proc/stat\n");
        fclose(fp);
        return -1;
    }

    /* Loop through all CPU cores */
    while((token = strtok(NULL, " ")) != NULL) {
        cpu_count++;
        cpu_usage += atoi(token);
    }

    /* Close the file and return CPU usage percentage */
    fclose(fp);
    return (cpu_usage / cpu_count);
}

/* Main function */
int main() {
    int interval = 1; /* Time interval between two measurements in seconds */
    float prev_cpu_usage, curr_cpu_usage, cpu_usage_diff;

    /* Get initial CPU usage */
    prev_cpu_usage = get_cpu_usage();
    if(prev_cpu_usage == -1) {
        fprintf(stderr, "Error getting CPU usage\n");
        exit(EXIT_FAILURE);
    }

    /* Loop forever */
    while(1) {
        /* Sleep for interval seconds */
        sleep(interval);

        /* Get current CPU usage */
        curr_cpu_usage = get_cpu_usage();
        if(curr_cpu_usage == -1) {
            fprintf(stderr, "Error getting CPU usage\n");
            exit(EXIT_FAILURE);
        }

        /* Calculate CPU usage diff */
        cpu_usage_diff = curr_cpu_usage - prev_cpu_usage;

        /* Print CPU usage diff */
        printf("%f\n", cpu_usage_diff);

        /* Set previous CPU usage to current */
        prev_cpu_usage = curr_cpu_usage;
    }

    return 0;
}