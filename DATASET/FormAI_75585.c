//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Hello! Let's write some data to a file!\n");

    // Creating a file pointer
    FILE *fp;

    // Opening a file named "data.txt" in write mode 
    fp = fopen("data.txt", "w");

    // Checking if file opened successfully
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // Writing to the file
    fprintf(fp, "This is a test file.\n");
    fprintf(fp, "I'm writing data to it.\n");
    fprintf(fp, "Yay! I love writing to files!\n");

    // Closing the file
    fclose(fp);

    printf("Data written successfully!\n");

    // Now let's read the file
    printf("\nReading data from file...\n\n");

    // Opening the file in read mode
    fp = fopen("data.txt", "r");

    // Checking if file opened successfully
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // Reading and printing the contents of the file
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    // Closing the file
    fclose(fp);

    printf("\nData read successfully!\n");

    return 0;
}