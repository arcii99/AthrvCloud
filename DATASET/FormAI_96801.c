//FormAI DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 4096
#define MAX_FILES 100

// struct for the file system
struct file_system {
    char name[20];
    int size;
    char* content;
};

// struct for the directory
struct directory {
    char name[20];
    int num_files;
    struct file_system files[MAX_FILES];
};

// struct for the file system and directory together
struct file_system_and_directory {
    struct file_system fs;
    struct directory dir;
};

// function to create a new file system
struct file_system_and_directory new_fs(char* fs_name) {
    struct file_system_and_directory fsd;
    strcpy(fsd.fs.name, fs_name);
    fsd.fs.size = 0;
    fsd.fs.content = (char*)malloc(MAX_FILE_SIZE * sizeof(char));
    fsd.dir.num_files = 0;
    return fsd;
}

// function to create a new file and add it to the directory
void create_file(struct directory* dir, char* filename) {
    struct file_system* file = &(dir->files[dir->num_files]);
    strcpy(file->name, filename);
    file->size = 0;
    file->content = (char*)malloc(MAX_FILE_SIZE * sizeof(char));
    dir->num_files++;
}

// function to delete a file from the directory
void delete_file(struct directory* dir, char* filename) {
    int i, pos = -1;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        free(dir->files[pos].content);
        for (i = pos + 1; i < dir->num_files; i++) {
            dir->files[i - 1] = dir->files[i];
        }
        dir->num_files--;
    }
}

// function to write to a file
void write_to_file(struct directory* dir, char* filename, char* data) {
    int i, pos = -1;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        strcpy(dir->files[pos].content, data);
        dir->files[pos].size = strlen(data);
    }
}

// function to read from a file
char* read_from_file(struct directory* dir, char* filename) {
    int i, pos = -1;
    for (i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        return dir->files[pos].content;
    } else {
        return "File not found";
    }
}

// driver function
int main() {
    struct file_system_and_directory myfs = new_fs("my_file_system");
    create_file(&(myfs.dir), "file1.txt");
    create_file(&(myfs.dir), "file2.txt");
    write_to_file(&(myfs.dir), "file1.txt", "This is file 1");
    write_to_file(&(myfs.dir), "file2.txt", "This is file 2");
    printf("%s\n", read_from_file(&(myfs.dir), "file1.txt"));
    printf("%s\n", read_from_file(&(myfs.dir), "file2.txt"));
    delete_file(&(myfs.dir), "file1.txt");
    printf("%s\n", read_from_file(&(myfs.dir), "file1.txt"));
    printf("%d\n", myfs.dir.num_files);
    return 0;
}