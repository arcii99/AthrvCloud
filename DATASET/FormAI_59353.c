//FormAI DATASET v1.0 Category: File handling ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *filepointer;
    char ch, filename[20], content[200];

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter the content of the file: ");
    scanf(" %[^\n]s", content);

    // Write content to the file
    filepointer = fopen(filename, "w"); //Open file for Writing
    if(filepointer == NULL){
        printf("Can't create file!\n");
        exit(0);
    }

    fprintf(filepointer, "%s", content); //Write content to file
    printf("Content successfully added to file %s\n", filename);
    fclose(filepointer);

    // Read content from the file
    filepointer = fopen(filename, "r"); //Open file for Reading
    if(filepointer == NULL){
        printf("Can't open file!\n");
        exit(0);
    }

    printf("Content of file %s is: \n", filename);
    while((ch = fgetc(filepointer)) != EOF){ //Read content from file until end of file
        printf("%c", ch);
    }
    printf("\n");

    fclose(filepointer);
    return 0;
}