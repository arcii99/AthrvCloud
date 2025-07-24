//FormAI DATASET v1.0 Category: File system simulation ; Style: all-encompassing
/* This is a simple C program to simulate a simple file system */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_FILE_SIZE 100

struct file {
    char name[MAX_NAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
};

struct directory {
    char name[MAX_NAME_LENGTH];
    int num_files;
    struct file files[MAX_FILE_SIZE];
};

struct filesystem {
    int num_dir;
    struct directory dirs[MAX_FILE_SIZE];
};

struct filesystem my_fs;

void create_directory(char* name) {
    strcpy(my_fs.dirs[my_fs.num_dir].name, name);
    my_fs.dirs[my_fs.num_dir].num_files = 0;
    my_fs.num_dir++;
}

void create_file(char* name, char* data) {
    int dir_num = 0; // Assume the file is created in the first directory
    int i;
    for (i = 0; i < my_fs.num_dir; i++) {
        if (strcmp(my_fs.dirs[i].name, ".") != 0 && strcmp(my_fs.dirs[i].name, "..") != 0) {
            dir_num = i;
            break;
        }
    }

    strcpy(my_fs.dirs[dir_num].files[my_fs.dirs[dir_num].num_files].name, name);
    my_fs.dirs[dir_num].files[my_fs.dirs[dir_num].num_files].size = strlen(data);
    strcpy(my_fs.dirs[dir_num].files[my_fs.dirs[dir_num].num_files].data, data);
    my_fs.dirs[dir_num].num_files++;
}

void list_files() {
    int i, j;
    for (i = 0; i < my_fs.num_dir; i++) {
        printf("Directory: %s\n", my_fs.dirs[i].name);
        for (j = 0; j < my_fs.dirs[i].num_files; j++) {
            printf("- File: %s, Size: %d\n", my_fs.dirs[i].files[j].name, my_fs.dirs[i].files[j].size);
        }
        printf("\n");
    }
}

int main() {
    create_directory(".");
    create_directory("..");
    create_directory("documents");
    create_directory("pictures");

    create_file("resume.txt", "This is my resume.");
    create_file("selfie.jpg", "Some image data.");

    list_files();

    return 0;
}