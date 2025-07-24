//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024 // Set the buffer size for reading file.

void count_freq(char* filename) {
    int count[26] = { 0 }; // Initialize an array to store the frequency of each alphabet (a-z).
    FILE* fp = fopen(filename, "r"); // Open the file in read mode.
    char buffer[BUF_SIZE]; // Create a buffer to store the file contents.
    if (fp == NULL) { // Check if file exists or not.
        printf("File not found.\n");
        exit(1);
    }
    while (fgets(buffer, BUF_SIZE, fp)) { // Read file line by line.
        for (int i = 0; buffer[i] != '\0'; i++) { // Traverse through each character of line.
            if (isalpha(buffer[i])) { // If the character is an alphabet.
                count[tolower(buffer[i]) - 'a']++; // Increase the frequency of alphabet accordingly.
            }
        }
    }
    fclose(fp); // Close the file.
    printf("Frequency of each alphabet in the file %s:\n\n", filename);
    for (int i = 0; i < 26; i++) { // Traverse through the array to print frequency of each alphabet.
        printf("%c : %d\n", i + 'a', count[i]); // Print the result in required format.
    }
}

int main() {
    char filename[50];
    printf("Enter the name of file you want to process: ");
    scanf("%s", filename); // Take input from user for the file name.
    count_freq(filename); // Call the function to count the frequency of each alphabet in the file.
    return 0;
}