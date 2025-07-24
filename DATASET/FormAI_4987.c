//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

//Function to print the process info
void printProcessInfo(char* pid) {
    char path[50];
    FILE* stat_file;
    char field[32];
    int value;

    //Read process stat file
    sprintf(path, "/proc/%s/stat", pid);
    stat_file = fopen(path, "r");
    if (stat_file == NULL)
        return;

    //Skip first two fields (pid and comm)
    fscanf(stat_file, "%s %s", field, field);
    
    //Print other fields
    while (fscanf(stat_file, "%s", field) != EOF) {
        if (strcmp(field, "rss") == 0) {
            //RSS is in KB, convert to MB
            fscanf(stat_file, "%d", &value);
            printf("    Resident Set Size: %d MB\n", value / 1024);
        } else if (strcmp(field, "state") == 0) {
            fscanf(stat_file, "%s", field);
            printf("    State: %s\n", field);
        } else if (strcmp(field, "utime") == 0) {
            fscanf(stat_file, "%d", &value);
            printf("    User CPU Time: %d\n", value);
        } else if (strcmp(field, "stime") == 0) {
            fscanf(stat_file, "%d", &value);
            printf("    System CPU Time: %d\n", value);
        }
    }

    fclose(stat_file);
}

//Recursive function to print process hierarchy
void printProcessHierarchy(char* pid, int depth) {
    char path[50], cmd[50], comm[50], state;
    DIR* dir;
    struct dirent* ent;

    //Print process info
    printf("%*s", depth*4, ""); //Indentation
    printf("PID: %s\n", pid);
    sprintf(path, "/proc/%s/cmdline", pid); //Get command line of process
    FILE* cmd_file = fopen(path, "r");
    if (cmd_file != NULL) {
        fgets(cmd, sizeof(cmd), cmd_file);
        printf("%*s    Command: %s\n", depth*4, "", cmd);        
        fclose(cmd_file);
    }
    sprintf(path, "/proc/%s/comm", pid); //Get process name
    FILE* comm_file = fopen(path, "r");
    if (comm_file != NULL) {
        fgets(comm, sizeof(comm), comm_file);
        printf("%*s    Process Name: %s", depth*4, "", comm);
        fclose(comm_file);
    }
    printProcessInfo(pid);

    //Recursively print children
    sprintf(path, "/proc/%s/task", pid);
    dir = opendir(path);
    if (dir == NULL)
        return;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_name[0] != '.') { //Ignore hidden files/folders
            //Get the child process PID
            pid_t child_pid = strtol(ent->d_name, NULL, 10);
            if (child_pid != strtol(pid, NULL, 10)) { //Ignore self
                sprintf(path, "%d", child_pid);
                printProcessHierarchy(path, depth+1);
            }
        }
    }
    closedir(dir);
}

//Main function
int main() {
    printf("Process Hierarchy:\n");

    //Start with root process (pid=1)
    printProcessHierarchy("1", 0);

    return 0;
}