//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void text_to_morse(char str[]);

int main()
{
    char input[100];

    printf("Enter a string to convert to Morse code:\n");
    fgets(input, 100, stdin);

    text_to_morse(input);

    return 0;
}

void text_to_morse(char str[])
{
    int i, len = strlen(str);
    char morse[100], code[26][6]= {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    for(i = 0; i < len; i++)
    {
        if(isalpha(str[i]))
        {
            memcpy(&morse[i*5], &code[toupper(str[i]) - 'A'], 5);
        }
        else if(str[i] == ' ')
        {
            morse[i*5] = ' ';
        }
        else
        {
            morse[i*5] = ' ';
            printf("Invalid character '%c' in input string. Skipping.\n", str[i]);
        }
    }

    printf("Morse code: %s\n", morse);
}