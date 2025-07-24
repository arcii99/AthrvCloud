//FormAI DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char* itoa(int num, char* str){
    if(str == NULL) return NULL;
    sprintf(str, "%d", num);
    return str;
}

int isNumber(char *str){
    int i=0;
    while(str[i] != '\0'){
        if(!isdigit(str[i])) return 0;
        ++i;
    }
    return 1;
}

int main(){
    
    struct dirent *de;
    DIR *dr;

    char *path=(char *)malloc(sizeof(char)*(MAX+1));
    char *pid=(char *)malloc(sizeof(char)*(MAX+1));
    char *line=(char *)malloc(sizeof(char)*(MAX+1));
    char *dummy=(char *)malloc(sizeof(char)*(MAX+1));

    char *proc_name=(char *)malloc(sizeof(char)*(MAX+1));
    char *state=(char *)malloc(sizeof(char)*(MAX+1));
    char *user=(char *)malloc(sizeof(char)*(MAX+1));
    char *cpu=(char *)malloc(sizeof(char)*(MAX+1));
    char *mem=(char *)malloc(sizeof(char)*(MAX+1));
    char *vm_size=(char *)malloc(sizeof(char)*(MAX+1));
    char *vm_rss=(char *)malloc(sizeof(char)*(MAX+1));

    printf("Enter the path of proc directory: ");
    scanf("%s", path);

    dr=opendir(path);
    if(dr == NULL){
        printf("Could not open directory");
        return 0;
    }
    
    printf("=========================================================================================================\n");
    printf("%10s %20s %10s %15s %15s %15s %15s \n", "PID", "Process Name", "State", "User", "CPU", "Memory", "Virtual Mem");
    printf("=========================================================================================================\n");

    while((de=readdir(dr)) != NULL){
        if(!isNumber(de->d_name)) continue;
        
        strcpy(pid, de->d_name);
        strcpy(path, "/proc/");
        strcat(path,pid);
        strcat(path,"/status");

        FILE *f=fopen(path, "r");
        if(f == NULL){
            printf("Error opening file");
            continue;
        }

        int i=0;
        while(fgets(line, MAX, f) != NULL){
            sscanf(line, "%s %s", dummy, proc_name);

            if(!strcmp(dummy, "State:")){
                sscanf(line, "%s %s", dummy, state);
            }

            else if(!strcmp(dummy, "Uid:")){
                sscanf(line, "%s %s", dummy, user);
            }

            else if(!strcmp(dummy, "VmSize:")){
                sscanf(line, "%s %s", dummy, vm_size);
            }

            else if(!strcmp(dummy, "VmRSS:")){
                sscanf(line, "%s %s", dummy, vm_rss);
            }
            
            i++;
        }

        fclose(f);

        strcpy(path, "/proc/");
        strcat(path,pid);
        strcat(path,"/stat");

        f=fopen(path, "r");
        if(f == NULL){
            printf("Error opening file");
            continue;
        }

        fgets(line, MAX, f);

        sscanf(line, "%s", dummy);
        sscanf(line, "%s", dummy);
        sscanf(line, "%s", dummy);
        sscanf(line, "%s", dummy);
        sscanf(line, "%s", dummy);
        sscanf(line, "%s", dummy);
        sscanf(line, "%s", dummy);
        sscanf(line, "%s", dummy);

        sscanf(line, "%s", dummy);
        sscanf(line, "%s", dummy);

        sscanf(line, "%s", cpu);
        sscanf(line, "%s", mem);

        fclose(f);

        printf("%10s %20s %10s %15s %15s KB %15s KB %15s KB\n", pid, proc_name, state, user, cpu, mem, vm_size);
    }

    closedir(dr);

    free(path);
    free(pid);
    free(line);
    free(dummy);
    free(proc_name);
    free(state);
    free(user);
    free(cpu);
    free(mem);
    free(vm_size);
    free(vm_rss);

    return 0;
}