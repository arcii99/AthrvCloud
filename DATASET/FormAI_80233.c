//FormAI DATASET v1.0 Category: System administration ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_CMD_LENGTH 1024

int main(int argc, char *argv[]) {
    char cmd[MAX_CMD_LENGTH];
    FILE *fp;
    char line[MAX_CMD_LENGTH];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sprintf(cmd, "ls -la %s", argv[1]);

    fp = popen(cmd, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to execute command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("Directory listing of %s:\n", argv[1]);
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    pclose(fp);

    return 0;
}