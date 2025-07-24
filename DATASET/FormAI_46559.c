//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/* Declare our constant for the maximum number of characters in a filename */
#define MAX_FILENAME_LENGTH 256

int main(int argc, char **argv) {
    /* Declare our variables */
    char filename[MAX_FILENAME_LENGTH];
    struct stat file_info;
    
    /* Check the number of arguments */
    if (argc < 2) {
        printf("Please specify a file to get metadata about.\n");
        return 1;
    }
    
    /* Get the filename from the first argument */
    strcpy(filename, argv[1]);
    
    /* Use the stat function to get information about the file */
    if (stat(filename, &file_info) != 0) {
        printf("Failed to get metadata for %s\n", filename);
        return 1;
    }
    
    /* Print out information about the file */
    printf("Metadata for %s:\n", filename);
    printf("Size: %ld bytes\n", file_info.st_size);
    printf("Permissions: %o\n", file_info.st_mode & 0777);
    printf("Owner: %d\n", file_info.st_uid);
    printf("Group: %d\n", file_info.st_gid);
    printf("Last modified: %s", ctime(&file_info.st_mtime));
    
    return 0;
}