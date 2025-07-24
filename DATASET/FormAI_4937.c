//FormAI DATASET v1.0 Category: System process viewer ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

/* Defining constants */
#define PROC_DIRECTORY "/proc/"
#define MAX_PID_LENGTH 6

/* Function to check if a directory is a process directory or not */
int is_process(char *directory_name) {
    DIR *directory=opendir(directory_name);
    struct dirent *entry;
    int is_process=0;
    
    while((entry=readdir(directory))!=NULL) {
        /* Check if the folder contains folders named 'fd','maps' and 'cwd' */
        if(strcmp(entry->d_name,"fd")==0 || strcmp(entry->d_name,"maps")==0 || strcmp(entry->d_name,"cwd")==0) {
            is_process=1;
            break;
        }
    }
    closedir(directory);
    return is_process;
}

/* Main function */
int main() {
    DIR *directory=opendir(PROC_DIRECTORY);
    struct dirent *entry;
    char pid[MAX_PID_LENGTH];
    
    /* Loop through all directories in /proc */
    while((entry=readdir(directory))!=NULL) {
        /* Check if directory contains only digits (i.e a process folder) */
        if(entry->d_type == DT_DIR && is_process(entry->d_name)==1) {
            /* Copy the folder name (PID) to the variable pid */
            strcpy(pid,entry->d_name);
            
            /* Display information about the process */
            printf("PID: %s\n",pid);
            printf("Command Line: ");
            
            /* Create path string to read the command line file */
            char path[strlen(PROC_DIRECTORY)+strlen(pid)+14];
            snprintf(path,sizeof(path),"%s%s/cmdline",PROC_DIRECTORY,pid);
            
            /* Open the file and read its contents */
            FILE *fp=fopen(path,"r");
            if(fp!=NULL) {
                char c;
                while((c=fgetc(fp))!=EOF) {
                    putchar(c);
                }
                fclose(fp);
            }
            printf("\n\n");
        }
    }
    closedir(directory);
    return 0;
}