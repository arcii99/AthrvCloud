//FormAI DATASET v1.0 Category: System process viewer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int main(){
    DIR* dir_path;
    struct dirent* direntry;
    char stat_file[50], proc_name[100], state;
    int pid, ppid;
    long unsigned int vm_size;

    printf("PID  PPID  STATE  VM SIZE(kB)  PROCESS NAME\n");

    dir_path = opendir("/proc/");
    while((direntry = readdir(dir_path)) != NULL){
        if(!isdigit(*direntry->d_name))
            continue;

        pid = atoi(direntry->d_name);
        sprintf(stat_file, "/proc/%d/stat", pid);
        
        FILE* procfile = fopen(stat_file,"r");

        fscanf(procfile, "%d %s %c %d", &pid, proc_name, &state, &ppid);
        fclose(procfile);

        char statm_file[50];
        sprintf(statm_file, "/proc/%d/statm", pid);
        procfile = fopen(statm_file,"r");
        
        fscanf(procfile, "%lu", &vm_size);
        fclose(procfile);

        printf("%d  %d  %c  %lu  %s\n", pid, ppid, state, vm_size, proc_name);
    }

    closedir(dir_path);
    return 0;
}