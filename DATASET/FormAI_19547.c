//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

struct ProcessInfo {
    int pid;
    char pname[50];
    long int vsize;
    char state;
};

int main(){
    struct dirent *de;
    DIR *dr = opendir("/proc");

    if(dr == NULL){
        printf("Unable to open proc directory\n");
        return 0;
    }

    printf("PID\tProcess Name\tVirtual Memory Size\tProcess State\n");

    while((de = readdir(dr)) != NULL){
        if(de->d_type == DT_DIR && atoi(de->d_name) > 0){
            char fname[50];
            sprintf(fname, "/proc/%s/stat", de->d_name);
            FILE *f = fopen(fname, "r");
            if(f == NULL){
                continue;
            }
            struct ProcessInfo pi;
            fscanf(f, "%d %s %c", &pi.pid, pi.pname, &pi.state);
            fscanf(f, "%ld", &pi.vsize);
            fclose(f);
            printf("%d\t%s\t%ld kB\t\t%c\n", pi.pid, pi.pname, pi.vsize/1024, pi.state);
        }
    }
    closedir(dr);
    return 0;
}