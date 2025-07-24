//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 512

void execute_command(char* command, char* output) {
    FILE* fp = popen(command, "r");
    char buffer[BUFFER_SIZE];
    if (fp == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        strcat(output, buffer);
    }

    pclose(fp);
}

void check_cpu_usage() {
    char output[BUFFER_SIZE];
    char* command = "ps -C <process_name> -o %cpu | tail -n 1";
    execute_command(command, output);

    // Remove leading and trailing white spaces
    char* p = output;
    while (isspace(*p)) {
        ++p;
    }
    int cpu_usage = atoi(p);
    printf("Current CPU usage: %d%%\n", cpu_usage);
}

int main() {
    while (1) {
        check_cpu_usage();
        sleep(5);
    }
    return 0;
}