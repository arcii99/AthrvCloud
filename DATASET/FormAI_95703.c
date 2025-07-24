//FormAI DATASET v1.0 Category: File system simulation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_SIZE 50
#define MAX_FILE_SIZE 1024

typedef struct{
    char filename[MAX_FILENAME_SIZE];
    int size;
    char content[MAX_FILE_SIZE];
}FS_File;

//Function declarations
int addFile(FS_File file, FS_File *files, int numFiles);
int removeFile(char *filename, FS_File *files, int numFiles);
void printFiles(FS_File *files, int numFiles);

int main(){

    FS_File files[10];
    int numFiles = 0;
    char userInput[255];

    printf("Welcome to the File System Simulation Program!\n");

    while(1){
        printf("\nPlease enter a command (add, remove, list, quit):\n");
        fgets(userInput, 255, stdin);
        userInput[strcspn(userInput, "\n")] = 0; //removes newline character from input

        if(strcmp(userInput, "add") == 0){
            FS_File file;
            printf("\nPlease enter the name of the file (max %d characters):\n", MAX_FILENAME_SIZE);
            fgets(file.filename, MAX_FILENAME_SIZE, stdin);
            file.filename[strcspn(file.filename, "\n")] = 0; //removes newline character from input

            printf("\nPlease enter the content of the file (max %d characters):\n", MAX_FILE_SIZE);
            fgets(file.content, MAX_FILE_SIZE, stdin);
            file.content[strcspn(file.content, "\n")] = 0; //removes newline character from input

            file.size = strlen(file.content);
            
            if(addFile(file, files, numFiles) == -1){
                printf("\nError: File could not be added to the file system.\n");
            } else {
                printf("\nSuccess: File added to the file system.\n");
                numFiles++;
            }
        } else if(strcmp(userInput, "remove") == 0){
            char filename[MAX_FILENAME_SIZE];
            printf("\nPlease enter the name of the file you would like to remove:\n");
            fgets(filename, MAX_FILENAME_SIZE, stdin);
            filename[strcspn(filename, "\n")] = 0; //removes newline character from input

            if(removeFile(filename, files, numFiles) == -1){
                printf("\nError: File could not be removed from the file system.\n");
            } else {
                printf("\nSuccess: File removed from the file system.\n");
                numFiles--;
            }
        } else if(strcmp(userInput, "list") == 0){
            if(numFiles == 0){
                printf("\nThe file system is currently empty.\n");
            } else {
                printf("\nThe following files are in the file system:\n");
                printFiles(files, numFiles);
            }
        } else if(strcmp(userInput, "quit") == 0){
            printf("\nGoodbye!\n");
            return 0;
        } else {
            printf("\nError: Invalid command.\n");
        }
    }
}

/**
 * Adds a file to the file system
 * Returns 0 on success and -1 on failure
**/
int addFile(FS_File file, FS_File *files, int numFiles){
    //Make sure the file size isn't too big
    if(file.size > MAX_FILE_SIZE){
        return -1;
    }

    //Make sure there isn't already a file with the same name
    for(int i = 0; i < numFiles; i++){
        if(strcmp(file.filename, files[i].filename) == 0){
            return -1;
        }
    }

    //Add the file to the file system
    files[numFiles] = file;
    return 0;
}

/**
 * Removes a file from the file system
 * Returns 0 on success and -1 on failure
**/
int removeFile(char *filename, FS_File *files, int numFiles){
    //Find the file with the matching name
    int foundFile = -1;
    for(int i = 0; i < numFiles; i++){
        if(strcmp(filename, files[i].filename) == 0){
            foundFile = i;
            break;
        }
    }

    //If the file wasn't found, return an error
    if(foundFile == -1){
        return -1;
    }

    //Shift all files after the removed file back one index
    for(int i = foundFile; i < numFiles-1; i++){
        files[i] = files[i+1];
    }

    return 0;
}

/**
 * Prints all files in the file system
**/
void printFiles(FS_File *files, int numFiles){
    for(int i = 0; i < numFiles; i++){
        printf("\nFile %d:\n", i+1);
        printf("Name: %s\n", files[i].filename);
        printf("Size: %d\n", files[i].size);
        printf("Content: %s\n", files[i].content);
    }
}