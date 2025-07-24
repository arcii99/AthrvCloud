//FormAI DATASET v1.0 Category: File system simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME_LENGTH 20
#define MAX_FILE_SIZE 1024

struct file {
    char name[MAX_NAME_LENGTH];
    int size;
    char* contents;
};

struct file file_table[MAX_FILES];
int current_num_files = 0;

int create_file(char* name, int size) {
    // Check if there is space for a new file
    if (current_num_files >= MAX_FILES) {
        printf("Cannot create file, maximum number of files reached\n");
        return -1;
    }

    // Check if file with the same name already exists
    for (int i = 0; i < current_num_files; i++) {
        if (strcmp(name, file_table[i].name) == 0) {
            printf("Cannot create file, file with the same name already exists\n");
            return -1;
        }
    }

    // Create new file
    struct file new_file;
    strncpy(new_file.name, name, MAX_NAME_LENGTH);
    new_file.size = size;
    new_file.contents = calloc(size, sizeof(char));
    file_table[current_num_files] = new_file;
    current_num_files++;

    printf("File created successfully\n");
    return 0;
}

int write_to_file(char* name, char* data, int size) {
    // Find the file with the given name
    int index = -1;
    for (int i = 0; i < current_num_files; i++) {
        if (strcmp(name, file_table[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File does not exist\n");
        return -1;
    }

    // Check if the data fits in the file
    if (size > file_table[index].size) {
        printf("Cannot write to file, data exceeds file size\n");
        return -1;
    }

    // Write data to file
    strncpy(file_table[index].contents, data, size);

    printf("Data written to file successfully\n");
    return 0;
}

int read_from_file(char* name, int size, char* buffer) {
    // Find the file with the given name
    int index = -1;
    for (int i = 0; i < current_num_files; i++) {
        if (strcmp(name, file_table[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File does not exist\n");
        return -1;
    }

    // Check if buffer is large enough to hold the data
    if (size < file_table[index].size) {
        printf("Cannot read from file, buffer size too small\n");
        return -1;
    }

    // Read data from file to buffer
    strncpy(buffer, file_table[index].contents, file_table[index].size);

    printf("Data read from file successfully\n");
    return 0;
}

int delete_file(char* name) {
    // Find the file with the given name
    int index = -1;
    for (int i = 0; i < current_num_files; i++) {
        if (strcmp(name, file_table[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File does not exist\n");
        return -1;
    }

    // Delete file
    free(file_table[index].contents);
    for (int i = index; i < current_num_files - 1; i++) {
        file_table[i] = file_table[i+1];
    }
    current_num_files--;

    printf("File deleted successfully\n");
    return 0;
}

int main() {
    // Test file system operations
    create_file("file1", MAX_FILE_SIZE / 2);
    create_file("file2", MAX_FILE_SIZE);
    char data[] = "This is some data";
    write_to_file("file1", data, strlen(data));
    char buffer[MAX_FILE_SIZE];
    read_from_file("file1", MAX_FILE_SIZE, buffer);
    printf("%s\n", buffer);
    delete_file("file2");
    delete_file("file2");
    create_file("file3", MAX_FILE_SIZE + 1);
    create_file("file4", MAX_NAME_LENGTH);

    return 0;
}