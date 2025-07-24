//FormAI DATASET v1.0 Category: System process viewer ; Style: scalable
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PROC_PATH "/proc"

int main(void) {
    DIR* dir = opendir(PROC_PATH);
    if (!dir) {
        fprintf(stderr, "Failed to open " PROC_PATH "\n");
        exit(EXIT_FAILURE);
    }

    struct dirent* dir_entry;
    while ((dir_entry = readdir(dir))) {
        const char* name = dir_entry->d_name;
        if (!isdigit(name[0])) {
            continue;
        }

        char path[PATH_MAX] = { 0 };
        snprintf(path, sizeof(path), PROC_PATH "/%s/stat", name);

        FILE* stat_file = fopen(path, "r");
        if (!stat_file) {
            continue;
        }

        int pid;
        char cmd[NAME_MAX];
        fscanf(stat_file, "%d %s", &pid, cmd);
        fclose(stat_file);

        printf("PID: %d, COMMAND: %s\n", pid, cmd);
    }

    closedir(dir);
    return 0;
}