//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{ 
    // Create a file pointer and open the file in write mode
    FILE *fptr = fopen("happy_file.txt", "w");
    
    // Check if the file was opened successfully
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    char message[100] = "Hello, this is a happy file! :)\n";
    
    // Write the message to the file
    fputs(message, fptr);
    
    // Close the file
    fclose(fptr);
    
    // Open the file again, but this time in read mode
    fptr = fopen("happy_file.txt", "r");
    
    // Check if the file was opened successfully
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    
    char buffer[100];
    
    // Read the contents of the file and print it to the console
    while(fgets(buffer, 100, fptr)) {
        printf("%s", buffer);
    }
    
    // Close the file
    fclose(fptr);
    
    return 0;
}