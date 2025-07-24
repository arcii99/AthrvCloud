//FormAI DATASET v1.0 Category: File handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_CONTENT_LENGTH 200

// function to recursively write files
void write_files(char *dir_path) {
    char filename[MAX_FILENAME_LENGTH];
    char file_content[MAX_FILE_CONTENT_LENGTH];
    int file_count;

    printf("Enter the number of files you want to create in directory %s: ", dir_path);
    scanf("%d", &file_count);

    // base case: if no files to create, return
    if (file_count == 0) {
        return;
    }

    // loop through number of files to create and write each file
    for (int i = 1; i <= file_count; i++) {
        sprintf(filename, "%s/file%d.txt", dir_path, i); // generate file name
        FILE *file = fopen(filename, "w"); // create or overwrite file

        // ask user for file content and write to file
        printf("Enter the content for file %d: ", i);
        scanf(" %[^\n]*c", file_content); // read input until newline character
        fprintf(file, "%s", file_content); // write content to file
        fclose(file); // close file

        printf("File %s created successfully!\n", filename);
    }

    // recursive call to create files in subdirectories
    char sub_dir[MAX_FILENAME_LENGTH];
    printf("Do you want to create files in a subdirectory of %s? (y/n): ", dir_path);
    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Enter the name of the subdirectory you want to create in %s: ", dir_path);
        scanf(" %[^\n]*c", sub_dir);

        // create subdirectory if it doesn't exist
        char sub_dir_path[MAX_FILENAME_LENGTH];
        sprintf(sub_dir_path, "%s/%s", dir_path, sub_dir);
        if (!opendir(sub_dir_path)) {
            mkdir(sub_dir_path, 0777);
        }

        // recursive call to create files in subdirectory
        printf("Creating files in subdirectory %s...\n", sub_dir_path);
        write_files(sub_dir_path);
    } else {
        return;
    }
}

int main() {
    char dir_path[MAX_FILENAME_LENGTH];

    printf("Enter the name of the directory you want to create files in: ");
    scanf(" %[^\n]*c", dir_path);

    // create directory if it doesn't exist
    if (!opendir(dir_path)) {
        mkdir(dir_path, 0777);
    }

    printf("Creating files in directory %s...\n", dir_path);
    write_files(dir_path);

    return 0;
}