//FormAI DATASET v1.0 Category: File handling ; Style: modular
#include<stdio.h>

//Function to create and write data to file
void createAndWrite(char *filename){
    FILE *fileptr = fopen(filename, "w"); //Opening file in write mode
    if(fileptr == NULL){ //Checking if file was opened successfully
        printf("Error in opening file!");
        return;
    }
    fprintf(fileptr, "This is an example program to showcase C File Handling in a Modular way.\n"); //Writing data to file
    fprintf(fileptr, "The program demonstrates the use of different file handling functions in C.\n");
    fclose(fileptr); //Closing file
}

//Function to read data from file
void readFromFile(char *filename){
    char ch;
    FILE *fileptr = fopen(filename, "r"); //Opening file in read mode
    if(fileptr == NULL){ //Checking if file was opened successfully
        printf("Error in opening file!");
        return;
    }
    printf("Reading data from file: \n");
    while((ch = fgetc(fileptr))!=EOF){ //Reading data until the end of file
        putchar(ch); //Printing the read character to console
    }
    fclose(fileptr); //Closing file
}

//Function to append data to file
void appendToFile(char *filename){
    FILE *fileptr = fopen(filename, "a"); //Opening file in append mode
    if(fileptr == NULL){ //Checking if file was opened successfully
        printf("Error in opening file!");
        return;
    }
    fprintf(fileptr, "The program also handles file errors such as non-existing files.\n"); //Appending data to file
    fclose(fileptr); //Closing file
}

//Main function to call other functions
int main(){
    char filename[] = "example.txt";
    createAndWrite(filename); //Calling the function to create and write data to file
    readFromFile(filename); //Calling the function to read data from file
    appendToFile(filename); //Calling the function to append data to file
    return 0;
}