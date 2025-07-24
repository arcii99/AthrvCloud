//FormAI DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main() {
    struct dirent *de;
    DIR *dir = opendir("/proc");

    // Check if directory exists
    if (dir == NULL) {
        printf("Unable to open directory.");
        return 0;
    }

    printf("%-6s | %s\n", "PID", "Process Name");

    while ((de = readdir(dir)) != NULL) {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
            continue;
        int pid = atoi(de->d_name);
        if (pid == 0)
            continue;
        char filename[255];
        sprintf(filename, "/proc/%d/status", pid);
        FILE *fp = fopen(filename, "r");
        if (!fp)
            continue;
        char process_name[255];
        while (fgets(process_name, 255, fp)) {
            if (strncmp(process_name, "Name:", 5) == 0) {
                sscanf(process_name, "%*s %s", process_name);
                break;
            }
        }
        fclose(fp);
        printf("%-6d | %s\n", pid, process_name);
    }
    closedir(dir);
    return 0;
}