//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1000

struct file {
    char name[50];
    char content[MAX_FILE_SIZE];
};

struct directory {
    char name[50];
    struct file files[MAX_FILES];
    int num_files;
};

struct filesystem {
    struct directory root;
};

int create_file(struct directory *dir, char *name) {
    if (dir->num_files == MAX_FILES) {
        printf("Directory is full\n");
        return -1;
    }
    struct file new_file;
    strcpy(new_file.name, name);
    dir->files[dir->num_files++] = new_file;
    return 0;
}

int delete_file(struct directory *dir, char *name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            for (int j = i; j < dir->num_files; j++) {
                dir->files[j] = dir->files[j+1];
            }
            dir->num_files--;
            return 0;
        }
    }
    printf("File not found\n");
    return -1;
}

int write_file(struct directory *dir, char *name, char *content) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            strcpy(dir->files[i].content, content);
            return 0;
        }
    }
    printf("File not found\n");
    return -1;
}

void print_file(struct directory *dir, char *name) {
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            printf("File name: %s\n", dir->files[i].name);
            printf("File content: %s\n", dir->files[i].content);
            return;
        }
    }
    printf("File not found\n");
}

int main() {
    struct filesystem fs;
    strcpy(fs.root.name, "root");
    fs.root.num_files = 0;

    create_file(&fs.root, "file1.txt");
    write_file(&fs.root, "file1.txt", "Hello world!");
    print_file(&fs.root, "file1.txt");

    delete_file(&fs.root, "file1.txt");
    print_file(&fs.root, "file1.txt");

    return 0;
}