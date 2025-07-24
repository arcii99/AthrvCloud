//FormAI DATASET v1.0 Category: Text processing ; Style: happy
// Welcome to my happy text processing program!
// This program takes in a text file and converts all letters to uppercase.
// It also counts the number of words in the file and outputs the result to the user.
// Let's get started!

#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[50];
    char c;
    int word_count = 0;
    
    // Get the filename from the user
    printf("Welcome! Please enter the name of your file: ");
    scanf("%s", filename);
    
    // Open the file
    fp = fopen(filename, "r");
    
    // Check if the file exists
    if (fp == NULL) {
        printf("Sorry, the file does not exist. Please try again.\n");
        return 0;
    }
    
    // Loop through the file and convert letters to uppercase
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            c = toupper(c);
        }
        putchar(c);
        
        // Count the number of words
        if (isspace(c)) {
            word_count++;
        }
    }
    
    // Close the file
    fclose(fp);
    
    // Output the number of words to the user
    printf("\n\nYour file has %d words. Thanks for using my program! :)\n", word_count+1);
    
    return 0;
}