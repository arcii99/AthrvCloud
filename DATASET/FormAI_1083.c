//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>  // include the standard input and output library
#include <stdlib.h> // include the standard library
#include <sys/stat.h> // include the system stat library
#include <time.h>      // include the time library

int main(){
    // welcome message
    printf("Welcome to the C Metadata Extractor program!\n\n");

    // prompt the user to enter the file path
    printf("Please enter the file path: ");
    char file_path[100];
    scanf("%s", file_path);

    // create a struct for the file stats
    struct stat file_stats;

    // check if the file exists
    if(stat(file_path, &file_stats) == 0){
        // display file metadata
        printf("\nFile Name: %s", file_path);
        printf("\nFile Size: %ld bytes", file_stats.st_size);
        printf("\nFile Permissions: %o", file_stats.st_mode & 0777);

        // convert the time to a human-readable format using the localtime function
        char str_time[100];
        strftime(str_time, 100, "%c", localtime(&file_stats.st_mtime));

        printf("\nLast Modified: %s\n", str_time);
    } else {
        printf("Error: file not found\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}