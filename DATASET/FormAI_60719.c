//FormAI DATASET v1.0 Category: File system simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("Holy cow, I can't believe how complicated a file system simulation can be!\n");
    printf("But, here goes nothing...\n\n");

    //create the root directory
    struct directory{
        char name[20];
        struct file* files[100];
        struct directory* directories[100];
    }root;

    strcpy(root.name, "/");
    printf("Created root directory: %s\n", root.name);

    //create a new file in the root directory
    struct file{
        char name[20];
        char data[100];
    }file1;

    strcpy(file1.name, "file1.txt");
    strcpy(file1.data, "This is file 1");

    root.files[0] = &file1;
    printf("Created file %s in directory %s\n", file1.name, root.name);

    //create a new directory in the root directory
    struct directory subdirectory1;
    strcpy(subdirectory1.name, "subdirectory1");

    root.directories[0] = &subdirectory1;
    printf("Created subdirectory %s in directory %s\n", subdirectory1.name, root.name);

    //create a new file in the subdirectory
    struct file file2;
    strcpy(file2.name, "file2.txt");
    strcpy(file2.data, "This is file 2");

    subdirectory1.files[0] = &file2;
    printf("Created file %s in directory %s\n", file2.name, subdirectory1.name);

    //access the files and directories
    printf("Accessing files and directories...\n");
    printf("%s\n", root.name);
    printf("|--%s\n", file1.name);
    printf("|--%s\n", subdirectory1.name);
    printf("   |--%s\n", file2.name);
    
    //delete subdirectory and file inside it
    printf("Deleting subdirectory %s and files inside it...\n", subdirectory1.name);
    subdirectory1.files[0] = NULL;
    root.directories[0] = NULL;
    printf("%s\n", root.name);
    printf("|--%s\n", file1.name);

    //delete root directory
    printf("Deleting root directory...\n");
    root.files[0] = NULL;
    printf("Directory %s has been deleted!\n", root.name);

    return 0;
}