//FormAI DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_DIR "/proc"
#define MAX_COMM 255
#define MAX_STATE 255
#define MAX_BUFF 1024
#define MAX_PID_LEN 10

typedef struct {
    char comm[MAX_COMM+1];
    char state[MAX_STATE+1];
    pid_t pid;
    unsigned int rss;
} ProcEntry;

ProcEntry* read_proc_file(pid_t pid) {
    char buffer[MAX_BUFF];
    char filename[MAX_BUFF];
    FILE *stat_file;
    ProcEntry *entry;

    sprintf(filename, "/proc/%d/stat", pid);
    stat_file = fopen(filename, "r");
    if(!stat_file) {
        return NULL;
    }

    entry = malloc(sizeof(ProcEntry));

    fscanf(stat_file, "%d %s %s", &(entry->pid), entry->comm, entry->state);

    while(fgets(buffer, MAX_BUFF, stat_file)) {
        if(strncmp(buffer, "VmRSS:", 6) == 0) {
            sscanf(buffer+6, "%u", &(entry->rss));
        }
    }

    fclose(stat_file);

    return entry;
}

void print_process_info(ProcEntry *entry) {
    printf("%d %6u %s %s\n", entry->pid, entry->rss, entry->state, entry->comm);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char *endptr;
    pid_t pid;

    dir = opendir(PROC_DIR);
    if (!dir) {
        fprintf(stderr, "Cannot open proc directory %s\n", PROC_DIR);
        return EXIT_FAILURE;
    }

    while((entry = readdir(dir))) {
        if(!isdigit(entry->d_name[0])) {
            continue;
        }

        pid = strtol(entry->d_name, &endptr, 10);
        if(!*endptr && pid > 0) {
            ProcEntry *proc_entry = read_proc_file(pid);
            if(proc_entry) {
                print_process_info(proc_entry);
                free(proc_entry);
            }
        }
    }

    closedir(dir);

    return EXIT_SUCCESS;
}