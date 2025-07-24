//FormAI DATASET v1.0 Category: File system simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1000

struct File {
    char name[50];
    int size;
    char data[MAX_FILE_SIZE];
};

struct Directory {
    char name[50];
    struct File files[MAX_FILES];
    int num_files;
};

struct FileSystem {
    struct Directory root;
    int num_dirs;
};

void create_file(struct Directory *dir, char name[], char data[], int size) {
    if (dir->num_files == MAX_FILES) {
        printf("Directory is full! Cannot create file.\n");
    } else {
        struct File new_file;
        strcpy(new_file.name, name);
        new_file.size = size;
        strcpy(new_file.data, data);
        dir->files[dir->num_files] = new_file;
        dir->num_files++;
        printf("File %s created successfully.\n", name);
    }
}

void create_directory(struct FileSystem *fs, char name[]) {
    if (fs->num_dirs == MAX_FILES) {
        printf("File system is full! Cannot create directory.\n");
    } else {
        struct Directory new_dir;
        strcpy(new_dir.name, name);
        new_dir.num_files = 0;
        fs->root.num_files++;
        fs->root.files[fs->root.num_files-1].size = sizeof(new_dir);
        memcpy(fs->root.files[fs->root.num_files-1].data, &new_dir, sizeof(new_dir));
        fs->num_dirs++;
        printf("Directory %s created successfully.\n", name);
    }
}

void delete_file(struct Directory *dir, char name[]) {
    int index = -1;
    for (int i=0; i<dir->num_files; i++) {
        if (strcmp(dir->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("File not found in directory.\n");
    } else {
        for (int i=index; i<dir->num_files-1; i++) {
            dir->files[i] = dir->files[i+1];
        }
        dir->num_files--;
        printf("File %s deleted successfully.\n", name);
    }
}

void delete_directory(struct FileSystem *fs, char name[]) {
    int index = -1;
    for (int i=0; i<fs->num_dirs; i++) {
        if (strcmp(fs->root.files[i].data, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Directory not found in file system.\n");
    } else {
        for (int i=index; i<fs->root.num_files-1; i++) {
            fs->root.files[i] = fs->root.files[i+1];
        }
        fs->root.num_files--;
        fs->num_dirs--;
        printf("Directory %s deleted successfully.\n", name);
    }
}

int main() {
    struct FileSystem fs;
    strcpy(fs.root.name, "/");
    fs.root.num_files = 0;
    fs.num_dirs = 1;

    create_file(&fs.root, "file1.txt", "This is file 1.", strlen("This is file 1."));
    create_file(&fs.root, "file2.txt", "This is file 2.", strlen("This is file 2."));
    create_directory(&fs, "dir1");
    create_directory(&fs, "dir2");

    printf("\nFiles in root directory:\n");
    for (int i=0; i<fs.root.num_files; i++) {
        printf("%s\n", fs.root.files[i].name);
    }

    delete_file(&fs.root, "file1.txt");
    delete_file(&fs.root, "file_not_exist.txt");

    printf("\nFiles in root directory after deletion:\n");
    for (int i=0; i<fs.root.num_files; i++) {
        printf("%s\n", fs.root.files[i].name);
    }

    delete_directory(&fs, "dir1");
    delete_directory(&fs, "dir_not_exist");

    printf("\nDirectories in file system after deletion:\n");
    for (int i=0; i<fs.root.num_files; i++) {
        struct Directory dir;
        memcpy(&dir, fs.root.files[i].data, sizeof(dir));
        printf("%s\n", dir.name);
    }

    return 0;
}