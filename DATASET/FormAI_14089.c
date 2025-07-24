//FormAI DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 32
#define MAX_FILE_COUNT 100

typedef struct {
    int start_block;
    int end_block;
    char name[MAX_FILENAME_LENGTH];
} File;

File files[MAX_FILE_COUNT];
int file_count = 0;

void create_file(char* name, int start_block, int end_block) {
    if (file_count >= MAX_FILE_COUNT) {
        printf("Maximum file count reached.\n");
        return;
    }
    
    File new_file;
    new_file.start_block = start_block;
    new_file.end_block = end_block;
    strcpy(new_file.name, name);
    
    files[file_count++] = new_file;
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            // Shift all files after the deleted file back one index
            for (int j = i+1; j < file_count; j++) {
                files[j-1] = files[j];
            }
            file_count--;
            return;
        }
    }
    
    printf("File %s not found.\n", name);
}

void list_files() {
    printf("%-15s%-15s%-15s\n", "Name", "Start Block", "End Block");
    for (int i = 0; i < file_count; i++) {
        printf("%-15s%-15d%-15d\n", files[i].name, files[i].start_block, files[i].end_block);
    }
}

int main() {
    create_file("file1.txt", 0, 5);
    create_file("file2.txt", 6, 8);
    create_file("file3.txt", 9, 12);
    
    list_files();
    delete_file("file2.txt");
    list_files();
    
    return 0;
}