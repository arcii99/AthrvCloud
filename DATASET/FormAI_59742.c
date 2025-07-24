//FormAI DATASET v1.0 Category: File system simulation ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for file
struct File {
    char* name;
    char* data;
    int size;
};

// Structure for directory
struct Directory {
    char* name;
    struct File* files;
    int num_files;
};

int main() {
    printf("Welcome to the Surreal File System Simulation\n");

    // Creating directory with files
    struct File file1 = {"Pineapple", "This is a pineapple.\n", 23};
    struct File file2 = {"Giraffe", "This is not a giraffe.\n", 26};
    struct File file3 = {"Beach", "The ocean is wavy and warm.\n", 31};
    struct File files[3] = {file1, file2, file3};
    struct Directory surreal_dir = {"Surreal", files, 3};

    // Printing directory and files
    printf("Directory: %s\n", surreal_dir.name);
    for (int i=0; i<surreal_dir.num_files; i++) {
        printf("File %d:\n", i+1);
        printf("\tName: %s\n", surreal_dir.files[i].name);
        printf("\tData: %s", surreal_dir.files[i].data);
        printf("\tSize: %d\n", surreal_dir.files[i].size);
    }

    // Changing data of file 1
    surreal_dir.files[0].data = "This is not a pineapple.\n";
    printf("Updated Pineapple file:\n");
    printf("\tName: %s\n", surreal_dir.files[0].name);
    printf("\tData: %s", surreal_dir.files[0].data);
    printf("\tSize: %d\n", surreal_dir.files[0].size);

    // Deleting file 2
    surreal_dir.files[1] = surreal_dir.files[2];
    surreal_dir.num_files--;
    printf("Deleted Giraffe file.\n");
    printf("Remaining files in directory:\n");
    for (int i=0; i<surreal_dir.num_files; i++) {
        printf("File %d: %s\n", i+1, surreal_dir.files[i].name);
    }

    // Adding new file
    struct File file4 = {"Rainbow", "The rainbow is a serpent's scales.\n", 36};
    surreal_dir.files[surreal_dir.num_files] = file4;
    surreal_dir.num_files++;
    printf("Added Rainbow file.\n");
    printf("Remaining files in directory:\n");
    for (int i=0; i<surreal_dir.num_files; i++) {
        printf("File %d: %s\n", i+1, surreal_dir.files[i].name);
    }

    // Changing name of directory
    surreal_dir.name = "Reality?";
    printf("Changed directory name to: %s\n", surreal_dir.name);

    return 0;
}