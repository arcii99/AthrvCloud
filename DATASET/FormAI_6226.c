//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// function to convert byte size to human-readable format
char* getReadableSize(long long int size){
    static const char *SIZES[] = {"B", "KB", "MB", "GB", "TB"};
    int len = sizeof(SIZES) / sizeof(SIZES[0]);
    int i = 0;
    double dSize = (double) size;
    for(i=0; i<len && dSize>=1024; i++, dSize/=1024);
    char *result = (char *) malloc(64);
    sprintf(result, "%.2f %s", dSize, SIZES[i]);
    return result;
}

// function to recursively loop through directory and calculate disk space
long long int getDiskSpace(char *path){
    DIR *dir;
    struct dirent *dirEntry;
    struct stat dirStat;
    long long int space = 0;
    if((dir = opendir(path)) == NULL){
        return 0;
    }
    while((dirEntry = readdir(dir)) != NULL){
        char *fullPath = (char *) malloc(strlen(path) + strlen(dirEntry->d_name) + 2);
        sprintf(fullPath, "%s/%s", path, dirEntry->d_name);
        if(stat(fullPath, &dirStat) == -1){
            space += 0;
        }
        else if(S_ISDIR(dirStat.st_mode)){
            if(strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0){
                space += 0;
            }
            else{
                long long int subSpace = getDiskSpace(fullPath);
                space += subSpace;
            }
        }
        else{
            space += dirStat.st_blocks * 512;
        }
        free(fullPath);
    }
    closedir(dir);
    return space;
}

int main(){
    char *path = "/Path/To/Directory";
    long long int space = getDiskSpace(path);
    char *readableSpace = getReadableSize(space);
    printf("Total disk space used by directory %s is %s\n", path, readableSpace);
    free(readableSpace);
    return 0;
}