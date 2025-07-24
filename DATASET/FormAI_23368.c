//FormAI DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h> // Importing Standard Input Output Header File

void main() { // Main Function
    
    FILE *fptr; // File pointer
    
    char filename[100], c; // Defining Two Variables For Filename And Characters
    
    printf("Enter the filename: "); // Prompting User For Filename
    scanf("%s", filename); // Scanning User Input For Filename
    
    fptr = fopen(filename, "r"); // Open File With Given Filename in Read Mode
    
    if (fptr == NULL) { // Check If File Was Opened Successfully
        printf("Cannot open file. Please try again.\n"); // If File Was Not Opened Successfully
    }
    else {
        printf("\n"); // If File Was Opened Successfully
        
        while ((c = getc(fptr)) != EOF) { // Read File Character By Character Till The End Of File
            printf("%c", c); // Print Character To Console
        }
        
        fclose(fptr); // Close The Opened File
    }
}