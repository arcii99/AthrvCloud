//FormAI DATASET v1.0 Category: File Synchronizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int copyfile(const char *f1, const char *f2) {
    int fd1, fd2, n; 
    char buf[BUF_SIZE];
    
    fd1 = open(f1, O_RDONLY); 
    if(fd1 == -1){
        perror("Error opening source file\n");
        return -1;
    }
    
    fd2 = open(f2, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);
    if(fd2 == -1) {
        perror("Error opening destination file\n");
        close(fd1);
        return -1;
    }
    
    while( (n = read(fd1, buf, BUF_SIZE)) > 0){
        if(write(fd2, buf, n) != n){
            perror("Error writing to destination file\n");
            close(fd1);
            close(fd2);
            return -1;
        }
    }
    
    if(n == -1){
        perror("Error reading from source file\n");
        close(fd1);
        close(fd2);
        return -1;
    }
    
    if(close(fd1) == -1){
        perror("Error closing source file\n");
        return -1;
    }
    
    if(close(fd2) == -1){
        perror("Error closing destination file\n");
        return -1;
    }
    
    return 0;
}

int sync_files(const char *dir1, const char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *dirp1, *dirp2;
    struct stat st1, st2;
    char s1[BUF_SIZE], s2[BUF_SIZE];
    
    if ((dp1 = opendir(dir1)) == NULL) {
        perror("Error opening source directory\n");
        return -1;
    }
    if ((dp2 = opendir(dir2)) == NULL) {
        perror("Error opening destination directory\n");
        closedir(dp1);
        return -1;
    }
    
    while ((dirp1 = readdir(dp1)) != NULL) {   
        sprintf(s1, "%s/%s", dir1, dirp1->d_name);
        sprintf(s2, "%s/%s", dir2, dirp1->d_name);
        if (stat(s1, &st1) == -1 || S_ISDIR(st1.st_mode)) {
            continue;     
        }
        if (stat(s2, &st2) == -1) {          
            copyfile(s1, s2); 
            printf("File \"%s\" copied from source directory to destination directory\n", dirp1->d_name);
        } 
        else {                 
            if (st1.st_mtime > st2.st_mtime) {  
                copyfile(s1, s2);
                printf("File \"%s\" updated in destination directory\n", dirp1->d_name);
            }
        }
    }
    
    while ((dirp2 = readdir(dp2)) != NULL) {   
        sprintf(s1, "%s/%s", dir2, dirp2->d_name);
        sprintf(s2, "%s/%s", dir1, dirp2->d_name);
        if (stat(s1, &st1) == -1 || S_ISDIR(st1.st_mode)) {
            continue;     
        }
        if (stat(s2, &st2) == -1) {          
            copyfile(s1, s2); 
            printf("File \"%s\" copied from destination directory to source directory\n", dirp2->d_name);
        } 
    }

    printf("Sync successful!\n");

    closedir(dp1);
    closedir(dp2);
    
    return 0;
}

int main(int argc, char *argv[]) { 
    
    if(argc != 3){
        printf("Usage: synchronizer [Source folder path] [Destination folder path]\n");
        return -1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}