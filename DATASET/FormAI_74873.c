//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

//Function to calculate the size of a directory recursively
long long int getSize(char* path){
    DIR* dirp = opendir(path);
    struct dirent *dp;
    long long int size = 0;

    while((dp = readdir(dirp)) != NULL){
        if(dp->d_type == DT_REG){
            char *filename = dp->d_name;
            char filepath[512];
            sprintf(filepath, "%s/%s", path, filename);
            struct stat fileStat;
            if(stat(filepath, &fileStat) < 0){
                printf("Couldn't stat the file %s\n", filepath);
                continue;
            }
            size += fileStat.st_size;
        }else if(dp->d_type == DT_DIR && strcmp(dp->d_name,".")!=0 && strcmp(dp->d_name,"..")!=0){
            char subDirPath[512];
            sprintf(subDirPath, "%s/%s", path, dp->d_name);
            size += getSize(subDirPath);
        }
    }
    closedir(dirp);
    return size;
}

int main(){
    char path[512];
    printf("Enter the path to analyze\n");
    scanf("%s", path);

    long long int size = getSize(path);
    printf("Size of directory %s is %lld Bytes\n", path, size);
    return 0;
}