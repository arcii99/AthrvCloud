//FormAI DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void printProcInfo(char* pid) {
    char filename[512], buffer[1024], processName[128];
    FILE* fp;

    sprintf(filename, "/proc/%s/status", pid);

    fp = fopen(filename, "r");

    if (fp != NULL) {
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strncmp(buffer, "Name:", 5) == 0) {
                sscanf(buffer + 6, "%s", processName);
            }
            if (strncmp(buffer, "State:", 6) == 0) {
                printf("%-10s%-20s", pid, processName);
                printf("%-10s", strtok(buffer + 7, " "));
                break;
            }
        }
        fclose(fp);
    }
}

int main() {
    printf("%-10s%-20s%-10s\n", "PID", "Name", "State");

    DIR* procDir = opendir("/proc");
    struct dirent* dirEntry;

    while ((dirEntry = readdir(procDir)) != NULL) {
        if (dirEntry->d_type == DT_DIR && atoi(dirEntry->d_name) > 0) {
            printProcInfo(dirEntry->d_name);
        }
    }

    closedir(procDir);
    return 0;
}