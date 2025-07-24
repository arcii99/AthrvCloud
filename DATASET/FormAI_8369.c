//FormAI DATASET v1.0 Category: System process viewer ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PATH_LEN 1024
#define MAX_CMD_LEN 1024

struct process {
    int pid;
    char command[MAX_CMD_LEN];
    char state;
    int ppid;
    int pgrp;
    int session;
    int tty_nr;
    int tpgid;
    unsigned int flags;
    unsigned long int minflt;
    unsigned long int cminflt;
    unsigned long int majflt;
    unsigned long int cmajflt;
    unsigned long int utime;
    unsigned long int stime;
    long int cutime;
    long int cstime;
    long int priority;
    long int nice;
};

void parse_status_file(char *filename, struct process *p) {
    FILE *fp;
    char line[MAX_CMD_LEN], *token, *endptr;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, ":\t");
        if (!strcmp(token, "Pid")) {
            token = strtok(NULL, ":\t");
            p->pid = atoi(token);
        } else if (!strcmp(token, "State")) {
            token = strtok(NULL, ":\t");
            p->state = token[0];
        } else if (!strcmp(token, "PPid")) {
            token = strtok(NULL, ":\t");
            p->ppid = atoi(token);
        } else if (!strcmp(token, "Pgrp")) {
            token = strtok(NULL, ":\t");
            p->pgrp = atoi(token);
        } else if (!strcmp(token, "Session")) {
            token = strtok(NULL, ":\t");
            p->session = atoi(token);
        } else if (!strcmp(token, "TtyNr")) {
            token = strtok(NULL, ":\t");
            p->tty_nr = atoi(token);
        } else if (!strcmp(token, "Tpgid")) {
            token = strtok(NULL, ":\t");
            p->tpgid = atoi(token);
        } else if (!strcmp(token, "Flags")) {
            token = strtok(NULL, ":\t");
            p->flags = strtol(token, NULL, 16);
        } else if (!strcmp(token, "Minflt")) {
            token = strtok(NULL, ":\t");
            p->minflt = strtol(token, &endptr, 10);
            if (*endptr == 'K') {
                p->minflt *= 1024;
            }
        } else if (!strcmp(token, "Cminflt")) {
            token = strtok(NULL, ":\t");
            p->cminflt = strtol(token, &endptr, 10);
            if (*endptr == 'K') {
                p->cminflt *= 1024;
            }
        } else if (!strcmp(token, "Majflt")) {
            token = strtok(NULL, ":\t");
            p->majflt = strtol(token, &endptr, 10);
            if (*endptr == 'K') {
                p->majflt *= 1024;
            }
        } else if (!strcmp(token, "Cmajflt")) {
            token = strtok(NULL, ":\t");
            p->cmajflt = strtol(token, &endptr, 10);
            if (*endptr == 'K') {
                p->cmajflt *= 1024;
            }
        } else if (!strcmp(token, "Utime")) {
            token = strtok(NULL, ":\t");
            p->utime = atoi(token);
        } else if (!strcmp(token, "Stime")) {
            token = strtok(NULL, ":\t");
            p->stime = atoi(token);
        } else if (!strcmp(token, "Cutime")) {
            token = strtok(NULL, ":\t");
            p->cutime = atoi(token);
        } else if (!strcmp(token, "Cstime")) {
            token = strtok(NULL, ":\t");
            p->cstime = atoi(token);
        } else if (!strcmp(token, "Priority")) {
            token = strtok(NULL, ":\t");
            p->priority = strtol(token, NULL, 10);
        } else if (!strcmp(token, "Nice")) {
            token = strtok(NULL, ":\t");
            p->nice = strtol(token, NULL, 10);
        }
    }

    fclose(fp);
}

void print_process_info(struct process *p) {
    printf("%d\t", p->pid);
    printf("%c\t", p->state);
    printf("%d\t", p->ppid);
    printf("%d\t", p->pgrp);
    printf("%d\t", p->session);
    printf("%d\t", p->tty_nr);
    printf("%d\t", p->tpgid);
    printf("%u\t", p->flags);
    printf("%lu\t", p->minflt);
    printf("%lu\t", p->cminflt);
    printf("%lu\t", p->majflt);
    printf("%lu\t", p->cmajflt);
    printf("%lu\t", p->utime);
    printf("%lu\t", p->stime);
    printf("%ld\t", p->cutime);
    printf("%ld\t", p->cstime);
    printf("%ld\t", p->priority);
    printf("%ld\n", p->nice);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LEN], status_file[MAX_PATH_LEN];
    struct process p;
    pid_t pid;

    printf("PID\tSTATE\tPPID\tPGRP\tSESSION\tTTY_NR\tTPGID\tFLAGS\tMINFLT\tCMINFLT\tMAJFLT\tCMAJFLT\tUTIME\tSTIME\tCUTIME\tCSTIME\tPRIORITY\tNICE\n");

    // Open /proc directory
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("Cannot open directory");
        exit(EXIT_FAILURE);
    }

    // Loop through all directories in /proc
    while ((entry = readdir(dir)) != NULL) {
        // Check if the directory is a process directory
        if (isdigit(entry->d_name[0])) {
            // Get the pid of the process
            pid = atoi(entry->d_name);

            // Construct the path to the process's status file
            snprintf(status_file, sizeof(status_file), "/proc/%d/status", pid);

            // Parse the process's status file
            parse_status_file(status_file, &p);

            // Print the process information
            print_process_info(&p);
        }
    }

    // Close /proc directory
    closedir(dir);

    return EXIT_SUCCESS;
}