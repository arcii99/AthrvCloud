//FormAI DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backup(char *filename) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    char command[1000];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%Y-%m-%d_%H-%M-%S", timeinfo);
    sprintf(command, "cp %s %s_backup_%s", filename, filename, buffer);

    system(command);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }

    char *filename = argv[1];

    printf("Backing up %s...\n", filename);
    backup(filename);
    printf("Backup complete!\n");

    return 0;
}