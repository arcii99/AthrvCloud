//FormAI DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>

// Function prototype
void writeToFile(FILE *filePtr, char *text);
void readFromFile(FILE *filePtr);

int main(){
    // Open or create a file in write mode and save the file pointer
    FILE *filePtr = fopen("example.txt", "w");

    // Write some text to the file
    char text[] = "This is an example program using file handling in C!";
    writeToFile(filePtr, text);

    // Close the file
    fclose(filePtr);

    // Open the same file in read mode and save the file pointer
    filePtr = fopen("example.txt", "r");

    // Read all the text from the file and output it to the console
    readFromFile(filePtr);

    // Close the file again
    fclose(filePtr);
    
    return 0;
}

// Function to write text to a file
void writeToFile(FILE *filePtr, char *text){
    // Check if the file pointer is valid
    if(filePtr == NULL){
        printf("Error: File pointer is null");
        return;
    }

    // Write the text to the file
    fprintf(filePtr, "%s", text);   
}

// Function to read all the text from a file and output it to the console
void readFromFile(FILE *filePtr){
    // Check if the file pointer is valid
    if(filePtr == NULL){
        printf("Error: File pointer is null");
        return;
    }

    // Declare a buffer to hold the text to read from the file
    char buffer[256];

    // Read and output each line from the file
    while(fgets(buffer, 256, filePtr) != NULL){
        printf("%s", buffer);
    }
}