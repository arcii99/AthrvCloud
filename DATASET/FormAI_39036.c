//FormAI DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    // Check for correct usage
    if(argc != 3) {
        printf("Usage: %s [directory] [file extension]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the directory and check for errors
    DIR *dir = opendir(argv[1]);
    if(!dir) {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    // Loop through all files in the directory
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {

        // Check if the file extension matches
        if(strstr(entry->d_name, argv[2]) != NULL) {

            // Construct the filepath
            char filepath[256];
            strcpy(filepath, argv[1]);
            strcat(filepath, "/");
            strcat(filepath, entry->d_name);

            // Delete the file and check for errors
            if(unlink(filepath) != 0) {
                perror("Error deleting file");
                exit(EXIT_FAILURE);
            }

            printf("Deleted file: %s\n", filepath);
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}