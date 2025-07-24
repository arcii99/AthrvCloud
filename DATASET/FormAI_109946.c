//FormAI DATASET v1.0 Category: System process viewer ; Style: Ken Thompson
/*
 * Ken Thompson Style System Process Viewer
 * By: Your Name
 */

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("PID   PPID   CMD\n");
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char buf[512];
            sprintf(buf, "/proc/%s/stat", entry->d_name);
            FILE *fp = fopen(buf, "r");

            if (!fp) {
                continue;
            }

            // Parsing process information
            char comm[256];
            int pid, ppid;
            fscanf(fp, "%d %s %*c %d", &pid, comm, &ppid);
            fclose(fp);

            // Removing parentheses from command name
            comm[strcspn(comm, ")")] = '\0';
            memmove(comm, comm + 1, strlen(comm));

            printf("%-5d %-5d %s\n", pid, ppid, comm);
        }
    }

    closedir(dir);
    return 0;
}