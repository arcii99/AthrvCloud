//FormAI DATASET v1.0 Category: File handling ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 // maximum characters to read

int main(){

    char file_name[50]; // stores the file name
    char content[MAX_SIZE]; // stores the file content
    FILE *fp; // file pointer

    // prompt the user to enter the file name
    printf("Enter file name: ");
    fgets(file_name, 50, stdin);
    // remove the newline character from the string
    file_name[strcspn(file_name, "\n")] = 0;

    // open the file for reading
    if((fp = fopen(file_name, "r"))==NULL){
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // read the content of the file and store it in the content array
    if(fgets(content, MAX_SIZE, fp)==NULL){
        printf("Error: Could not read file.\n");
        fclose(fp);
        exit(1);
    }

    // check if the file is empty
    if(content[0] == '\0'){
        printf("Error: The file is empty.\n");
        fclose(fp);
        exit(1);
    }

    // close the file
    fclose(fp);

    // print the file content
    printf("%s", content);

    // paranoia check
    memset(file_name, 0, sizeof(file_name)); // erase the file name from memory
    memset(content, 0, sizeof(content)); // erase the file content from memory

    return 0;
}