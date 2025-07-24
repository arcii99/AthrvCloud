//FormAI DATASET v1.0 Category: File handling ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *loveFile; // Declare a file pointer
    char romanticWords[100];

    loveFile = fopen("loveLetter.txt", "w"); // Open a file for writing

    // Check if file opened successfully
    if (loveFile == NULL) {
        printf("Failed to open the file. Please check the file location.\n");
        exit(1); // Exit the program with error code 1
    }

    // Write romantic words to the file
    fprintf(loveFile, "My love,\n");
    fprintf(loveFile, "As I write this letter, I am filled with an overwhelming feeling of love for you.\n");
    fprintf(loveFile, "Words cannot express how much you mean to me.\n");
    fprintf(loveFile, "Every moment spent with you is a true blessing in my life.\n");
    fprintf(loveFile, "The way you smile just melts my heart and the way you laugh is music to my ears.\n");
    fprintf(loveFile, "I can't imagine my life without your soft touch, gentle hugs and sweet kisses.\n");
    fprintf(loveFile, "You are the reason I believe in love again.\n");
    fprintf(loveFile, "I am so grateful to have you in my life.\n");
    fprintf(loveFile, "Forever yours,\n");

    fclose(loveFile); // Close the file

    printf("Dear, I have written a love letter for you in the file named loveLetter.txt\n");

    loveFile = fopen("loveLetter.txt", "r"); // Open the same file for reading

    // Check if file opened successfully
    if (loveFile == NULL) {
        printf("Failed to open the file. Please check the file location.\n");
        exit(1); // Exit the program with error code 1
    }

    printf("\nHere are the romantic words I wrote for you:\n\n");

    // Read the contents of the file and display it
    while (fgets(romanticWords, 100, loveFile) != NULL) {
        printf("%s", romanticWords);
    }

    fclose(loveFile); // Close the file

    return 0; // Exit the program with success code 0
}