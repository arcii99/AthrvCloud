//FormAI DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define program constants
#define MAX_PATH_LENGTH 100
#define MAX_FILE_SIZE 100000
#define SYNC_INTERVAL 60 // seconds

void sync_files(char* path1, char* path2) {
    char file1[MAX_PATH_LENGTH], file2[MAX_PATH_LENGTH];
    FILE *fptr1, *fptr2;
    char buffer[MAX_FILE_SIZE];
    int sync_needed = 0;

    // Construct full file paths
    sprintf(file1, "%s%s", path1, "/file.txt");
    sprintf(file2, "%s%s", path2, "/file.txt");

    // Attempt to open both files for reading
    fptr1 = fopen(file1, "r");
    fptr2 = fopen(file2, "r");

    // Check if either file could not be opened
    if (fptr1 == NULL || fptr2 == NULL) {
        printf("Error: could not open one or more files.\n");
        return;
    }

    // Read the contents of both files
    char* contents1 = fgets(buffer, MAX_FILE_SIZE, fptr1);
    char* contents2 = fgets(buffer, MAX_FILE_SIZE, fptr2);

    // Compare the contents of the files to see if they're different
    if (strcmp(contents1, contents2) != 0) {
        sync_needed = 1;
    }

    // Close the file pointers
    fclose(fptr1);
    fclose(fptr2);

    // If the files need to be synced, do so now
    if (sync_needed) {
        // Attempt to open both files for writing
        fptr1 = fopen(file1, "w");
        fptr2 = fopen(file2, "w");

        // Check if either file could not be opened
        if (fptr1 == NULL || fptr2 == NULL) {
            printf("Error: could not open one or more files.\n");
            return;
        }

        // Write the contents of the first file to the second file
        fputs(contents1, fptr2);

        // Write the contents of the second file to the first file
        fputs(contents2, fptr1);

        // Close the file pointers
        fclose(fptr1);
        fclose(fptr2);

        printf("Files synced successfully!\n");
    } else {
        printf("Files are already in sync.\n");
    }
}

int main() {
    // Define the two directories to sync
    char* path1 = "/home/user1/documents";
    char* path2 = "/home/user2/documents";

    // Continuously sync the files every 'SYNC_INTERVAL' seconds
    while (1) {
        sync_files(path1, path2);
        sleep(SYNC_INTERVAL);
    }

    return 0;
}