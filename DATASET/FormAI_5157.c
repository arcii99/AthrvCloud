//FormAI DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#define MAX_READ_BUFFER_SIZE 1024

int main() {
    DIR *dirp;
    struct dirent *dirent;
    char* process_path_template = "/proc/%s/status";
    char process_path[MAX_READ_BUFFER_SIZE], buffer[MAX_READ_BUFFER_SIZE], *line;
    FILE *fp;
    pid_t pid;

    printf("PID\tPPID\tNAME\n");

    dirp = opendir("/proc/");
    if (dirp == NULL) {
        perror("Failed to open /proc/ directory");
        exit(1);
    }

    while ((dirent = readdir(dirp)) != NULL) {
        if (dirent->d_type != DT_DIR) {
            continue;
        }

        pid = atoi(dirent->d_name);

        if (pid == 0) {
            continue;
        }

        sprintf(process_path, process_path_template, dirent->d_name);
        fp = fopen(process_path, "r");
        if (fp == NULL) {
            continue;
        }

        line = fgets(buffer, MAX_READ_BUFFER_SIZE - 1, fp);
        while (line != NULL) {
            if (strncmp(line, "Name:", 5) == 0) {
                line += 6;
                printf("%s\t", dirent->d_name);  // PID
                line[strlen(line) - 1] = 0;
                printf("%s\t", buffer);  // PPID
                printf("%s\n", line);  // NAME
                break;
            } else if (strncmp(line, "PPid:", 5) == 0) {
                line += 6;
                if (strcmp(line, "1\n") == 0) {
                    printf("%s\t", dirent->d_name);  // PID
                    printf("INIT\t");  // PPID
                    break;
                }
                break;
            }

            line = fgets(buffer, MAX_READ_BUFFER_SIZE - 1, fp);
        }
        fclose(fp);
    }
    return 0;
}