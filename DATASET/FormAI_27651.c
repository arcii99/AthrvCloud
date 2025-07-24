//FormAI DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME 20
#define MAX_FILESIZE 100

typedef struct {
    char name[MAX_FILENAME];
    char content[MAX_FILESIZE];
    int size;
    int block_ids[MAX_FILESIZE];
    int num_blocks;
} File;

typedef struct {
    File files[MAX_FILES];
    int num_files;
} FileSystem;

int find_file(FileSystem fs, char* name) {
    for (int i = 0; i < fs.num_files; i++) {
        if (strcmp(fs.files[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void create_file(FileSystem* fs, char* name, char* content, int size) {
    if (find_file(*fs, name) != -1) {
        printf("File with name '%s' already exists.\n", name);
        return;
    }

    if (fs->num_files >= MAX_FILES) {
        printf("Cannot create file - maximum number of files reached.\n");
        return;
    }

    File new_file;
    strcpy(new_file.name, name);
    strcpy(new_file.content, content);
    new_file.size = size;

    int num_blocks = (size + MAX_FILESIZE - 1) / MAX_FILESIZE;
    if (num_blocks > MAX_FILES) {
        printf("Cannot create file - size too large.\n");
        return;
    }

    for (int i = 0; i < num_blocks; i++) {
        new_file.block_ids[i] = rand() % MAX_FILES;
    }

    new_file.num_blocks = num_blocks;
    fs->files[fs->num_files++] = new_file;
}

void display_file(FileSystem fs, char* name) {
    int file_index = find_file(fs, name);
    if (file_index == -1) {
        printf("File with name '%s' not found.\n", name);
        return;
    }
    printf("File '%s':\n", name);
    printf("Size: %d bytes\n", fs.files[file_index].size);
    printf("Blocks:");
    for (int i = 0; i < fs.files[file_index].num_blocks; i++) {
        printf(" %d", fs.files[file_index].block_ids[i]);
    }
    printf("\nContent:\n%s\n", fs.files[file_index].content);
}

void write_file(FileSystem* fs, char* name, char* content, int size) {
    int file_index = find_file(*fs, name);
    if (file_index == -1) {
        printf("File with name '%s' not found.\n", name);
        return;
    }

    if (size > MAX_FILESIZE * fs->files[file_index].num_blocks) {
        printf("Cannot write more than %d bytes to file.\n", MAX_FILESIZE * fs->files[file_index].num_blocks);
        return;
    }
    
    strcpy(fs->files[file_index].content, content);
    fs->files[file_index].size = size;

    int num_blocks = (size + MAX_FILESIZE - 1) / MAX_FILESIZE;
    if (num_blocks > fs->files[file_index].num_blocks) {
        printf("Cannot write - file size too large.\n");
        return;
    }
}

int main() {
    FileSystem fs;
    fs.num_files = 0;

    // create some sample files
    create_file(&fs, "file1.txt", "This is the content of file 1.", 30);
    create_file(&fs, "file2.txt", "This is a longer file with more content.", 43);
    create_file(&fs, "file3.txt", "This file is short.", 17);

    // display file information
    display_file(fs, "file1.txt");
    display_file(fs, "file2.txt");
    display_file(fs, "file3.txt");

    // modify and display file content
    write_file(&fs, "file1.txt", "This is the updated content of file 1.", 39);
    display_file(fs, "file1.txt");

    return 0;
}