//FormAI DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_BUFFSIZE 1024
#define MAX_UIDLEN 10

int isNumeric(const char *str) {
    while (*str != '\0') {
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return 1;
}

void printSeparator(int count, char separator) {
    int i;
    for (i = 0; i < count; i++) {
        putchar(separator);
    }
    putchar('\n');
}

void printProcessInfo(char *pid, char *uid, char *state, char *mem, char *name) {
    printf("%-10s %-10s %-10s %-10s %-30s\n", pid, uid, state, mem, name);
}

int main() {
    DIR *dir;
    struct dirent *dir_entry;
    char uid[MAX_UIDLEN];
    char pid[MAX_BUFFSIZE];
    char state[MAX_BUFFSIZE];
    char mem[MAX_BUFFSIZE];
    char name[MAX_BUFFSIZE];
    char stat_file[MAX_BUFFSIZE];
    FILE *fp;

    dir = opendir("/proc");
    if (!dir) {
        perror("Error opening /proc directory.");
        exit(EXIT_FAILURE);
    }

    printf("PROCESS VIEWER:\n");
    printSeparator(65, '-');
    printf("%-10s %-10s %-10s %-10s %-30s\n", "PID", "USER", "STATE", "MEMORY", "NAME");
    printSeparator(65, '-');

    while ((dir_entry = readdir(dir))) {
        if (isNumeric(dir_entry->d_name)) {
            snprintf(stat_file, sizeof(stat_file), "/proc/%s/stat", dir_entry->d_name);
            fp = fopen(stat_file, "r");
            if (fp) {
                fscanf(fp, "%s %s %s", pid, name, state);
                fclose(fp);
                snprintf(stat_file, sizeof(stat_file), "/proc/%s/status", dir_entry->d_name);
                fp = fopen(stat_file, "r");
                if (fp) {
                    while (fgets(uid, sizeof(uid), fp)) {
                        if (strncmp(uid, "Uid:", 4) == 0) {
                            strtok(uid, " \t");
                            snprintf(uid, sizeof(uid), "%s", strtok(NULL, " \t"));
                            break;
                        }
                    }
                    fclose(fp);
                } else {
                    continue;
                }
                snprintf(stat_file, sizeof(stat_file), "/proc/%s/statm", dir_entry->d_name);
                fp = fopen(stat_file, "r");
                if (fp) {
                    fscanf(fp, "%s", mem);
                    fclose(fp);
                } else {
                    continue;
                }
                printProcessInfo(pid, uid, state, mem, name);
            }
        }
    }

    printSeparator(65, '-');
    closedir(dir);
    return 0;
}