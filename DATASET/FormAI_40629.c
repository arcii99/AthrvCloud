//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
/*
* Ada Lovelace-style C Metadata Extractor example program
*
* This program extracts metadata from a file and displays it on the screen
* It currently supports extracting file size, creation date, and file type.
* Feel free to add more metadata as needed.
*
* Author: Ada Lovelace
* Date: October 10, 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    char *filename;
    struct stat file_stats;
    int file_type;

    // Check if a filename was provided
    if (argc < 2) {
        printf("Error: No filename provided. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    // Get the filename from command line
    filename = argv[1];

    // Get the file stats
    if (stat(filename, &file_stats) < 0) {
        printf("Error: Could not get file stats. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    // Print file size
    printf("File size: %d bytes\n", (int) file_stats.st_size);

    // Print file creation date
    printf("File created on: %s", ctime(&file_stats.st_ctime));

    // Determine file type
    file_type = file_stats.st_mode & S_IFMT;

    // Print file type
    switch (file_type) {
        case S_IFBLK:
            printf("File type: Block device\n");
            break;
        case S_IFCHR:
            printf("File type: Character device\n");
            break;
        case S_IFDIR:
            printf("File type: Directory\n");
            break;
        case S_IFIFO:
            printf("File type: FIFO/pipe\n");
            break;
        case S_IFLNK:
            printf("File type: Symbolic link\n");
            break;
        case S_IFREG:
            printf("File type: Regular file\n");
            break;
        case S_IFSOCK:
            printf("File type: Socket\n");
            break;
        default:
            printf("File type: Unknown\n");
            break;
    }

    return 0;
}