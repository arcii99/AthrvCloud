//FormAI DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>

int main() {
    FILE *fp;
    char message[100];
    
    // Prompt user to enter a message
    printf("Enter a message: ");
    fgets(message, 100, stdin);
    
    // Open file in write mode
    fp = fopen("message.txt", "w");
    
    // Write message to file
    fprintf(fp, "%s", message);
    
    // Close the file
    fclose(fp);
    
    // Open file in read mode
    fp = fopen("message.txt", "r");
    
    // Check if file was opened successfully
    if(fp == NULL) {
        printf("Error opening file.");
        return 1;
    }
    
    // Read and display contents of file
    printf("\nThe contents of the file are:\n");
    while(fgets(message, 100, fp) != NULL) {
        printf("%s", message);
    }
    
    // Close the file
    fclose(fp);
    
    return 0;
}