//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>

//Function to print out the contents of a file
void printFileContents(FILE *file) {
    printf("Printing file contents:\n");
    char c;
    while((c = fgetc(file)) != EOF) {
        putchar(c);
    }
    printf("\n");
}

int main() {
    FILE *filePointer;
    //Creating a new file
    filePointer = fopen("examplefile.txt", "w");
    if(filePointer == NULL) {
        printf("Error creating file!");
        return 1;
    }
    //Writing to the file
    fprintf(filePointer, "This is an example file.\n");
    fprintf(filePointer, "It contains some text.\n");
    //Closing the file
    fclose(filePointer);
    
    //Opening the file in read mode
    filePointer = fopen("examplefile.txt", "r");
    if(filePointer == NULL) {
        printf("Error opening file!");
        return 1;
    }
    //Printing out the contents of the file
    printFileContents(filePointer);
    //Closing the file
    fclose(filePointer);

    //Appending to the file
    filePointer = fopen("examplefile.txt", "a");
    if(filePointer == NULL) {
        printf("Error opening file!");
        return 1;
    }
    fprintf(filePointer, "This is some additional text.\n");
    //Closing the file
    fclose(filePointer);

    //Opening the file again in read mode
    filePointer = fopen("examplefile.txt", "r");
    if(filePointer == NULL) {
        printf("Error opening file!");
        return 1;
    }
    //Printing out the contents of the file again
    printFileContents(filePointer);
    //Closing the file
    fclose(filePointer);

    return 0;
}