//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: peaceful
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: metadata_extractor <filename>\n");
        return 1;
    }

    char *filename = argv[1];

    struct stat metadata;
    if (stat(filename, &metadata) == -1) {
        printf("Error: could not retrieve metadata for %s\n", filename);
        return 2;
    }

    printf("File name: %s\n", filename);
    printf("File size: %lld bytes\n", metadata.st_size);
    printf("File permissions: %o\n", metadata.st_mode & 0777);
    printf("Owner ID: %d\n", metadata.st_uid);
    printf("Group ID: %d\n", metadata.st_gid);
    printf("Last access time: %s", ctime(&metadata.st_atime));
    printf("Last modification time: %s", ctime(&metadata.st_mtime));
    printf("Last status change time: %s", ctime(&metadata.st_ctime));

    return 0;
}