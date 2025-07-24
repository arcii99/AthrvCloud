//FormAI DATASET v1.0 Category: System process viewer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir() failed");
        exit(1);
    }

    printf("PID    COMMAND\n");

    while ((entry = readdir(dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            char filename[64];
            sprintf(filename, "/proc/%s/cmdline", entry->d_name);

            FILE *file = fopen(filename, "r");
            if (file) {
                char command[512];
                if (fgets(command, sizeof(command), file)) {
                    printf("%s    %s", entry->d_name, command);
                }
                fclose(file);
            }
        }
    }

    closedir(dir);
    return 0;
}