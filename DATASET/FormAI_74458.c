//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<sys/statvfs.h>
#include<time.h>

int main(int argc, char** argv){
    struct statvfs vfs;
    struct tm *dt;
    time_t t;

    if(argc != 2) {
        printf("Usage: %s <Path>\n", argv[0]);
        exit(1);
    }

    if(statvfs(argv[1], &vfs) != 0) {
        perror("statvfs");
        exit(1);
    }

    t = time(NULL);
    dt = localtime(&t);

    printf("Disk space information for %s at %d:%d:%d on %d/%d/%d:\n", argv[1],
           dt->tm_hour, dt->tm_min, dt->tm_sec, dt->tm_mday, dt->tm_mon+1, dt->tm_year+1900);

    printf("Total disk space: %ld bytes\n", vfs.f_frsize * vfs.f_blocks);
    printf("Free disk space : %ld bytes (%f%%)\n", vfs.f_frsize * vfs.f_bfree, ((float) vfs.f_bfree) / vfs.f_blocks * 100);
    printf("Total inodes    : %ld\n", vfs.f_files);
    printf("Free inodes     : %ld (%f%%)\n", vfs.f_ffree, ((float) vfs.f_ffree) / vfs.f_files * 100);

    return 0;
}