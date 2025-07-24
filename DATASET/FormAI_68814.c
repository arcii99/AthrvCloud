//FormAI DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc < 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        exit(1);
    }

    char command[512];
    sprintf(command, "ps aux | grep %s | grep -v grep", argv[1]);

    // Execute system command and read output
    FILE *fp;
    char output[2048];
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Error executing system command\n");
        exit(1);
    }
    fgets(output, sizeof(output), fp);
    pclose(fp);

    // Parse output
    char *tokens[1024];
    char *sep = " ";
    char *ptr = strtok(output, sep);
    int i = 0;
    while (ptr != NULL) {
        tokens[i++] = ptr;
        ptr = strtok(NULL, sep);
    }

    // Print process information
    printf("PID: %s\n", tokens[1]);
    printf("USER: %s\n", tokens[0]);
    printf("CPU: %s\n", tokens[2]);
    printf("MEM: %s\n", tokens[3]);
    printf("VSZ: %s\n", tokens[4]);
    printf("RSS: %s\n", tokens[5]);
    printf("TTY: %s\n", tokens[6]);
    printf("STAT: %s\n", tokens[7]);
    printf("START: %s %s\n", tokens[8], tokens[9]);
    printf("TIME: %s\n", tokens[10]);
    printf("COMMAND: %s\n", tokens[11]);

    return 0;
}