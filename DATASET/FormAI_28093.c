//FormAI DATASET v1.0 Category: File system simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to create a new file
void createFile(char* fileName, char* fileContent){
    FILE *fp = fopen(fileName, "w");
    if(fp != NULL){
        fprintf(fp, "%s", fileContent);
        fclose(fp);
        printf("\nFile created successfully!");
    }else{
        printf("\nFailed to create file.");
    }
}

//function to read a file
void readFile(char* fileName){
    FILE *fp = fopen(fileName, "r");
    char buffer[255];
    if(fp != NULL){
        printf("\nContent of file: ");
        while(fgets(buffer, 255, fp) != NULL){
            printf("%s", buffer);
        }
        fclose(fp);
    }else{
        printf("\nFailed to open file.");
    }
}

//function to rename a file
void renameFile(char* oldName, char* newName){
    if(rename(oldName, newName) == 0){
        printf("\nFile renamed successfully!");
    }else{
        printf("\nFailed to rename file.");
    }
}

//function to delete a file
void deleteFile(char* fileName){
    if(remove(fileName) == 0){
        printf("\nFile deleted successfully!");
    }else{
        printf("\nFailed to delete file.");
    }
}

int main(){
    printf("Wow! Let's simulate a C file system!");

    //creating a new file
    createFile("example.txt", "Hello, world!");

    //reading the file
    readFile("example.txt");

    //renaming the file
    renameFile("example.txt", "newExample.txt");

    //reading the renamed file
    readFile("newExample.txt");

    //deleting the file
    deleteFile("newExample.txt");

    printf("\nEnd of simulation. That was fun!");
    return 0;
}