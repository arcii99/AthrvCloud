//FormAI DATASET v1.0 Category: System process viewer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/types.h>

#define PID_MAX_LEN 10
#define MAX_CMD_LEN 1024

struct ProcessInfo {
    pid_t pid;
    char cmd[MAX_CMD_LEN];
};

int getNumProcesses() {
    int fd, num_bytes;
    char buffer[PATH_MAX];
    char *ptr;
    int num_processes=-1; // exclude header
    if ((fd = open("/proc/stat", O_RDONLY)) == -1) {
        perror("Cannot open /proc/stat");
        exit(EXIT_FAILURE);
    }
    if ((num_bytes = read(fd, buffer, PATH_MAX)) == -1) {
        perror("Cannot read from /proc/stat");
        exit(EXIT_FAILURE);
    }
    close(fd);
    ptr = buffer;
    while (sscanf(ptr, "processes %d", &num_processes) != 1) {
        ptr = strchr(ptr, '\n') + 1;
    }
    return num_processes;
}

void getProcessInfo(pid_t pid, char *cmd, size_t cmd_len) {
    char filename[PATH_MAX];
    snprintf(filename, PATH_MAX, "/proc/%d/cmdline", pid);
    int fd;
    if ((fd = open(filename, O_RDONLY)) == -1) {
        perror("Cannot open cmdline file");
        exit(EXIT_FAILURE);
    }
    int num_bytes;
    if ((num_bytes = read(fd, cmd, cmd_len)) == -1) {
        perror("Cannot read from cmdline file");
        exit(EXIT_FAILURE);
    }
    close(fd);
    // replace null characters with spaces
    for (int i=0; i<num_bytes; ++i) {
        if (cmd[i] == '\0') {
            cmd[i] = ' ';
        }
    }
}

void printProcessInfo(struct ProcessInfo *p) {
    printf("%d\t%s\n", p->pid, p->cmd);
}

void *updateProcesses(void *data) {
    struct ProcessInfo *process_infos = (struct ProcessInfo *) data;
    int max_num_processes = *(int *) process_infos[0].cmd;
    while (true) {
        int num_processes = getNumProcesses();
        if (num_processes > max_num_processes) {
            fprintf(stderr, "Number of processes increased from %d to %d. Some processes might not be included.\n", max_num_processes, num_processes);
        } else if (num_processes < max_num_processes) {
            fprintf(stderr, "Number of processes decreased from %d to %d. Some processes might be duplicated.\n", max_num_processes, num_processes);
        }
        max_num_processes = num_processes;
        lseek(STDOUT_FILENO, 0, SEEK_SET);
        printf("PID\tCOMMAND\n");
        for (int i=1; i<=max_num_processes; ++i) {
            getProcessInfo(i, process_infos[i].cmd, MAX_CMD_LEN);
            if (process_infos[i].pid == 0) {
                process_infos[i].pid = i;
            }
            printProcessInfo(&process_infos[i]);
        }
        sleep(2);
    }
}

int main(int argc, char **argv) {
    int num_processes = getNumProcesses();
    printf("Starting process viewer with %d processes\n", num_processes);
    printf("PID\tCOMMAND\n");
    struct ProcessInfo process_infos[num_processes+1];
    memset(process_infos, 0, sizeof(process_infos));
    *(int *) process_infos[0].cmd = num_processes;
    pthread_t thread_id;
    if (pthread_create(&thread_id, NULL, updateProcesses, (void*) process_infos)) {
        perror("Error creating thread");
        exit(EXIT_FAILURE);
    }
    pthread_detach(thread_id);
    getchar(); // wait for user input
    return 0;
}