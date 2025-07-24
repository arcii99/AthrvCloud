//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

// Function to convert c to Morse Code
void convertToMorseCode(char *input)
{
    // Initializing Morse code
    char *morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/"};
    char output[1000] = "";

    // Loop through the input string
    for (int i = 0; i < strlen(input); i++)
    {
        // Converting a character to Morse code
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            strcat(output, morse[input[i] - 'a']);
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            strcat(output, morse[input[i] - 'A']);
        }
        else
        {
            // If the character is not a letter, append a slash
            strcat(output, "/");
        }
    }
    // Print the Morse code string
    printf("Morse Code: %s", output);
}

int main()
{
    printf("Enter a message to convert to Morse Code: ");
    char input[1000];
    fgets(input, 1000, stdin);

    // Removing the newline character at the end of the string
    if (input[strlen(input) - 1] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }

    convertToMorseCode(input);
    return 0;
}