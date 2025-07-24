//FormAI DATASET v1.0 Category: Text processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Declare a pointer to hold the file pointer
    FILE *fptr;
    // Open the file in read mode
    fptr = fopen("input.txt", "r");

    // Check if the file was opened successfully
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // Declare an array to hold the file contents
    char text[1000];
    // Read the contents of the file and store it in the array
    fgets(text, 1000, fptr);

    // Close the file
    fclose(fptr);

    // Find the length of the string
    int length = strlen(text);

    // Count the number of vowels in the text
    int vowels = 0;
    for (int i = 0; i < length; i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            vowels++;
        }
    }

    // Count the number of consonants in the text
    int consonants = 0;
    for (int i = 0; i < length; i++) {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) {
            if (text[i] != 'a' && text[i] != 'e' && text[i] != 'i' && text[i] != 'o' && text[i] != 'u' && text[i] != 'A' && text[i] != 'E' && text[i] != 'I' && text[i] != 'O' && text[i] != 'U') {
                consonants++;
            }
        }
    }

    // Output the result
    printf("The text contains %d vowels and %d consonants.", vowels, consonants);

    return 0;
}