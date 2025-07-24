//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

//function to calculate size of the directory and sub-directories
long int calculateSize(char path[]){
    struct stat st;
    long int total_size = 0;
    DIR *dir;
    struct dirent *entry;

    dir = opendir(path);

    if(!dir){
        printf("Unable to open directory!");
        return -1;
    }
    while((entry = readdir(dir)) != NULL){
        char filePath[256];
        if(entry->d_type == DT_DIR){
            // check for directory
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
                //skip "." and ".." directories
                continue;
            }
            snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);
            total_size += calculateSize(filePath);
        } else {
            //add file to total size
            snprintf(filePath, sizeof(filePath), "%s/%s", path, entry->d_name);
            stat(filePath, &st);
            total_size += st.st_size;
        }
    }
    closedir(dir);
    return total_size;
}

int main(){
     char path[256];
     long double size = 0;
     printf("Enter Directory Path: ");
     scanf("%s", path);
     size = calculateSize(path);
     printf("Size of Directory: %Lf Bytes\n", size);
     return 0;
 }