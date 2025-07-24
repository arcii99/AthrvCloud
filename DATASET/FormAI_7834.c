//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define MAX_PID 32768
#define PROC_DIR "/proc/"

typedef struct {
    int pid;
    char comm[1024];
    char state;
    unsigned long utime, stime;
    int threads;
} process_info;

void print_process_info(process_info *info) {
    printf("%d\t%s\t%c\t%lu\t%lu\t%d\n", info->pid, info->comm, info->state,
           info->utime, info->stime, info->threads);
}

int read_process_info(int pid, process_info *info) {
    char path[1024], line[1024], *p;
    FILE *f;

    sprintf(path, PROC_DIR "%d/stat", pid);
    f = fopen(path, "r");
    if (f == NULL) {
        return 0;
    }

    if (fgets(line, sizeof(line), f) == NULL) {
        fclose(f);
        return 0;
    }

    fclose(f);

    p = line;
    p = strchr(p, '(');
    if (p == NULL) {
        return 0;
    }

    strncpy(info->comm, p + 1, sizeof(info->comm) - 1);
    p = strchr(info->comm, ')');
    if (p == NULL) {
        return 0;
    }
    *p = '\0';

    sscanf(line, "%d %s %c", &info->pid, &info->comm, &info->state);
    p = strchr(line, ')');
    if (p == NULL) {
        return 0;
    }
    ++p; // skip ')' character
    sscanf(p, " %lu %lu", &info->utime, &info->stime);

    sprintf(path, PROC_DIR "%d/task", pid);
    info->threads = 0;
    DIR *dir = opendir(path);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0])) {
            continue;
        }
        ++info->threads;
    }
    closedir(dir);

    return 1;
}

int main(int argc, char **argv) {
    int pid;
    process_info info;

    printf("PID\tCMD\tSTATE\tUTIME\tSTIME\tTHREADS\n");

    for (pid = 0; pid <= MAX_PID; ++pid) {
        if (read_process_info(pid, &info)) {
            print_process_info(&info);
        }
    }

    return 0;
}