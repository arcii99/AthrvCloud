//FormAI DATASET v1.0 Category: File system simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 20
#define DISK_SIZE 1024

struct File {
    char name[MAX_FILENAME_LENGTH];
    int size;
    int start;
};

struct Disk {
    char data[DISK_SIZE];
    int used_blocks;
};

struct File_system {
    struct File files[MAX_FILES];
    struct Disk disk;
};

void initialize_file_system(struct File_system* fs) {
    fs->disk.used_blocks = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i].name[0] = '\0';
        fs->files[i].size = 0;
        fs->files[i].start = -1;
    }
}

void print_file_system(struct File_system* fs) {
    printf("Disk usage: %d/%d\n", fs->disk.used_blocks, DISK_SIZE);
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].name[0] != '\0') {
            printf("%s\t%d bytes\tstarting at block %d\n", 
                   fs->files[i].name, fs->files[i].size, fs->files[i].start);
        }
    }
}

int create_file(struct File_system* fs, char* name, int size) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].name[0] == '\0') {
            fs->files[i].size = size;
            fs->files[i].start = fs->disk.used_blocks;
            fs->disk.used_blocks += size;
            for (int j = 0; j < size; j++) {
                fs->disk.data[fs->files[i].start + j] = 0;
            }
            snprintf(fs->files[i].name, MAX_FILENAME_LENGTH, "%s", name);
            return 1;
        }
    }
    return 0;
}

int delete_file(struct File_system* fs, char* name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int start = fs->files[i].start;
            int size = fs->files[i].size;
            for (int j = 0; j < size; j++) {
                fs->disk.data[start + j] = 0;
            }
            fs->files[i].name[0] = '\0';
            fs->files[i].size = 0;
            fs->files[i].start = -1;
            return 1;
        }
    }
    return 0;
}

int write_file(struct File_system* fs, char* name, char* data, int size) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int start = fs->files[i].start;
            int file_size = fs->files[i].size;
            if (size > file_size) {
                return 0;
            }
            for (int j = 0; j < size; j++) {
                fs->disk.data[start + j] = data[j];
            }
            return 1;
        }
    }
    return 0;
}

int read_file(struct File_system* fs, char* name, char* buffer) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            int start = fs->files[i].start;
            int size = fs->files[i].size;
            for (int j = 0; j < size; j++) {
                buffer[j] = fs->disk.data[start + j];
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    struct File_system fs;
    initialize_file_system(&fs);
    create_file(&fs, "file1", 3);
    create_file(&fs, "file2", 4);
    create_file(&fs, "file3", 5);
    print_file_system(&fs);
    char data[] = "hello";
    write_file(&fs, "file2", data, 5);
    print_file_system(&fs);
    char buffer[6];
    read_file(&fs, "file2", buffer);
    buffer[5] = '\0';
    printf("%s\n", buffer);
    delete_file(&fs, "file2");
    print_file_system(&fs);
    return 0;
}