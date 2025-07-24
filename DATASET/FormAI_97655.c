//FormAI DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void showProcessInfo(char *pid) {
    char filePath[50];
    char line[100];
    FILE *fp;

    sprintf(filePath, "/proc/%s/status", pid);

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        return;
    }

    while (fgets(line, 100, fp) != NULL) {
        if (strncmp(line, "Name:", 5) == 0 || strncmp(line, "Pid:", 4) == 0 || strncmp(line, "State:", 6) == 0) {
            printf("%s", line);
        }
    }
    fclose(fp);
}

int main() {
    DIR *dir;
    struct dirent *ent;
    char path[] = "/proc";

    dir = opendir(path);
    if (dir == NULL) {
        printf("Failed to open directory\n");
        return 1;
    }

    printf("------------------------------------------------------------\n");
    printf("| %-20s| %-10s| %-20s |\n", "Name", "PID", "State");
    printf("------------------------------------------------------------\n");

    while((ent = readdir(dir)) != NULL) {
        if (atoi(ent->d_name) != 0) {
            showProcessInfo(ent->d_name);
        }
    }
    closedir(dir);
    return 0;
}