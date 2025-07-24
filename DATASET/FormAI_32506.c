//FormAI DATASET v1.0 Category: File system simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 50 /* Maximum number of files in the file system */
#define MAX_NAME 15 /* Maximum length of file name */
#define MAX_SIZE 1024 /* Maximum size of file in bytes */

/* File struct that holds the file's name and data */
struct File {
    char name[MAX_NAME];
    char data[MAX_SIZE];
};

/* File system struct that holds the array of files */
struct FileSystem {
    struct File files[MAX_FILES];
    int num_files; /* Number of files currently in the file system */
};

/* Function to create a new file in the file system */
void create_file(struct FileSystem *fs, char *name, char *data) {
    if (fs->num_files >= MAX_FILES) {
        printf("File system is full, unable to create file.\n");
        return;
    }
    if (strlen(name) > MAX_NAME) {
        printf("File name is too long, unable to create file.\n");
        return;
    }

    /* Copy the file name and data into a new File struct */
    struct File new_file;
    strcpy(new_file.name, name);
    strcpy(new_file.data, data);

    /* Add the new File struct to the file system and increment the num_files counter */
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
}

/* Function to read a file in the file system */
void read_file(struct FileSystem *fs, char *name) {
    int i;

    /* Search for the file with the specified name */
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            /* File found, print its data */
            printf("File data: %s\n", fs->files[i].data);
            return;
        }
    }

    /* File not found */
    printf("File not found.\n");
}

/* Main function that demonstrates the file system functions */
int main() {
    /* Initialize a new file system */
    struct FileSystem fs;
    fs.num_files = 0;

    /* Create some new files */
    create_file(&fs, "file1", "Hello world!");
    create_file(&fs, "file2", "This is a test.");
    create_file(&fs, "file3", "Another file.");

    /* Read one of the files */
    read_file(&fs, "file2");

    return 0;
}