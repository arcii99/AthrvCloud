//FormAI DATASET v1.0 Category: File system simulation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct file {  // structure representing a file
    char name[50];
    char content[100];
};

struct directory { // structure representing a directory
    char name[50];
    struct file files[10];  // array of files
    int filecount;
    struct directory *subdirectories[5];  //array of subdirectories
    int subcount;
};

void print_directory(struct directory *dir) { //function to print the directory
    printf("\nDirectory name: %s\n", dir->name);
    printf("Files in the directory:\n");
    for(int i=0; i<dir->filecount; i++) {  //loop to print all files
        printf("Name: %s\n", dir->files[i].name);
        printf("Content: %s\n", dir->files[i].content);
    }
    printf("Subdirectories in the directory:\n");
    for(int i=0; i<dir->subcount; i++) { //loop to print all subdirectories
        print_directory(dir->subdirectories[i]); //recursive call to print subdirectory
    }
}

int main() {
    
    struct directory root; //creating the root directory
    strcpy(root.name, "root"); 
    
    root.filecount = 2; //adding two files to the root directory
    strcpy(root.files[0].name, "file1");
    strcpy(root.files[0].content, "This is the content of file1"); 
    strcpy(root.files[1].name, "file2");
    strcpy(root.files[1].content, "This is the content of file2"); 
    
    root.subcount = 1; //adding a subdirectory to the root directory
    struct directory *subdir = (struct directory *)malloc(sizeof(struct directory)); //creating a subdirectory using malloc
    strcpy(subdir->name, "subdir1"); 
    
    subdir->filecount = 1; //adding a file to the subdirectory
    strcpy(subdir->files[0].name, "file3");
    strcpy(subdir->files[0].content, "This is the content of file3"); 
    
    subdir->subcount = 0; //subdirectory has no subdirectories
    root.subdirectories[0] = subdir; 
    
    print_directory(&root); //printing the directory
    
    return 0;
}