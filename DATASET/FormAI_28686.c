//FormAI DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

typedef struct {
    char pid[MAX_LEN];
    char pname[MAX_LEN];
    char status[MAX_LEN];
    char mem[MAX_LEN];
    char cmd[MAX_LEN];
} Process;

void parse_stat_file(char *pid, char *pname, char *status, char *mem) {
    char stat_filepath[MAX_LEN];
    sprintf(stat_filepath, "/proc/%s/stat", pid);
    
    FILE *fp = fopen(stat_filepath, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", stat_filepath);
        return;
    }
    
    fscanf(fp, "%s %s %s %s", pid, pname, status, mem);
    
    fclose(fp);
}

void parse_cmd_file(char *pid, char *cmd) {
    char cmd_filepath[MAX_LEN];
    sprintf(cmd_filepath, "/proc/%s/cmdline", pid);
    
    FILE *fp = fopen(cmd_filepath, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", cmd_filepath);
        return;
    }
    
    fgets(cmd, MAX_LEN, fp);
    trim_newline(cmd);
    
    fclose(fp);
}

void trim_newline(char *str) {
    int len = strlen(str);
    
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}

int is_digit(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    DIR *dir;
    struct dirent *ent;
    
    Process processes[MAX_LEN];
    memset(processes, 0, sizeof(processes));
    
    int i = 0;
    
    if ((dir = opendir("/proc")) != NULL) {
        while ((ent = readdir(dir)) != NULL && i < MAX_LEN) {
            char *pid = ent->d_name;
            
            if (is_digit(pid)) {
                parse_stat_file(pid, processes[i].pname, processes[i].status, processes[i].mem);
                parse_cmd_file(pid, processes[i].cmd);
                strncpy(processes[i].pid, pid, MAX_LEN);
                
                i++;
            }
        }
        
        closedir(dir);
    }
    
    printf("%5s %15s %10s %10s %s\n", "PID", "Name", "Status", "Memory", "Command");
    printf("--------------------------------------------------------------\n");
    
    int j;
    for (j = 0; j < i; j++) {
        printf("%5s %15s %10s %10s %s\n", processes[j].pid, processes[j].pname, 
               processes[j].status, processes[j].mem, processes[j].cmd);
    }
    
    return 0;
}