//FormAI DATASET v1.0 Category: File system simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_NUM_FILES 10
#define MAX_FILE_SIZE 1024

struct File {
    char name[MAX_FILENAME_LENGTH];
    int size;
    char contents[MAX_FILE_SIZE];
};

struct FileSystem {
    struct File files[MAX_NUM_FILES];
    int num_files;
    int total_size;
};

struct FileSystem create_file_system() {
    struct FileSystem fs;
    fs.num_files = 0;
    fs.total_size = 0;
    return fs;
}

void add_file(struct FileSystem *fs, char *filename, char *contents) {
    if (fs->num_files >= MAX_NUM_FILES) {
        printf("Error: maximum number of files reached\n");
        return;
    }
    struct File file;
    strcpy(file.name, filename);
    file.size = strlen(contents);
    strcpy(file.contents, contents);
    fs->files[fs->num_files] = file;
    fs->num_files += 1;
    fs->total_size += file.size;
}

void delete_file(struct FileSystem *fs, char *filename) {
    int index = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, filename) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: file not found\n");
        return;
    }
    fs->total_size -= fs->files[index].size;
    for (int i = index; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i+1];
    }
    fs->num_files -= 1;
}

void print_file_system(struct FileSystem fs) {
    printf("Total size of file system: %d\n", fs.total_size);
    printf("%-20s %-10s\n", "Filename", "Size");
    for (int i = 0; i < fs.num_files; i++) {
        printf("%-20s %-10d\n", fs.files[i].name, fs.files[i].size);
    }
}

int main() {
    struct FileSystem fs = create_file_system();
    add_file(&fs, "file1.txt", "hello world");
    add_file(&fs, "file2.txt", "this is a test");
    print_file_system(fs);
    delete_file(&fs, "file1.txt");
    print_file_system(fs);
    return 0;
}