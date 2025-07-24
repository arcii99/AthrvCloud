//FormAI DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f; // File pointer
    char filename[50]; // Filename string
    char input[100]; // Input string buffer
    int num; // Integer input buffer
    
    printf("Enter a filename to create or open: ");
    scanf("%s", filename);
    
    f = fopen(filename, "a+"); // Open file with read and write access
    
    if (f == NULL) {
        printf("Failed to open file.\n");
        exit(1);
    }
    
    // Display current contents of file
    printf("Current contents of file: \n");
    rewind(f); // Reset file cursor to beginning
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        printf("%c", ch);
    }
    printf("\n\n");
    
    // Prompt user for input and write to file
    printf("Enter a string to append to the file: ");
    scanf("%s", input);
    fprintf(f, "%s\n", input); // Write string to file
    
    // Prompt user for integer input and write to file
    printf("Enter an integer to append to the file: ");
    scanf("%d", &num);
    fprintf(f, "%d\n", num); // Write integer to file
    
    fclose(f); // Close file
    
    return 0;
}