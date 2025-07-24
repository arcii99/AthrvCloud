//FormAI DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_LENGTH 1024

void printHeader() {
    printf("%-10s %-20s %-10s %-10s %s\n", "PID", "Name", "State", "Parent", "Memory Usage");
    printf("%-10s %-20s %-10s %-10s %s\n", "======", "====================", "======", "======", "============");
}

void printProcess(char* pid, char* name, char* state, char* parent, char* memory) {
    printf("%-10s %-20s %-10s %-10s %s\n", pid, name, state, parent, memory);
}

char* getProcName(char* pid) {
    // Open the status file of this process
    char path[MAX_LENGTH];
    sprintf(path, "/proc/%s/status", pid);
    FILE* file = fopen(path, "r");

    // Read the file and look for the name in the first few lines
    char* line = NULL;
    size_t len = 0;
    char* name = NULL;
    while (getline(&line, &len, file) != -1) {
        if (strncmp(line, "Name:", 5) == 0) {
            name = malloc(strlen(line) - 5);
            strcpy(name, &line[6]);
            name[strlen(name) - 1] = '\0'; // Remove newline character
            break;
        }
    }
    fclose(file);
    free(line);
    return name;
}

char* getProcState(char* pid) {
    // Open the status file of this process
    char path[MAX_LENGTH];
    sprintf(path, "/proc/%s/status", pid);
    FILE* file = fopen(path, "r");

    // Read the file and look for the state in the first few lines
    char* line = NULL;
    size_t len = 0;
    char* state = NULL;
    while (getline(&line, &len, file) != -1) {
        if (strncmp(line, "State:", 6) == 0) {
            state = malloc(2);
            strcpy(state, &line[7]);
            break;
        }
    }
    fclose(file);
    free(line);
    return state;
}

char* getProcParent(char* pid) {
    // Open the status file of this process
    char path[MAX_LENGTH];
    sprintf(path, "/proc/%s/status", pid);
    FILE* file = fopen(path, "r");

    // Read the file and look for the PPid in the first few lines
    char* line = NULL;
    size_t len = 0;
    char* parent = NULL;
    while (getline(&line, &len, file) != -1) {
        if (strncmp(line, "PPid:", 5) == 0) {
            parent = malloc(strlen(line) - 5);
            strcpy(parent, &line[6]);
            parent[strlen(parent) - 1] = '\0'; // Remove newline character
            break;
        }
    }
    fclose(file);
    free(line);
    return parent;
}

char* getProcMemory(char* pid) {
    // Open the statm file of this process
    char path[MAX_LENGTH];
    sprintf(path, "/proc/%s/statm", pid);
    FILE* file = fopen(path, "r");

    // Read the first line of the file which contains the memory usage
    char* line = NULL;
    size_t len = 0;
    getline(&line, &len, file);
    char* token = strtok(line, " ");
    char* memory = malloc(strlen(token) + 4);
    sprintf(memory, "%s KB", token);

    fclose(file);
    free(line);
    return memory;
}

void printProcesses() {
    // Open the /proc directory
    DIR* proc_dir = opendir("/proc");

    // Loop through all the directories in /proc and check if they are processes
    struct dirent* dir_entry;
    while ((dir_entry = readdir(proc_dir)) != NULL) {
        if (dir_entry->d_type == DT_DIR) {
            char* name = dir_entry->d_name;

            // Check if the directory name is a number (i.e. a PID)
            int is_pid = 1;
            for (int i = 0; i < strlen(name); i++) {
                if (name[i] < '0' || name[i] > '9') {
                    is_pid = 0;
                    break;
                }
            }
            if (is_pid) {
                char* pid = name;
                char* state = getProcState(pid);
                char* parent = getProcParent(pid);
                char* name = getProcName(pid);
                char* memory = getProcMemory(pid);

                // Print the process info
                printProcess(pid, name, state, parent, memory);
                free(state);
                free(parent);
                free(name);
                free(memory);
            }
        }
    }
    closedir(proc_dir);
}

int main() {
    printHeader();
    printProcesses();
    return 0;
}