//FormAI DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILENAME 50
#define MAX_FILES 100

typedef struct file {
    char name[MAX_FILENAME];
    int size;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char* name, int size) {
    if (num_files < MAX_FILES) {
        strcpy(files[num_files].name, name);
        files[num_files].size = size;
        num_files++;
        printf("File created: %s (%d bytes)\n", name, size);
    } else {
        printf("Maximum number of files reached.\n");
    }
}

void delete_file(char* name) {
    int i;
    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0) {
            num_files--;
            files[i] = files[num_files];
            printf("File deleted: %s\n", name);
            return;
        }
    }
    printf("File not found: %s\n", name);
}

void list_files() {
    int i;
    printf("List of files:\n");
    for (i = 0; i < num_files; i++) {
        printf("- %s (%d bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    create_file("file1.txt", 100);
    create_file("file2.txt", 200);
    list_files();
    delete_file("file2.txt");
    list_files();
    return 0;
}