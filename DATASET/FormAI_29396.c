//FormAI DATASET v1.0 Category: File system simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 20
#define MAX_FILE_SIZE 1024

struct File {
    char name[MAX_FILE_NAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
};

struct File_System {
    struct File files[10];
    int num_files;
};

void init_file_system(struct File_System *fs) {
    fs->num_files = 0;
}

void create_file(struct File_System *fs, char *name, char *data, int size) {
    if (fs->num_files == 10) {
        printf("Maximum number of files reached\n");
        return;
    }
    struct File *f = &fs->files[fs->num_files++];
    strcpy(f->name, name);
    f->size = size;
    strncpy(f->data, data, size);
}

void delete_file(struct File_System *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->num_files--;
            fs->files[i] = fs->files[fs->num_files];
            printf("File %s deleted\n", name);
            return;
        }
    }
    printf("File %s not found\n", name);
}

void print_file_system(struct File_System *fs) {
    printf("File system contents:\n");
    int i;
    for (i = 0; i < fs->num_files; i++) {
        struct File *f = &fs->files[i];
        printf("File %s size %d contents %.*s\n", f->name, f->size, f->size, f->data);
    }
}

int main() {
    struct File_System fs;
    init_file_system(&fs);
    
    create_file(&fs, "file1.txt", "This is file 1", 14);
    create_file(&fs, "file2.txt", "This is file 2", 14);
    create_file(&fs, "file3.txt", "This is file 3", 14);
    print_file_system(&fs);
    
    delete_file(&fs, "file2.txt");
    print_file_system(&fs);
    
    return 0;
}