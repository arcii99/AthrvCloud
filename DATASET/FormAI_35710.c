//FormAI DATASET v1.0 Category: File system simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define BLOCK_SIZE 512

typedef struct file {
    char *name;
    int size;
    char *data;
} file;

typedef struct file_system {
    file *files[MAX_FILES];
    char blocks[MAX_FILES * BLOCK_SIZE];
    int num_files;
} file_system;

void init_file_system(file_system *fs) {
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i] = NULL;
    }
    fs->num_files = 0;
    memset(fs->blocks, 0, MAX_FILES * BLOCK_SIZE);
}

file *create_file(char *name, int size) {
    file *f = malloc(sizeof(file));
    f->name = malloc(strlen(name) + 1);
    strcpy(f->name, name);
    f->size = size;
    f->data = NULL;
    return f;
}

void delete_file(file *f) {
    if (f->data) {
        free(f->data);
    }
    free(f->name);
    free(f);
}

int add_file(file_system *fs, char *name, int size) {
    if (fs->num_files >= MAX_FILES) {
        return 0;
    }
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] == NULL) {
            file *f = create_file(name, size);
            fs->files[i] = f;
            fs->num_files++;
            return 1;
        }
    }
    return 0;
}

int delete_file_by_name(file_system *fs, char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL && strcmp(fs->files[i]->name, name) == 0) {
            delete_file(fs->files[i]);
            fs->files[i] = NULL;
            fs->num_files--;
            return 1;
        }
    }
    return 0;
}

file *get_file_by_name(file_system *fs, char *name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL && strcmp(fs->files[i]->name, name) == 0) {
            return fs->files[i];
        }
    }
    return NULL;
}

void write_file_data(file_system *fs, file *f, char *data) {
    int i = 0;
    while (i < MAX_FILES * BLOCK_SIZE) {
        if (fs->blocks[i] == 0) {
            int j = i;
            int k = 0;
            int data_left = f->size;
            while (j < MAX_FILES * BLOCK_SIZE && k < f->size) {
                if (fs->blocks[j] == 0) {
                    fs->blocks[j] = data[k];
                    k++;
                    data_left--;
                }
                j++;
            }
            if (data_left == 0) {
                f->data = &fs->blocks[i];
                return;
            }
        }
        i++;
    }
}

void print_file_system(file_system *fs) {
    printf("Files in file system:\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL) {
            printf("File name: %s\n", fs->files[i]->name);
            printf("File size: %d\n", fs->files[i]->size);
            printf("File data: %s\n", fs->files[i]->data);
        }
    }
}

int main() {
    file_system fs;
    init_file_system(&fs);

    add_file(&fs, "file1", 10);
    add_file(&fs, "file2", 5);
    add_file(&fs, "file3", 8);
    print_file_system(&fs);

    file *f = get_file_by_name(&fs, "file2");
    char *data = "hello";
    write_file_data(&fs, f, data);
    printf("File data after writing: %s\n", f->data);

    delete_file_by_name(&fs, "file1");
    print_file_system(&fs);
    
    return 0;
}