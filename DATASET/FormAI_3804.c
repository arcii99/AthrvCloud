//FormAI DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 20 /* maximum filename length */
#define MAX_FILE_COUNT 50 /* maximum number of files */

/* Structure to hold file information */
typedef struct {
    char name[MAX_FILENAME_LEN + 1]; /* name of the file */
    int size; /* size of the file in bytes */
    char data[256]; /* file data */
} file;

/* Structure to hold information about the file system */
typedef struct {
    file files[MAX_FILE_COUNT]; /* list of files in the system */
    int file_count; /* number of files in the system */
    int total_size; /* total size of all files in the system */
} file_system;

/* Create a new file with the given name and size */
file create_file(char* name, int size) {
    file f;
    strncpy(f.name, name, MAX_FILENAME_LEN);
    f.size = size;
    memset(f.data, '0', sizeof(f.data));
    return f;
}

/* Add a file to the file system */
void add_file(file_system* fs, file f) {
    if (fs->file_count < MAX_FILE_COUNT) {
        fs->files[fs->file_count] = f;
        fs->file_count++;
        fs->total_size += f.size;
        printf("%s added to file system!\n", f.name);
    }
    else {
        printf("File system full! %s not added.\n", f.name);
    }
}

/* Delete a file from the file system */
void delete_file(file_system* fs, char* name) {
    int i, index = -1;
    for (i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        fs->total_size -= fs->files[index].size;
        for (i = index; i < fs->file_count - 1; i++) {
            fs->files[i] = fs->files[i + 1];
        }
        fs->file_count--;
        printf("%s deleted from file system!\n", name);
    }
    else {
        printf("%s not found in file system!\n", name);
    }
}

/* Display information about the file system */
void display_file_system(file_system fs) {
    printf("File system contains %d file(s) with a total size of %d bytes:\n", fs.file_count, fs.total_size);
    int i;
    for (i = 0; i < fs.file_count; i++) {
        printf("\t%s (%d bytes)\n", fs.files[i].name, fs.files[i].size);
    }
}

/* Main function */
int main() {
    file_system fs = {0};
    printf("Welcome to the file system simulation program!\n");
    printf("Here, we can create, add and delete files from our file system\n");

    file f1 = create_file("file1", 1024);
    add_file(&fs, f1);

    file f2 = create_file("file2", 2048);
    add_file(&fs, f2);

    file f3 = create_file("file3", 512);
    add_file(&fs, f3);

    display_file_system(fs);

    delete_file(&fs, "file2");

    display_file_system(fs);

    return 0;
}