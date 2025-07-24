//FormAI DATASET v1.0 Category: File system simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int size;
    char data[MAX_FILE_SIZE];
} file;

typedef struct {
    file* files;
    int num_files;
} file_system;

void add_file(file_system* fs, char* filename, char* data, int size) {
    if (fs->num_files >= MAX_FILE_SIZE) {
        printf("Error: file system is full\n");
        return;
    }

    file new_file;
    strncpy(new_file.filename, filename, MAX_FILENAME_LENGTH);
    new_file.filename[MAX_FILENAME_LENGTH-1] = 0;
    new_file.size = size;
    strncpy(new_file.data, data, size);
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
}

file* find_file(file_system* fs, char* filename) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            return &fs->files[i];
        }
    }
    return NULL;
}

void delete_file(file_system* fs, char* filename) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            for (int j = i + 1; j < fs->num_files; j++) {
                fs->files[j-1] = fs->files[j];
            }
            fs->num_files--;
            printf("File %s deleted\n", filename);
            return;
        }
    }
    printf("Error: file not found\n");
}

void print_file(file* f) {
    printf("%s (%d bytes):\n", f->filename, f->size);
    printf("%s\n", f->data);
}

void ls(file_system* fs) {
    for (int i = 0; i < fs->num_files; i++) {
        printf("%s\n", fs->files[i].filename);
    }
}

int main() {
    file_system my_files;
    my_files.num_files = 0;
    my_files.files = malloc(sizeof(file) * MAX_FILE_SIZE);

    add_file(&my_files, "hello.txt", "Hello, world!", 14);
    add_file(&my_files, "goodbye.txt", "Goodbye, world!", 16);

    printf("My Files:\n");
    ls(&my_files);

    char search_filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to find: ");
    scanf("%s", search_filename);
    file* found_file = find_file(&my_files, search_filename);
    if (found_file) {
        print_file(found_file);
    } else {
        printf("File not found\n");
    }

    char delete_filename[MAX_FILENAME_LENGTH];
    printf("Enter filename to delete: ");
    scanf("%s", delete_filename);
    delete_file(&my_files, delete_filename);

    printf("My Files:\n");
    ls(&my_files);

    free(my_files.files);

    return 0;
}