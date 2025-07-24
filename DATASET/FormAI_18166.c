//FormAI DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;

    printf("PID   | NAME                | STATUS\n");
    printf("--------------------------------\n");

    dir = opendir("/proc");
    if (dir == NULL) {
        printf("Failed to open /proc directory.\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[50];
        sprintf(path, "/proc/%s/status", entry->d_name);

        FILE *fp = fopen(path, "r");
        if (fp != NULL) {
            char line[256];

            // Get process name 
            fgets(line, 256, fp);
            strtok(line, ":\t");
            char *name = strtok(NULL, ":\t");
            if (name != NULL) {
                // Get process status
                fgets(line, 256, fp);
                strtok(line, ":\t");
                char *status = strtok(NULL, ":\t");

                printf("%-5s | %-20s | %s\n", entry->d_name, name, status);
            }
            fclose(fp);
        }
    }

    closedir(dir);
    return 0;
}