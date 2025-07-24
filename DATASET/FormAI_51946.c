//FormAI DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_SIZE 100

struct file {
    char name[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    size_t size;
};

void backup(struct file current_file) {
    // Open file for writing in binary mode.
    FILE* fp = fopen(current_file.name, "wb");
    if (fp == NULL) {
        printf("Error opening file for writing\n");
        return;
    }
    // Write to file.
    fwrite(current_file.data, current_file.size, 1, fp);
    // Close file.
    fclose(fp);
}

int main() {
    struct file my_file;
    // Set file name.
    strcpy(my_file.name, "my_data.txt");
    // Set file data.
    strcpy(my_file.data, "Hello, world!");
    my_file.size = strlen(my_file.data);
    // Backup file.
    backup(my_file);
    return 0;
}