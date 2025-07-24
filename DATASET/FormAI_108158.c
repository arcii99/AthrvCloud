//FormAI DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>

#define PROC_DIRECTORY "/proc"
#define MAX_PID_LEN 6

typedef struct {
    pid_t pid;
    uid_t uid;
    char state;
    unsigned long long utime;
    unsigned long long stime;
    char cmdline[256];
} Process;

void print_process_info(Process proc) {
    printf("%-6d %-6d %-6c %8llu %8llu %s\n", proc.pid, proc.uid, proc.state, proc.utime, proc.stime, proc.cmdline);
}

unsigned long long get_process_time(int pid, char* time_str) {
    char path[50];
    sprintf(path, "/proc/%d/stat", pid);
    
    FILE* stat_file = fopen(path, "r");
    if (stat_file == NULL) {
        printf("Failed to open %s for reading: %s\n", path, strerror(errno));
        return 0;
    }
    
    char* token;
    char line[256];
    fgets(line, sizeof(line), stat_file);
    fclose(stat_file);
    
    strtok(line, " ");  // Discard pid
    strtok(NULL, " ");  // Discard command string
    strtok(NULL, " ");  // Discard state
    
    token = strtok(NULL, " ");
    unsigned long long utime = strtoull(token, NULL, 10);
    
    token = strtok(NULL, " ");
    unsigned long long stime = strtoull(token, NULL, 10);
    
    if (time_str != NULL) {
        sprintf(time_str, "%llu:%llu", utime, stime);
    }
    return utime + stime;
}

Process read_process_info(int pid) {
    char path[50];
    sprintf(path, "/proc/%d/stat", pid);
    
    FILE* stat_file = fopen(path, "r");
    if (stat_file == NULL) {
        printf("Failed to open %s for reading: %s\n", path, strerror(errno));
        Process proc = {0};
        return proc;
    }
    
    Process proc;
    proc.pid = pid;
    
    char* token;
    char line[256];
    fgets(line, sizeof(line), stat_file);
    fclose(stat_file);
    
    // Parses contents of stat file
    token = strtok(line, " ");
    strtok(NULL, " ");  // Discard command string
    proc.state = strtok(NULL, " ")[0];
    
    token = strtok(NULL, " ");
    proc.utime = strtoull(token, NULL, 10);
    
    token = strtok(NULL, " ");
    proc.stime = strtoull(token, NULL, 10);
    
    // Read command line into cmdline array
    sprintf(path, "/proc/%d/cmdline", pid);
    FILE* cmdline_file = fopen(path, "r");
    if (cmdline_file == NULL) {
        printf("Failed to open %s for reading: %s\n", path, strerror(errno));
        strcpy(proc.cmdline, "?");
    } else {
        fgets(proc.cmdline, sizeof(proc.cmdline), cmdline_file);
        fclose(cmdline_file);
    }
    
    // Get user ID of process owner
    sprintf(path, "/proc/%d/status", pid);
    FILE* status_file = fopen(path, "r");
    if (status_file == NULL) {
        printf("Failed to open %s for reading: %s\n", path, strerror(errno));
        proc.uid = -1;
    } else {
        while (fgets(line, sizeof(line), status_file) != NULL) {
            if (strncmp(line, "Uid:", 4) == 0) {
                // Parse UID from line in format "Uid:    1000    1000    1000    1000"
                token = strtok(line, " \t");
                for (int i = 0; i < 3; i++) {
                    token = strtok(NULL, " \t");
                }
                proc.uid = atoi(token);
                break;
            }
        }
        fclose(status_file);
    }
    
    return proc;
}

void show_process_list() {
    printf("%-6s %-6s %-6s %8s %8s %s\n", "PID", "UID", "STATE", "UTIME", "STIME", "COMMAND");
    DIR* proc_dir;
    struct dirent* dir_entry;
    
    proc_dir = opendir(PROC_DIRECTORY);
    if (proc_dir == NULL) {
        printf("Failed to open %s: %s\n", PROC_DIRECTORY, strerror(errno));
        return;
    }
    
    while ((dir_entry = readdir(proc_dir)) != NULL) {
        if (isdigit(dir_entry->d_name[0])) {
            int pid = atoi(dir_entry->d_name);
            unsigned long long time = get_process_time(pid, NULL);
            if (time > 0) {
                Process proc = read_process_info(pid);
                print_process_info(proc);
            }
        }
    }
    closedir(proc_dir);
}

int main() {
    show_process_list();
    return 0;
}