//FormAI DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 20
#define MAX_FILE_SIZE 1024
#define MAX_NO_OF_FILES 10

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    char file_content[MAX_FILE_SIZE];
} File;

typedef struct {
    File files[MAX_NO_OF_FILES];
    int no_of_files;
} FileSystem;

FileSystem file_system;

void init_file_system() {
    file_system.no_of_files = 0;
}

void format_file_system() {
    file_system.no_of_files = 0;
    memset(&file_system.files, 0, sizeof(File) * MAX_NO_OF_FILES);
}

int create_file(char* file_name, char* file_content) {
    if(file_system.no_of_files < MAX_NO_OF_FILES) {
        File file;
        strcpy(file.file_name, file_name);
        file.file_size = strlen(file_content);
        strcpy(file.file_content, file_content);
        file_system.files[file_system.no_of_files++] = file;
        return 0;
    } else {
        return -1;
    }
}

int delete_file(char* file_name) {
    for(int i=0; i<file_system.no_of_files; i++) {
        if(strcmp(file_system.files[i].file_name, file_name) == 0) {
            file_system.files[i] = file_system.files[file_system.no_of_files - 1];
            file_system.no_of_files--;
            return 0;
        }
    }
    return -1;
}

int read_file(char* file_name, char* file_content) {
    for(int i=0; i<file_system.no_of_files; i++) {
        if(strcmp(file_system.files[i].file_name, file_name) == 0) {
            strcpy(file_content, file_system.files[i].file_content);
            return 0;
        }
    }
    return -1;
}

int update_file(char* file_name, char* file_content) {
    for(int i=0; i<file_system.no_of_files; i++) {
        if(strcmp(file_system.files[i].file_name, file_name) == 0) {
            file_system.files[i].file_size = strlen(file_content);
            strcpy(file_system.files[i].file_content, file_content);
            return 0;
        }
    }
    return -1;
}

int main() {
    init_file_system();

    create_file("file1.txt", "This is file 1 content.");
    create_file("file2.txt", "This is file 2 content.");
    create_file("file3.txt", "This is file 3 content.");

    char file_content[MAX_FILE_SIZE];

    read_file("file2.txt", file_content);
    printf("File 2 content: %s\n", file_content);

    update_file("file1.txt", "This is updated content of file 1.");

    read_file("file1.txt", file_content);
    printf("File 1 content after update: %s\n", file_content);

    delete_file("file3.txt");

    format_file_system();

    printf("File system formatted. No of files: %d\n", file_system.no_of_files);

    return 0;
}