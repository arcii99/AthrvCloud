//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Morse code dictionary
char *morse_codes[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

// Function to convert character to Morse code
char *char_to_morse(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return morse_codes[c - 'a'];
    }
    else if(c >= 'A' && c <= 'Z')
    {
        return morse_codes[c - 'A'];
    }
    else
    {
        return "";
    }
}

int main()
{
    char input[100];
    printf("Enter a sentence to convert to Morse code:\n");
    fgets(input, 100, stdin);
    // Remove newline character at end of input string
    input[strcspn(input, "\n")] = '\0';

    // Loop through input string and convert each character to Morse code
    for(int i = 0; i < strlen(input); i++)
    {
        char *morse_char = char_to_morse(input[i]);
        printf("%s ", morse_char);
    }

    return 0;
}