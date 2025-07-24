//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

float get_cpu_usage()
{
    /* Open output of command 'top' */
    FILE *fp = popen("top -b -n 1 | grep \"Cpu(s)\" | awk '{print $2}'", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[MAX_BUFFER_SIZE];
    char *last_char;
    float cpu_usage;

    /* Read top output and extract CPU usage percentage */
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        cpu_usage = strtof(buffer, &last_char);
    }

    pclose(fp);

    return cpu_usage;
}

int main()
{
    float cpu_usage;

    /* Continuously monitor CPU usage and print to console */
    while (1) {
        cpu_usage = get_cpu_usage();
        printf("CPU usage: %.2f%%\n", cpu_usage);
        usleep(500000);
    }

    return 0;
}