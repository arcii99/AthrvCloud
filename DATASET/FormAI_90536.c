//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Morse code lookup table
char *morse_table[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                       ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                       "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ","\0"};

// Convert a single character to Morse code
char *char_to_morse(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return morse_table[c - 'a'];
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return morse_table[c - 'A'];
    }
    else if (c == ' ')
    {
        return morse_table[26];
    }
    else
    {
        return morse_table[27];
    }
}

// Convert a string to Morse code
void string_to_morse(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%s ", char_to_morse(str[i]));
    }
    printf("\n");
}

int main()
{
    char str[100];

    // Accept input from user
    printf("Enter a string to convert to Morse code: ");
    fgets(str, 100, stdin);

    // Remove the newline character from the input
    str[strcspn(str, "\n")] = '\0';

    // Convert the string to Morse code
    string_to_morse(str);

    return 0;
}