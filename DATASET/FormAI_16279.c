//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>
#include <string.h>

// function to print ASCII art of text
void print_ascii_art(char *text)
{
    // ASCII art characters
    char ascii_chars[][6] = {
        "  #  ",
        "###  ",
        "  #  ",
        "  #  ",
        "#####",
        "     "
    };

    // loop through each character of the input text
    int len = strlen(text);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < len; j++)
        {
            // check if the character is a lowercase letter
            if (text[j] >= 'a' && text[j] <= 'z')
            {
                // get the index of the ASCII character for the letter
                int index = text[j] - 'a';

                // print the corresponding ASCII character for the letter
                printf("%s ", ascii_chars[i] + (index * 5));
            }
            // check if the character is an uppercase letter
            else if (text[j] >= 'A' && text[j] <= 'Z')
            {
                // get the index of the ASCII character for the letter
                int index = text[j] - 'A';

                // print the corresponding ASCII character for the letter
                printf("%s ", ascii_chars[i] + (index * 5));
            }
            // check if the character is a space
            else if (text[j] == ' ')
            {
                // print a space of the same width as an ASCII character
                printf("     ");
            }
            // if the character is not a letter or space, print an error message
            else
            {
                printf("Invalid character '%c' in input text.\n", text[j]);
                return;
            }
        }
        printf("\n");
    }
}

int main()
{
    // example usage of the print_ascii_art function
    print_ascii_art("Hello world!");
    return 0;
}