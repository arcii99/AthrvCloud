//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define INTERVAL 1 // Refresh interval in seconds for monitoring

// This function reads the number of bytes from a string
long long read_bytes(char* str) {
    char* end;
    long long num = strtoll(str, &end, 10);
    switch(*end) {
        case 'G':
            num *= 1024;
        case 'M':
            num *= 1024;
        case 'K':
            num *= 1024;
    }
    return num;
}

// This function updates the process information
void update_proc(char* pid, char* mem_info[], char* stat_info[]) {
    char proc_path[100];
    snprintf(proc_path, sizeof(proc_path), "/proc/%s", pid);

    // Open the status and stat files for the process
    char status_path[100];
    snprintf(status_path, sizeof(status_path), "%s/status", proc_path);
    int status_fd = open(status_path, O_RDONLY);
    if(status_fd == -1) {
        perror("Failed to open status file");
        return;
    }

    char stat_path[100];
    snprintf(stat_path, sizeof(stat_path), "%s/stat", proc_path);
    int stat_fd = open(stat_path, O_RDONLY);
    if(stat_fd == -1) {
        perror("Failed to open stat file");
        close(status_fd);
        return;
    }

    // Read status and stat files
    char buffer[BUFFER_SIZE];
    ssize_t mem_read = read(status_fd, buffer, BUFFER_SIZE);
    if(mem_read == -1) {
        perror("Failed to read status file");
        close(status_fd);
        close(stat_fd);
        return;
    }

    int stat_read = read(stat_fd, buffer, BUFFER_SIZE);
    if(stat_read == -1) {
        perror("Failed to read stat file");
        close(status_fd);
        close(stat_fd);
        return;
    }

    // Parse status and stat files
    char delim[] = ":\n";
    char *ptr = strtok(buffer, delim);
    while(ptr != NULL) {
        if(strcmp(ptr, "VmRSS") == 0) {
            mem_info[0] = strdup(ptr); // Memory usage label
            ptr = strtok(NULL, delim);
            mem_info[1] = strdup(ptr); // Memory usage value
        }
        ptr = strtok(NULL, delim);
    }

    ptr = strtok(stat_info[1], " ");
    for(int i=0; i<22; i++) {
        if(i == 13) {
            stat_info[i] = strdup(ptr); // Sourced RSS bytes
        }
        if(i == 20) {
            stat_info[i] = strdup(ptr); // Resident RSS bytes
        }
        ptr = strtok(NULL, " ");
    }

    printf("PID: %5s | RSS: %10s | %10s\n", pid, mem_info[1], stat_info[20]);

    close(status_fd);
    close(stat_fd);
}

int main(int argc, char* argv[]) {
    printf("Press CTRL+C to exit...\n");

    char *header = "PID       |    VIRTUAL |      RESIDENT\n";
    printf("%s", header);

    // Get PID from user
    if(argc != 2) {
        fprintf(stderr, "Usage: %s PID\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *pid = argv[1];
    char *mem_info[2];
    char *stat_info[22];

    // Continuously update memory usage
    while(1) {
        update_proc(pid, mem_info, stat_info);
        sleep(INTERVAL);
    }

    return EXIT_SUCCESS;
}