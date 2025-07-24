//FormAI DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>

int main() {
    FILE *fp;

    char str[50] = "This is a text file.";
    
    // Create a file
    fp = fopen("example.txt", "w");

    // Check if file was created
    if (fp == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    // Write to file
    fputs(str, fp);
    
    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen("example.txt", "r");

    // Check if file was opened
    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Read the file and print its contents
    printf("The contents of the file are:\n");
    while (fgets(str, 50, fp) != NULL) {
        printf("%s", str);
    }

    // Close the file
    fclose(fp);

    return 0;
}