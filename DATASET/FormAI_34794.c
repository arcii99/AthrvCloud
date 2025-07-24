//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char file1Name[50];
    char file2Name[50];
    printf("Enter the name of the first file: ");
    fgets(file1Name, 50, stdin);
    file1Name[strcspn(file1Name, "\n")] = 0; // Remove the newline character
    printf("Enter the name of the second file: ");
    fgets(file2Name, 50, stdin);
    file2Name[strcspn(file2Name, "\n")] = 0; // Remove the newline character

    FILE *file1 = fopen(file1Name, "r");
    FILE *file2 = fopen(file2Name, "r");
    if (file1 == NULL || file2 == NULL) {
        printf("Error opening files, please try again.\n");
        return 1;
    }

    char ch1 = getc(file1); // Get the first character from file1
    char ch2 = getc(file2); // Get the first character from file2
    int errorCount = 0;
    while (ch1 != EOF && ch2 != EOF) {
        if (ch1 != ch2) {
            errorCount++;
        }
        ch1 = getc(file1);
        ch2 = getc(file2);
    }
    if (errorCount == 0) {
        printf("Files are identical.\n");
    } else {
        printf("Files are not identical - there are %d errors.\n", errorCount);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}