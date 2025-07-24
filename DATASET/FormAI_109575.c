//FormAI DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create file pointer and open the file
    FILE *fp;
    fp = fopen("example.txt", "w+");
    
    // Write to the file
    fprintf(fp, "Hello World!\n");
    fprintf(fp, "This is a sample C file handling program.\n");
    fprintf(fp, "We are writing some text to a file using C.\n");
    fprintf(fp, "File handling is an important concept in programming.\n");
    
    // Close the file
    fclose(fp);
    
    // Open the file in read mode and print its contents
    fp = fopen("example.txt", "r");
    char ch;
    printf("Contents of example.txt:\n\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    
    // Close the file
    fclose(fp);
    
    // Append to the file
    fp = fopen("example.txt", "a");
    fprintf(fp, "\nThis text has been appended to the file.");
    fclose(fp);
    
    // Open the file in read mode and print its contents again to check the append operation
    fp = fopen("example.txt", "r");
    printf("\n\nContents of example.txt after append:\n\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    
    // Close the file
    fclose(fp);
    
    // Delete the file
    if (remove("example.txt") == 0) {
        printf("\n\nexample.txt deleted successfully.\n");
    } else {
        printf("\n\nFailed to delete example.txt.\n");
    }
    
    return 0;
}