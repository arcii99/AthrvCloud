//FormAI DATASET v1.0 Category: File system simulation ; Style: Alan Touring
//A simple File System Simulation Example program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct file {
    char name[20];
    int size;
    char content[100];
} File;

typedef struct directory {
    char name[20];
    int num_files;
    File files[10];
} Directory;

Directory root; //Root directory

//Function to create a new file
void create_file(char *name, int size, char *content, Directory *dir) {
    if(dir->num_files < 10) { //Check if directory has space for the file
        File new_file;
        strcpy(new_file.name, name);
        new_file.size = size;
        strcpy(new_file.content, content);
        dir->files[dir->num_files++] = new_file;
        printf("File created successfully!\n");
    } else {
        printf("Directory is full!\n");
    }
}

//Function to delete a file
void delete_file(char *name, Directory *dir) {
    int i;
    for(i=0; i<dir->num_files; i++) {
        if(strcmp(dir->files[i].name, name) == 0) {
            int j;
            for(j=i; j<dir->num_files-1; j++) {
                dir->files[j] = dir->files[j+1];
            }
            dir->num_files--;
            printf("File deleted successfully!\n");
            return;
        }
    }
    printf("File not found\n");
}

//Function to display the contents of a file
void display_file(char *name, Directory *dir) {
    int i;
    for(i=0; i<dir->num_files; i++) {
        if(strcmp(dir->files[i].name, name) == 0) {
            printf("Name: %s\tSize: %d\n", dir->files[i].name, dir->files[i].size);
            printf("Content: %s\n", dir->files[i].content);
            return;
        }
    }
    printf("File not found\n");
}

//Function to display the contents of a directory
void display_dir(Directory *dir) {
    printf("Directory: %s\n", dir->name);
    int i;
    for(i=0; i<dir->num_files; i++) {
        printf("Name: %s\tSize: %d\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    strcpy(root.name, "root");
    root.num_files = 0;
    int choice;
    char fname[20], content[100];
    int size;
    do {
        printf("file system simulation\n");
        printf("1. Create file\n2. Delete file\n3. Display file\n4. Display directory\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", fname);
                printf("Enter file size: ");
                scanf("%d", &size);
                printf("Enter file content: ");
                scanf("%s", content);
                create_file(fname, size, content, &root);
                break;
            case 2:
                printf("Enter file name: ");
                scanf("%s", fname);
                delete_file(fname, &root);
                break;
            case 3:
                printf("Enter file name: ");
                scanf("%s", fname);
                display_file(fname, &root);
                break;
            case 4:
                display_dir(&root);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);
    return 0;
}