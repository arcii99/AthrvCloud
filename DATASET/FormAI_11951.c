//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define Morse Code conversions for each letter and number
const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

// Function to convert a single character to Morse Code
void convert_char_to_morse(char c)
{
    if (isalpha(c))
    {
        printf("%s ", morse_code[toupper(c) - 'A']);
    }
    else if (isdigit(c))
    {
        printf("%s ", morse_code[c - '0' + 26]); // Offset by 26 to get to numerical values in the morse_code array
    }
    else if (c == ' ')
    {
        printf("/ ");
    }
    else
    {
        printf("%c ", c); // Character not found in Morse Code, print as is
    }
}

// Function to convert a string to Morse Code
void convert_string_to_morse(char *str)
{
    int str_len = strlen(str);

    for (int i = 0; i < str_len; i++)
    {
        convert_char_to_morse(str[i]);
    }
}

int main()
{
    char input_string[100];

    printf("Enter a string to convert to Morse Code:\n");
    fgets(input_string, 100, stdin);

    printf("\nMorse Code:\n");
    convert_string_to_morse(input_string);

    return 0;
}