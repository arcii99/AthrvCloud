//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    FILE *file;
    char path[1024];
    char line[256];
    char state[2];
    char color[10];
    
    dir = opendir("/proc");
    if (!dir) {
        perror("Couldn't open the directory");
        return 1;
    }
    printf("======= SYSTEM PROCESS VIEWER =======\n");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_DIR || strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        int pid = atoi(entry->d_name);
        sprintf(path, "/proc/%d/status", pid);
        file = fopen(path, "r");
        if (file) {
            while (fgets(line, sizeof(line), file)) {
                if (strncmp(line, "State:", 6) == 0) {
                    strncpy(state, &line[7], 1);
                    if (state[0] == 'S') {
                        strcpy(color, "\033[0;32m"); // green
                    } else if (state[0] == 'R') {
                        strcpy(color, "\033[0;31m"); // red
                    } else {
                        strcpy(color, "\033[0;33m"); // yellow
                    }
                    printf("%s%s [%d]\033[0m\n", color, entry->d_name, pid);
                    break;
                }
            }
            fclose(file);
        }
    }
    closedir(dir);
    return 0;
}