//FormAI DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>

// Declare function to check if a character is a letter
int isLetter(char ch)
{
    // Check if character is in ASCII range of uppercase or lowercase letters
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
    {
        return 1; // Character is a letter
    }
    else
    {
        return 0; // Character is not a letter
    }
}

// Declare function to count occurrences of a specific letter in a file
int countOccurrences(FILE *file, char letter)
{
    int count = 0; // Initialize count variable to zero
    char ch; // Declare variable to store current character from file

    // Loop through each character in the file
    while ((ch = fgetc(file)) != EOF)
    {
        // Check if current character is the desired letter
        if (ch == letter)
        {
            count++; // Increment count if character is desired letter
        }
    }

    return count; // Return the count of occurrences of the desired letter
}

int main()
{
    // Declare file pointer and open file "romeo_and_juliet.txt"
    FILE *file = fopen("romeo_and_juliet.txt", "r");

    // Check if file was opened successfully
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Declare variables to store number of occurrences of each letter
    int aCount = countOccurrences(file, 'a');
    rewind(file); // Reset file pointer to beginning of file
    int bCount = countOccurrences(file, 'b');
    rewind(file); // Reset file pointer to beginning of file
    int cCount = countOccurrences(file, 'c');
    rewind(file); // Reset file pointer to beginning of file

    fclose(file); // Close file

    // Print out results
    printf("In fair Verona, where we lay our scene,\n");
    printf("From ancient grudge break to new mutiny,\n");
    printf("Where civil blood makes civil hands unclean.\n");
    printf("\n");
    printf("In this lovely tale of tragic love,\n");
    printf("There are %d 'a's, %d 'b's, and %d 'c's,\n", aCount, bCount, cCount);
    printf("Which appear in the text like stars above.\n");
    printf("\n");
    printf("And so, with heavy heart and mournful gaze,\n");
    printf("We bid adieu to Romeo and Juliet,\n");
    printf("Whose love was pure and true in all ways.\n");

    return 0; // End program
}