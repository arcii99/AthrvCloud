//FormAI DATASET v1.0 Category: File handling ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char c;
    int count=0;

    printf("Welcome to my file handling program!\n");
    printf("I'm going to count the number of 'a's in the file you give me.\n");

    // Ask user for filename
    printf("Please enter the name of the file: ");
    char filename[50];
    scanf("%s", filename);

    // Open file
    fp = fopen(filename, "r");

    // Check if file opened successfully
    if (fp == NULL) {
        printf("Sorry, I couldn't open the file. Please try again.\n");
        return 1;
    }

    // Read file character by character
    while ((c = fgetc(fp)) != EOF) {
        if (c == 'a') {
            count++;
        }
    }

    // Close file
    fclose(fp);

    if (count > 0) {
        printf("There were %d 'a's in the file you gave me!\n", count);
    } else {
        printf("I didn't find any 'a's in the file you gave me. Sorry not sorry!\n");
    }

    return 0;
}