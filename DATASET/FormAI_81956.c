//FormAI DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#define MAX_PID_LENGTH 6
#define MEMINFO_PATH "/proc/meminfo"
#define STATUS_PATH_TEMPLATE "/proc/%s/status"

typedef struct {
    char pid[MAX_PID_LENGTH];
    char name[256];
    char state;
    long int utime;
    long int stime;
    long int rss;
} process_info;

void trim_whitespace(char *str) {
    int i = 0, j = -1;
    while (str[i]) {
        if (!isspace(str[i]))
            j = i;
        i++;
    }
    if (j >= 0)
        str[j + 1] = '\0';
}

int read_meminfo(long int *total_mem, long int *free_mem) {
    FILE* fp = fopen(MEMINFO_PATH, "r");
    if (!fp)
        return -1;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            char *value_start = strchr(line, ':') + 1;
            sscanf(value_start, "%ld", total_mem);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            char *value_start = strchr(line, ':') + 1;
            sscanf(value_start, "%ld", free_mem);
        }
    }

    fclose(fp);
    return 0;
}

int read_process_stats(const char* pid, process_info *info) {
    char path[256];
    sprintf(path, STATUS_PATH_TEMPLATE, pid);

    FILE* fp = fopen(path, "r");
    if (!fp)
        return -1;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            char *value_start = strchr(line, ':') + 1;
            trim_whitespace(value_start);
            strncpy(info->name, value_start, sizeof(info->name));
        } else if (strncmp(line, "State:", 6) == 0) {
            char *value_start = strchr(line, ':') + 1;
            trim_whitespace(value_start);
            info->state = value_start[0];
        } else if (strncmp(line, "Pid:", 4) == 0) {
            char *value_start = strchr(line, ':') + 1;
            trim_whitespace(value_start);
            strncpy(info->pid, value_start, MAX_PID_LENGTH);
        } else if (strncmp(line, "VmRSS:", 6) == 0) {
            char *value_start = strchr(line, ':') + 1;
            info->rss = strtol(value_start, NULL, 10);
        } else if (strncmp(line, "utime:", 6) == 0) {
            char *value_start = strchr(line, ':') + 1;
            info->utime = strtol(value_start, NULL, 10);
        } else if (strncmp(line, "stime:", 6) == 0) {
            char *value_start = strchr(line, ':') + 1;
            info->stime = strtol(value_start, NULL, 10);
        }
    }
    fclose(fp);
    return 0;
}

int main() {
    long int total_mem = 0, free_mem = 0;
    if (read_meminfo(&total_mem, &free_mem) != 0) {
        fprintf(stderr, "Failed to read memory info\n");
        return 1;
    }

    printf("Total memory: %ld KB\n", total_mem);
    printf("Free memory: %ld KB\n", free_mem);

    printf("\nPID\tNAME\t\tSTATE\tRSS\tUTIME\tSTIME\n");

    DIR *d;
    struct dirent *dir;
    d = opendir("/proc");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (!isdigit(dir->d_name[0]))
                continue;

            process_info info;
            if (read_process_stats(dir->d_name, &info) != 0)
                continue;

            printf("%s\t%-15s\t%2c\t%5ld\t%ld\t%ld\n",
                info.pid, info.name, info.state, info.rss,
                info.utime, info.stime);
        }
        closedir(d);
    }

    return 0;
}