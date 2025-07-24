//FormAI DATASET v1.0 Category: File system simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50
#define MAX_FILE_NAME 20
#define MAX_FILE_SIZE 100

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    char data[MAX_FILE_SIZE];
} File;

typedef struct {
    File files[MAX_FILES];
    int num_files;
    int total_size;
} FileSystem;

void create(FileSystem *fs, char *name, char *data, int size) {
    if (fs->num_files < MAX_FILES && fs->total_size + size <= MAX_FILES) {
        File file;
        strcpy(file.name, name);
        file.size = size;
        strcpy(file.data, data);
        fs->files[fs->num_files] = file;
        fs->num_files++;
        fs->total_size += size;
        printf("File successfully created with name: %s\n", file.name);
    } else {
        printf("Error: File could not be created. Max file limit or capacity reached.\n");
    }
}

void delete(FileSystem *fs, char *name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            fs->total_size -= fs->files[i].size;
            for (int j = i; j < fs->num_files - 1; j++) {
                fs->files[j] = fs->files[j+1];
            }
            fs->num_files--;
            printf("File successfully deleted with name: %s\n", name);
            return;
        }
    }
    printf("Error: File not found with name: %s\n", name);
}

void read(FileSystem *fs, char *name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            printf("Name: %s\n", name);
            printf("Size: %d bytes\n", fs->files[i].size);
            printf("Data:\n%s\n", fs->files[i].data);
            return;
        }
    }
    printf("Error: File not found with name: %s\n", name);
}

int main() {
    FileSystem fs;
    fs.num_files = 0;
    fs.total_size = 0;

    create(&fs, "file1", "This is file 1.", 15);
    create(&fs, "file2", "This is file 2.", 15);
    create(&fs, "file3", "This is file 3.", 15);
    create(&fs, "file4", "This is file 4.", 15);
    create(&fs, "file5", "This is file 5.", 15);
    create(&fs, "file6", "This is file 6.", 15);
    create(&fs, "file7", "This is file 7.", 15);
    create(&fs, "file8", "This is file 8.", 15);
    create(&fs, "file9", "This is file 9.", 15);
    create(&fs, "file10", "This is file 10.", 20);

    printf("\n");

    read(&fs, "file3");

    printf("\n");

    delete(&fs, "file4");
    delete(&fs, "non-existent-file");

    printf("\n");

    create(&fs, "file11", "This is file 11.", 50);
    create(&fs, "file12", "This is file 12.", 30);

    return 0;
}