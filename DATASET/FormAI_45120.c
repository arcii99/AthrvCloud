//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: recursive
#include <stdio.h>
#include <string.h>

void recursive_morse(char c)
{
    const char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
        "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", 
        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    if (c >= 'a' && c <= 'z')
    {
        printf("%s ", morse[c - 'a']);
    }
    else if (c >= 'A' && c <= 'Z')
    {
        printf("%s ", morse[c - 'A']);
    }
    else if (c == ' ')
    {
        printf("/ ");
    }
}

void convert_morse(char *str)
{
    if (*str == '\0')
    {
        return;
    }
    else
    {
        recursive_morse(*str);
        convert_morse(str + 1);
    }
}

int main(void)
{
    char input[50];
    printf("Enter the text to convert to Morse code (max 50 characters):\n");
    fgets(input, 50, stdin);
    printf("Morse code: ");
    convert_morse(input);
    printf("\n");
    return 0;
}