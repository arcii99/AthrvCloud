//FormAI DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    // Check if program is being run with 2 arguments
    if (argc < 3) {
        printf("USAGE: %s FILE_PATH DIRECTORY_PATH\n", argv[0]);
        exit(1);
    }

    // Set the file path and directory path variables
    char *file_path = argv[1];
    char *dir_path = argv[2];

    // Check if the directory exists
    struct stat dir_stat;
    if (stat(dir_path, &dir_stat) < 0) {
        printf("ERROR: Directory does not exist\n");
        exit(1);
    }

    // Create the full file path by concatenating the directory path and file name
    char full_path[strlen(file_path) + strlen(dir_path) + 1];
    sprintf(full_path, "%s/%s", dir_path, file_path);

    // Create the file with 0666 permissions
    FILE *file = fopen(full_path, "w");
    if (file == NULL) {
        printf("ERROR: Could not create file\n");
        exit(1);
    }
    chmod(full_path, 0666);

    // Write some data to the file
    char data[] = "Hello, world!";
    int result = fputs(data, file);
    if (result < 0) {
        printf("ERROR: Could not write to file\n");
        exit(1);
    }

    // Close the file
    fclose(file);

    // Return success
    return 0;
}