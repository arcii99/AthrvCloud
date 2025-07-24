//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

long long int total_size=0;

void analyze_dir(char dir_name[]){
    DIR *d;
    struct dirent *dir;
    struct stat buf;
    char path[1000];
    d=opendir(dir_name);
    if(d){
        while((dir=readdir(d))!=NULL){
            if(strcmp(dir->d_name,".")!=0 && strcmp(dir->d_name,"..")!=0){
                sprintf(path,"%s/%s",dir_name,dir->d_name);
                if(stat(path,&buf)!=-1){
                    if(S_ISDIR(buf.st_mode)){
                        analyze_dir(path);
                    }
                    else{
                        total_size+=buf.st_size;
                    }
                }
            }
        }
        closedir(d);
    }
}

int main(){
    char dir_name[1000];
    printf("Enter directory path to analyze: ");
    scanf("%s",dir_name);
    analyze_dir(dir_name);
    printf("Total disk space used by the directory: %lld bytes.\n",total_size);
    return 0;
}