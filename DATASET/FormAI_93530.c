//FormAI DATASET v1.0 Category: File system simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FOLDER_DEPTH 10

typedef struct File {
    char* name;
    int size;
} File;

typedef struct Folder {
    char* name;
    int num_files;
    struct File** files;
    int num_folders;
    struct Folder** folders;
} Folder;

Folder* create_folder(char* name) {
    Folder* folder = malloc(sizeof(Folder));
    folder->name = name;
    folder->num_files = 0;
    folder->files = NULL;
    folder->num_folders = 0;
    folder->folders = NULL;
    return folder;
}

File* create_file(char* name, int size) {
    File* file = malloc(sizeof(File));
    file->name = name;
    file->size = size;
    return file;
}

void add_file_to_folder(Folder* folder, File* file) {
    folder->files = realloc(folder->files, (folder->num_files + 1) * sizeof(File*));
    folder->files[folder->num_files] = file;
    folder->num_files++;
}

void add_folder_to_folder(Folder* folder, Folder* subfolder) {
    folder->folders = realloc(folder->folders, (folder->num_folders + 1) * sizeof(Folder*));
    folder->folders[folder->num_folders] = subfolder;
    folder->num_folders++;
}

void print_folder_structure(Folder* folder, int depth) {
    int i, j;
    for (i = 0; i < depth; i++) printf("|   ");
    printf("|---%s/\n", folder->name);

    for (i = 0; i < folder->num_folders; i++) {
        print_folder_structure(folder->folders[i], depth+1);
    }
    for (j = 0; j < folder->num_files; j++) {
        for (i = 0; i < depth+1; i++) printf("|   ");
        printf("%s (%d bytes)\n", folder->files[j]->name, folder->files[j]->size);
    }
}

int main() {
    Folder* root = create_folder("root");
    Folder* folder1 = create_folder("folder1");
    Folder* folder2 = create_folder("folder2");

    File* file1 = create_file("file1.txt", 100);
    File* file2 = create_file("file2.txt", 200);
    File* file3 = create_file("file3.txt", 300);
    File* file4 = create_file("file4.txt", 400);

    add_file_to_folder(root, file1);
    add_folder_to_folder(root, folder1);
    add_folder_to_folder(root, folder2);
    add_file_to_folder(folder1, file2);
    add_file_to_folder(folder1, file3);
    add_file_to_folder(folder2, file4);

    printf("Folder structure:\n");
    print_folder_structure(root, 0);

    /* Cleanup */
    free(file1);
    free(file2);
    free(file3);
    free(file4);
    free(folder1);
    free(folder2);
    free(root);
    return 0;
}