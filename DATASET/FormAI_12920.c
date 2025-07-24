//FormAI DATASET v1.0 Category: Data recovery tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure of a file
typedef struct file {
    char* name;     // File name
    int size;       // File size in bytes
    struct file* sub_files; // Array of sub-files
    int num_sub_files;      // Number of sub-files
} file_t;

// Recursive function to traverse and recover data from filesystem
void recover_data(file_t* file, char* recovered_data) {
    // Check if file is a directory
    if (strcmp(file->name, "dir") == 0) {
        // Traverse all sub-files recursively
        for (int i = 0; i < file->num_sub_files; i++) {
            recover_data(&file->sub_files[i], recovered_data);
        }
    } else {
        // File is not a directory, add its data to recovered_data
        strcat(recovered_data, file->name);
    }
}

int main() {
    // Constructing the filesystem for demonstration purposes
    file_t root = {"dir", 0, NULL, 2};
    file_t sub1 = {"file1", 10, NULL, 0};
    file_t sub2 = {"dir", 0, (file_t[]) {{"file2", 5, NULL, 0}, {"file3", 3, NULL, 0}}, 2};
    root.sub_files = (file_t[]) {sub1, sub2};

    // Recovering data from the filesystem recursively
    char* recovered_data = malloc(sizeof(char) * 100);
    recover_data(&root, recovered_data);

    // Printing recovered data
    printf("Recovered data: %s\n", recovered_data);

    free(recovered_data);
    return 0;
}