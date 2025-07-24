//FormAI DATASET v1.0 Category: System process viewer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROC 100
#define MAX_NAME 25
#define MAX_STATES 15

typedef struct process {
    char name[MAX_NAME];
    char state[MAX_STATES];
    pid_t pid;
    pid_t ppid;
    time_t start_time;
    long unsigned int rss;
} Process;

int get_processes(Process** procs);
void print_processes(Process* procs, int n_procs);

int main() {
    Process* processes;
    int n_processes;

    n_processes = get_processes(&processes);
    if (n_processes == -1) {
        printf("Error: Unable to retrieve process information.\n");
        return 1;
    }

    print_processes(processes, n_processes);
    free(processes);

    return 0;
}

int get_processes(Process** procs) {
    DIR* dir;
    FILE* fp;
    struct dirent* entry;
    char path[50];
    char line[100];
    int i = 0;

    *procs = (Process*) malloc(MAX_PROC * sizeof(Process));
    dir = opendir("/proc");

    if (!dir) {
        return -1;
    }

    while ((entry = readdir(dir)) != NULL && i < MAX_PROC) {
        if (isdigit(entry->d_name[0])) {
            sprintf(path, "/proc/%s/stat", entry->d_name);
            fp = fopen(path, "r");

            if (fp) {
                fscanf(fp, "%d %s %c %d %d %*d %*d "
                            "%*d %*d %*d %*d %*d %"
                            "llu %lu %ld", &(*procs)[i].pid, (*procs)[i].name, 
                            &(*procs)[i].state[0], &(*procs)[i].ppid, 
                            &(*procs)[i].start_time, &(*procs)[i].rss);

                fclose(fp);
                i++;
            }
        }
    }

    closedir(dir);

    return i;
}

void print_processes(Process* procs, int n_procs) {
    time_t raw_time;
    struct tm *info;
    char time_buffer[80];

    printf("PID\tPPID\tNAME\t\t\tSTATE\t\tSTART TIME\tMEMORY USAGE\n");

    for (int i = 0; i < n_procs; i++) {
        raw_time = procs[i].start_time / sysconf(_SC_CLK_TCK);
        info = localtime(&raw_time);
        strftime(time_buffer, 80, "%x %X", info);

        printf("%d\t%d\t%-25s%c\t%s\t%ld\n", 
                procs[i].pid, procs[i].ppid, procs[i].name, 
                procs[i].state[0], time_buffer, procs[i].rss);
    }
}