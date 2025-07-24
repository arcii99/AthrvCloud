//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str)
{
    int count = 0;
    int i, len = strlen(str);

    for (i = 0; i < len; i++)
    {
        // If current character is a space or a newline
        if (str[i] == ' ' || str[i] == '\n')
        {
            // Increment word count
            count++;
        }
    }

    // Add one to the count to include the final word
    count++;

    return count;
}

// Main function
int main()
{
    char str[1000];

    // Ask user to enter a string
    printf("Enter a string: ");

    // Read input string
    fgets(str, sizeof(str), stdin);

    // Call countWords() function to count the number of words
    int count = countWords(str);

    // Print the number of words
    printf("The number of words in the string: %d\n", count);

    return 0;
}