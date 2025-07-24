//FormAI DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_NAME 50

struct file {
    char name[MAX_NAME];
    int size;
};

struct file_system {
    struct file files[MAX_FILES];
    int num_files;
};

void create_file(struct file_system *fs, char *name, int size) {
    if (fs->num_files >= MAX_FILES) {
        printf("Error: file system is full\n");
        return;
    }
    struct file new_file;
    strcpy(new_file.name, name);
    new_file.size = size;
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
    printf("File %s (size %d) created successfully\n", name, size);
}

void delete_file(struct file_system *fs, char *name) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            // shift all files down one index
            int j;
            for (j = i; j < fs->num_files-1; j++) {
                fs->files[j] = fs->files[j+1];
            }
            fs->num_files--;
            printf("File %s deleted successfully\n", name);
            return;
        }
    }
    printf("Error: file %s not found\n", name);
}

void list_files(struct file_system *fs) {
    printf("File system contains %d files:\n", fs->num_files);
    int i;
    for (i = 0; i < fs->num_files; i++) {
        printf("- %s (size %d)\n", fs->files[i].name, fs->files[i].size);
    }
}

int main() {
    struct file_system fs;
    fs.num_files = 0;

    create_file(&fs, "file1", 100);
    create_file(&fs, "file2", 50);
    list_files(&fs);

    delete_file(&fs, "file1");
    list_files(&fs);
    
    return 0;
}