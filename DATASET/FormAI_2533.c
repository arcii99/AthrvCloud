//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(int argc, char *argv[]) {
    if(argc != 2) { 
        fprintf(stderr, "Usage: %s mount_point\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *mount_point = argv[1];

    struct statvfs buf;
    int res = statvfs(mount_point, &buf);
    if(res != 0) { 
        fprintf(stderr, "Error: could not stat %s\n", mount_point);
        return EXIT_FAILURE;
    }

    printf("Filesystem block size: %lu\n", buf.f_bsize);
    printf("Total data blocks: %lu\n", buf.f_blocks);
    printf("Free blocks: %lu\n", buf.f_bfree);
    printf("Available blocks (non-superuser): %lu\n", buf.f_bavail);
    printf("Total inodes : %lu\n", buf.f_files);
    printf("Free inodes : %lu\n", buf.f_ffree);

    return EXIT_SUCCESS;
}