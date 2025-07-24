//FormAI DATASET v1.0 Category: File system simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

typedef struct {
    File files[MAX_FILE_SIZE];
    int num_files;
} Filesystem;

void create_file(Filesystem *fs, char *filename, char *data, int size) {
    if (fs->num_files >= MAX_FILE_SIZE) {
        printf("Error: Filesystem full.\n");
        return;
    }

    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(filename, fs->files[i].filename) == 0) {
            printf("Error: File with name %s already exists.\n", filename);
            return;
        }
    }

    File new_file;
    strcpy(new_file.filename, filename);
    memcpy(new_file.data, data, size);
    new_file.size = size;

    fs->files[fs->num_files++] = new_file;
}

void delete_file(Filesystem *fs, char *filename) {
    int index = -1;

    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(filename, fs->files[i].filename) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: File with name %s does not exist.\n", filename);
        return;
    }

    for (int i = index; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }

    fs->num_files--;
}

void print_file(File file) {
    printf("%s (%d bytes):\n", file.filename, file.size);

    for (int i = 0; i < file.size; i++) {
        printf("%c", file.data[i]);
    }

    printf("\n");
}

void print_filesystem(Filesystem fs) {
    printf("Filesystem:\n");

    for (int i = 0; i < fs.num_files; i++) {
        print_file(fs.files[i]);
    }
}

int main() {
    Filesystem fs;
    fs.num_files = 0;

    create_file(&fs, "example.txt", "Hello, world!", 13);
    create_file(&fs, "example2.txt", "This is a test.", 15);
    print_filesystem(fs);

    delete_file(&fs, "example.txt");
    print_filesystem(fs);

    create_file(&fs, "example3.txt", "New file.", 9);
    print_filesystem(fs);

    return 0;
}