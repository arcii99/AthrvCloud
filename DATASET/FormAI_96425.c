//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

void visit(char *path, long long int *total_size){
    DIR *dir; 
    struct dirent *entry;
    struct stat info;
    dir=opendir(path);
    while((entry=readdir(dir))!=NULL){
        char newpath[1024];
        strcpy(newpath,path);
        strcat(newpath,"/");
        strcat(newpath,entry->d_name);
        if(stat(newpath,&info)==0){
            if(info.st_mode & S_IFDIR){
                if(strcmp(entry->d_name,".")!=0 && strcmp(entry->d_name,"..")!=0){
                    visit(newpath,total_size);
                }
            }
            else{
                *total_size+=info.st_size;
            }
        }
    }
    closedir(dir);
}

int main(){
    char path[1024];
    printf("Enter the directory path: ");
    scanf("%s",path);
    long long int total_size=0;
    printf("Analyzing disk space...\n");
    visit(path,&total_size);
    printf("Total size of %s directory: %lld bytes\n",path,total_size);
    return 0;
}