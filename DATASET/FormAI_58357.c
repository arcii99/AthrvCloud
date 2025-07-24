//FormAI DATASET v1.0 Category: File system simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_COUNT 100

struct file {
    char file_name[MAX_FILENAME_LENGTH];
    int file_size;
    int file_index;
};

struct directory {
    char dir_name[MAX_FILENAME_LENGTH];
    struct file files[MAX_FILE_COUNT];
    int file_count;
};

struct filesystem {
    struct directory root;
    struct directory current_dir;
};

struct filesystem* create_filesystem() {
    struct filesystem* fs = malloc(sizeof(struct filesystem));
    strcpy(fs->root.dir_name, "/");
    fs->root.file_count = 0;
    fs->current_dir = fs->root;
    return fs;
}

int get_file_index(struct filesystem* fs, char* name) {
    for(int i=0; i<fs->current_dir.file_count; i++) {
        if(strcmp(fs->current_dir.files[i].file_name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void create_file(struct filesystem* fs, char* name, int size) {
    if(fs->current_dir.file_count == MAX_FILE_COUNT) {
        printf("Error: Directory is full\n");
        return;
    }
    int index = get_file_index(fs, name);
    if(index != -1) {
        printf("Error: File already exists\n");
        return;
    }
    struct file f;
    strcpy(f.file_name, name);
    f.file_size = size;
    f.file_index = fs->current_dir.file_count;
    fs->current_dir.files[fs->current_dir.file_count++] = f;
    printf("File created successfully\n");
}

void delete_file(struct filesystem* fs, char* name) {
    int index = get_file_index(fs, name);
    if(index == -1) {
        printf("Error: File not found\n");
        return;
    }
    for(int i=index; i<fs->current_dir.file_count-1; i++) {
        fs->current_dir.files[i] = fs->current_dir.files[i+1];
        fs->current_dir.files[i].file_index = i;
    }
    fs->current_dir.file_count--;
    printf("File deleted successfully\n");
}

void rename_file(struct filesystem* fs, char* name, char* new_name) {
    int index = get_file_index(fs, name);
    if(index == -1) {
        printf("Error: File not found\n");
        return;
    }
    strcpy(fs->current_dir.files[index].file_name, new_name);
    printf("File renamed successfully\n");
}

void list_files(struct filesystem* fs) {
    printf("Directory: %s\n", fs->current_dir.dir_name);
    printf("%-4s%-20s%-14s\n", "ID", "Name", "Size");
    for(int i=0; i<fs->current_dir.file_count; i++) {
        printf("%-4d%-20s%-14d\n", fs->current_dir.files[i].file_index,
                                   fs->current_dir.files[i].file_name,
                                   fs->current_dir.files[i].file_size);
    }
}

int main() {
    struct filesystem* fs = create_filesystem();
    char command[50];
    char file_name[50];
    char new_file_name[50];
    int size;
    while(1) {
        printf("\nEnter a command (create, delete, rename, list, exit):\n");
        scanf("%s", command);
        if(strcmp("create", command) == 0) {
            printf("Enter file name:\n");
            scanf("%s", file_name);
            printf("Enter file size:\n");
            scanf("%d", &size);
            create_file(fs, file_name, size);
        }
        else if(strcmp("delete", command) == 0) {
            printf("Enter file name:\n");
            scanf("%s", file_name);
            delete_file(fs, file_name);
        }
        else if(strcmp("rename", command) == 0) {
            printf("Enter file name:\n");
            scanf("%s", file_name);
            printf("Enter new file name:\n");
            scanf("%s", new_file_name);
            rename_file(fs, file_name, new_file_name);
        }
        else if(strcmp("list", command) == 0) {
            list_files(fs);
        }
        else if(strcmp("exit", command) == 0) {
            break;
        }
        else {
            printf("Invalid command!\n");
        }
    }
    free(fs);
    return 0;
}