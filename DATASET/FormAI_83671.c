//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: statistical
#include <stdio.h>
#include <string.h>

char *morse_code[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

char *convert_to_morse(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return morse_code[c - 'A'];
    }

    else if (c >= '0' && c <= '9')
    {
        return morse_code[c - '0' + 26];
    }
    return "";
}

int main()
{
    char input[100];
    printf("Enter text to convert to Morse code:\n");
    fgets(input, 100, stdin);

    int i, j;
    for (i = 0; i < strlen(input); i++)
    {
        char c = input[i];

        if (c == ' ')
        {
            printf("  ");
        }

        else
        {
            char *morse_code = convert_to_morse(toupper(c));

            for (j = 0; j < strlen(morse_code); j++)
            {
                if (morse_code[j] == '.')
                {
                    printf(". ");
                }

                else if (morse_code[j] == '-')
                {
                    printf("- ");
                }
            }

            printf(" ");
        }
    }

    printf("\n");
    return 0;
}