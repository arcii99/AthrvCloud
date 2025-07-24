//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    // Ask the user for a sentence
    printf("Please enter a sentence to be processed: ");
    char sentence[100];
    fgets(sentence, 100, stdin);

    // Create a variable to hold the number of vowels in the sentence
    int num_vowels = 0;

    // Loop over each character in the sentence
    for (int i = 0; i < strlen(sentence); i++)
    {
        char c = tolower(sentence[i]); // Convert the character to lowercase

        // Check if the character is a vowel
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            num_vowels++; // Increase the vowel count
        }
    }

    // Print the number of vowels found in the sentence
    printf("There were %d vowels in your sentence.\n", num_vowels);

    // Loop over each character in the sentence
    for (int i = 0; i < strlen(sentence); i++)
    {
        char c = sentence[i];

        // Check if the character is a letter
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            // Check if the letter is lowercase
            if (c >= 'a' && c <= 'z')
            {
                // Convert the letter to uppercase
                c -= 32;
            }

            // Print the uppercase letter and its ASCII code
            printf("%c = %d\n", c, (int)c);
        }
    }

    return 0;
}