//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// declare struct for 'file'
struct file {
    char name[20];  // name of file
    int size;       // size of file in bytes
};

// declare struct for 'directory'
struct directory {
    char name[20];      // name of directory
    struct file files[5];   // files in directory
};

int main() {
    // initialize root directory
    struct directory root = {"root", {{"jellyfish", 1000}, {"firework", 750}, {"whale", 2000}}};

    printf("Welcome to the surreal File System Simulation!\n\n");

    // print files in root directory
    printf("Current directory: %s\n", root.name);
    printf("Files in directory:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s (%d bytes)\n", root.files[i].name, root.files[i].size);
    }
    printf("\n");

    // create new directory
    struct directory surreal_dir = {"surreal", {}};
    printf("Created new directory: %s\n\n", surreal_dir.name);

    // add files to new directory
    surreal_dir.files[0] = root.files[1];
    surreal_dir.files[1] = (struct file){"dream", 500};
    surreal_dir.files[2] = (struct file){"imagination", 1250};
    printf("Added files to directory:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s (%d bytes)\n", surreal_dir.files[i].name, surreal_dir.files[i].size);
    }
    printf("\n");

    // move file from root directory to new directory
    surreal_dir.files[3] = root.files[2];
    root.files[2].size -= 500;
    printf("Moved file from root directory to %s:\n", surreal_dir.name);
    printf("%s (%d bytes) in %s\n", surreal_dir.files[3].name, surreal_dir.files[3].size, surreal_dir.name);
    printf("%s now has %d bytes\n\n", root.name, root.files[2].size);

    // delete file from root directory
    root.files[2] = (struct file){"", 0};
    printf("Deleted file from root directory:\n");
    for (int i = 0; i < 3; i++) {
        if (root.files[i].size == 0) {
            printf("File deleted.\n");
        } else {
            printf("%s (%d bytes)\n", root.files[i].name, root.files[i].size);
        }
    }
    printf("\n");

    printf("Thank you for using the surreal File System Simulation!\n");

    return 0;
}