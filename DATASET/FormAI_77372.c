//FormAI DATASET v1.0 Category: System process viewer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(void) {
    printf("Welcome to the Medieval Process Viewer!\n");
    while (1) {
        printf("Choose an option:\n1. View processes\n2. Exit\n");
        char option[10];
        scanf("%s", option);
        if (strcmp(option, "1") == 0) {
            DIR *dir;
            struct dirent *ent;
            char *path = "/proc";
            if ((dir = opendir(path)) != NULL) {
                printf("%-10s  %-30s  %s\n", "PID", "Name", "Status");
                while ((ent = readdir(dir)) != NULL) {
                    char *endptr;
                    long pid = strtol(ent->d_name, &endptr, 10);
                    if (*endptr == '\0') {
                        char buffer[1024];
                        snprintf(buffer, sizeof(buffer), "/proc/%ld/stat", pid);
                        FILE *file = fopen(buffer, "r");
                        if (file) {
                            char name[1024], status;
                            fscanf(file, "%ld %s %c ", &pid, name, &status);
                            fclose(file);
                            printf("%-10ld  %-30s  %c\n", pid, name, status);
                        }
                    }
                }
                closedir(dir);
            }
        } else if (strcmp(option, "2") == 0) {
            printf("Exiting...\n");
            return 0;
        } else {
            printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}