//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFSIZE 1024

void read_file_metadata(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        printf("Error getting file metadata for %s\n", filename);
        exit(1);
    }

    printf("Metadata for file %s:\n", filename);
    printf("\tFile size: %lld bytes\n", (long long)st.st_size);
    printf("\tPermissions: %o\n", st.st_mode & 0777);
    printf("\tOwner UID: %d\n", st.st_uid);
    printf("\tLast access time: %ld\n", st.st_atime);
    printf("\tLast modification time: %ld\n", st.st_mtime);
    printf("\tFile type: ");

    if (S_ISREG(st.st_mode)) {
        printf("Regular File\n");
        /* Add code here to extract metadata for regular files */
    } else if (S_ISDIR(st.st_mode)) {
        printf("Directory\n");
        /* Add code here to extract metadata for directories */
    } else if (S_ISLNK(st.st_mode)) {
        printf("Symbolic Link\n");
        /* Add code here to extract metadata for symbolic links */
    } else {
        printf("Unknown File Type\n");
    }

    close(fd);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_file_metadata(argv[1]);

    return 0;
}