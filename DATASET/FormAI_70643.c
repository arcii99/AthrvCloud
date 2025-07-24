//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

// Function to extract metadata from a file
void extract_metadata(const char* file_path) {
    struct stat file_stat;
    int result = stat(file_path, &file_stat);
    if (result == -1) {
        printf("Error: %s\n", strerror(errno));
        return;
    }

    printf("File Name: %s\n", file_path);
    printf("File Size: %ld bytes\n", file_stat.st_size);
    printf("Owner User ID: %u\n", file_stat.st_uid);
    printf("Owner Group ID: %u\n", file_stat.st_gid);
    printf("Last Access Time: %s", ctime(&file_stat.st_atime));
    printf("Last Modification Time: %s", ctime(&file_stat.st_mtime));
    printf("Last Status Change Time: %s", ctime(&file_stat.st_ctime));
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Please provide the file name as an argument.\n");
        return 1;
    }

    extract_metadata(argv[1]);

    return 0;
}