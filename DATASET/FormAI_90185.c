//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(){
    struct statvfs vfs;
    char path[100];
    printf("Enter the path of the directory to analyze: ");
    scanf("%s", path);
    
    if(statvfs(path, &vfs) != -1){
        long total = (long)vfs.f_frsize * (long)vfs.f_blocks;
        long available = (long)vfs.f_frsize * (long)vfs.f_bavail;
        long used = total - available;
        
        printf("Total space in %s: %ld bytes\n", path, total);
        printf("Used space in %s: %ld bytes\n", path, used);
        printf("Available space in %s: %ld bytes\n", path, available);
    }
    else{
        perror("statvfs");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}