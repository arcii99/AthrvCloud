//FormAI DATASET v1.0 Category: File system simulation ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 10
#define FILE_NAME_LENGTH 16

typedef struct {
    char name[FILE_NAME_LENGTH];
    int size;
} file_t;

int num_files = 0;
file_t files[MAX_FILES];

void create_file(char *name, int size) {
    if (num_files < MAX_FILES) {
        strcpy(files[num_files].name, name);
        files[num_files].size = size;
        num_files++;
    }
    else {
        printf("Error: Maximum number of files reached.\n");
    }
}

void list_files() {
    printf("%-16s Size\n", "Name");
    printf("--------------------\n");
    for (int i = 0; i < num_files; i++) {
        printf("%-16s %d\n", files[i].name, files[i].size);
    }
}

int main() {
    create_file("test.txt", 1024);
    list_files();
    return 0;
}