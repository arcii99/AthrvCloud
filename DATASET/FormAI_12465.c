//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

int main() {
    DIR* proc_dir = opendir("/proc");
    struct dirent* entry;

    printf("PID     Name        Status\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        if (isdigit(*entry->d_name)) {
            char filename[128];
            char name[128];
            char status[128];
            sprintf(filename, "/proc/%s/status", entry->d_name);

            FILE* sfile = fopen(filename, "r");
            if (sfile == NULL) continue;

            while (fscanf(sfile, "%s", name) == 1) {
                if (strcmp(name, "Name:") == 0) {
                    fscanf(sfile, "%s", name);
                }
                if (strcmp(name, "State:") == 0) {
                    fscanf(sfile, "%s", status);
                }
            }

            fclose(sfile);

            printf("%-7s %-11s %s\n", entry->d_name, name, status);
        }
    }

    closedir(proc_dir);
    return 0;
}