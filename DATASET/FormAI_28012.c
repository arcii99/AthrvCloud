//FormAI DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define PROC_PATH "/proc/"
#define MAX_PATH_SIZE 1024
#define NAME_SIZE 256
#define CMDLINE_SIZE 2048

typedef struct {
    int pid;
    char name[NAME_SIZE];
    char cmdline[CMDLINE_SIZE];
    int ppid;
    int num_threads;
    long int vmsize;
} process_t;

void print_process_info(process_t *process) {
    printf("PID: %d\nName: %s\nCommand line: %s\nParent PID: %d\nNumber of threads: %d\nVirtual memory size: %ld bytes\n\n",
           process->pid, process->name, process->cmdline, process->ppid, process->num_threads, process->vmsize);
}

void read_process_info(int pid, process_t *process) {
    char path[MAX_PATH_SIZE], buf[MAX_PATH_SIZE], *temp;

    snprintf(path, MAX_PATH_SIZE, PROC_PATH "%d/cmdline", pid);
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        printf("Could not open file %s", path);
        exit(EXIT_FAILURE);
    }

    // read the process name from the cmdline file
    fgets(process->cmdline, CMDLINE_SIZE, f);
    temp = strrchr(process->cmdline, '/');
    if (temp != NULL) {
        sscanf(++temp, "%255s", process->name);
    }
    fclose(f);

    snprintf(path, MAX_PATH_SIZE, PROC_PATH "%d/stat", pid);
    f = fopen(path, "r");
    if (f == NULL) {
        printf("Could not open file %s", path);
        exit(EXIT_FAILURE);
    }

    // parse the stat file to get other process information
    fgets(buf, MAX_PATH_SIZE, f);
    char *str = buf, *end;

    // read the PID
    process->pid = strtol(str, &end, 10);

    // skip to the process name
    str = end + 2;
    while (*str != '(') {
        ++str;
    }
    ++str;

    // read the PPID
    int i = 0;
    process->ppid = -1;
    while (*str != ')') {
        if (isdigit(*str)) {
            buf[i++] = *str;
        } else if (i > 0) {
            buf[i] = '\0';
            process->ppid = strtol(buf, NULL, 10);
            break;
        }
        ++str;
    }

    // skip unused fields
    for (i = 0; i < 3; ++i) {
        while (*str != ' ') {
            ++str;
        }
        ++str;
    }

    // read the number of threads
    process->num_threads = strtol(str, &end, 10);

    // skip unused fields
    for (i = 0; i < 2; ++i) {
        while (*end != ' ') {
            ++end;
        }
        ++end;
    }

    // read the virtual memory size
    process->vmsize = strtol(end, NULL, 10);

    fclose(f);
}

void list_processes() {
    DIR *proc_dir = opendir(PROC_PATH);
    struct dirent *entry;
    while ((entry = readdir(proc_dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            int pid = strtol(entry->d_name, NULL, 10);
            if (pid > 0) {
                process_t process;
                read_process_info(pid, &process);
                print_process_info(&process);
            }
        }
    }
    closedir(proc_dir);
}

int main() {
    list_processes();
    return 0;
}