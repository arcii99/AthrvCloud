//FormAI DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LEN 20
#define MAX_FILE_SIZE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int size;
    char data[MAX_FILE_SIZE];
} File;

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int size;
    int num_files;
    File files[MAX_FILES];
} Directory;

int num_dirs = 0;
Directory dirs[MAX_FILES];

void print_dir(Directory dir) {
    printf("Directory ID: %d\n", dir.id);
    printf("Directory Name: %s\n", dir.name);
    printf("Directory Size: %d bytes\n", dir.size);
    printf("Number of Files: %d\n", dir.num_files);
    printf("Files:\n");
    for (int i = 0; i < dir.num_files; i++) {
        printf("File Name: %s\n", dir.files[i].name);
        printf("File Size: %d bytes\n", dir.files[i].size);
        printf("File Data: %s\n", dir.files[i].data);
    }
}

void create_dir(char name[MAX_NAME_LEN]) {
    Directory dir;
    dir.id = num_dirs;
    strcpy(dir.name, name);
    dir.size = 0;
    dir.num_files = 0;
    dirs[num_dirs++] = dir;
    printf("Directory Created Successfully!\n");
}

void create_file(int dir_id, char name[MAX_NAME_LEN], char data[MAX_FILE_SIZE]) {
    Directory dir = dirs[dir_id];
    if (dir.num_files == MAX_FILES) {
        printf("Directory is Full. Failed to Create File.\n");
        return;
    }
    int size = strlen(data);
    if (dir.size + size > MAX_FILE_SIZE) {
        printf("Directory is Full. Failed to Create File.\n");
        return;
    }
    File file;
    strcpy(file.name, name);
    file.size = size;
    strcpy(file.data, data);
    dir.files[dir.num_files++] = file;
    dir.size += size;
    dirs[dir_id] = dir;
    printf("File Created Successfully!\n");
}

void delete_file(int dir_id, char name[MAX_NAME_LEN]) {
    Directory dir = dirs[dir_id];
    for (int i = 0; i < dir.num_files; i++) {
        if (strcmp(dir.files[i].name, name) == 0) {
            dir.size -= dir.files[i].size;
            for (int j = i; j < dir.num_files - 1; j++) {
                dir.files[j] = dir.files[j+1];
            }
            dir.num_files--;
            dirs[dir_id] = dir;
            printf("File Deleted Successfully!\n");
            return;
        }
    }
    printf("File Not Found. Failed to Delete File.\n");
}

void delete_dir(int dir_id) {
    Directory dir = dirs[dir_id];
    printf("Deleting Directory %s...\n", dir.name);
    for (int i = 0; i < dir.num_files; i++) {
        printf("Deleting File %s...\n", dir.files[i].name);
    }
    for (int i = dir_id; i < num_dirs - 1; i++) {
        dirs[i] = dirs[i+1];
    }
    num_dirs--;
    printf("Directory Deleted Successfully!\n");
}

int main() {
    create_dir("Documents");
    create_file(0, "resume", "I am a chatbot.");
    create_file(0, "essay", "Lorem Ipsum is simply dummy text of the printing and typesetting industry.");
    print_dir(dirs[0]);
    delete_file(0, "essay");
    print_dir(dirs[0]);
    delete_dir(0);
    return 0;
}