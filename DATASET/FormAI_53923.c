//FormAI DATASET v1.0 Category: System process viewer ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LINE_SIZE 256

int main() {
    char line[LINE_SIZE];
    FILE* file = fopen("/proc", "r");

    if (!file) {
        printf("Failed to open /proc\n");
        exit(1);
    }

    printf("PID\tName\n");

    while (fgets(line, LINE_SIZE, file)) {
        if (strcmp(line, ".\n") == 0 || strcmp(line, "..\n") == 0) continue;

        char path[LINE_SIZE];
        snprintf(path, sizeof(path), "/proc/%s/stat", line);

        FILE* proc_file = fopen(path, "r");
        if (!proc_file) continue;

        int pid;
        char comm[LINE_SIZE];

        fscanf(proc_file, "%d (%s", &pid, comm);

        comm[strlen(comm) - 1] = '\0';

        fclose(proc_file);

        printf("%d\t%s\n", pid, comm);
    }

    fclose(file);

    return 0;
}