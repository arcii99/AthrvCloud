//FormAI DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>

// Function to check if two files are equal
int are_files_equal(FILE *file1, FILE *file2) {
    char ch1 = getc(file1);
    char ch2 = getc(file2);
    while (ch1 != EOF && ch2 != EOF) {
        if (ch1 != ch2) return 0;
        ch1 = getc(file1);
        ch2 = getc(file2);
    }
    if (ch1 == EOF && ch2 == EOF) return 1;
    else return 0;
}

int main() {
    // Open two files
    FILE *file1, *file2;
    file1 = fopen("romeo.txt", "r");
    file2 = fopen("juliet.txt", "r");

    // Check if the files are equal
    if (are_files_equal(file1, file2)) {
        printf("Romeo and Juliet were made for each other!");
    } else {
        printf("There is no love between Romeo and Juliet :(");
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    return 0;
}