//FormAI DATASET v1.0 Category: System administration ; Style: authentic
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void create_directory(char *dir_path) {
    // create a directory with the given path
    int status = mkdir(dir_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (status == -1) {
        // print error message and exit program if unable to create directory
        perror("Error creating directory");
        exit(EXIT_FAILURE);
    }
    printf("Directory %s created successfully\n", dir_path);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // print usage message and exit program if incorrect number of arguments provided
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *dir_path = argv[1];
    
    // check if directory already exists
    struct stat st;
    if (stat(dir_path, &st) == 0 && S_ISDIR(st.st_mode)) {
        printf("Directory %s already exists\n", dir_path);
        return 0;
    }
    
    // create directory if it doesn't exist
    create_directory(dir_path);
    
    return 0;
}