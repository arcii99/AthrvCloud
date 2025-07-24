//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_alpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_numeric(char c)
{
    return (c >= '0' && c <= '9');
}

void convert_to_morse(char *text)
{
    char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", 
                          ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                          "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
                          "/"};
    char *alpha[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                     "s", "t", "u", "v", "w", "x", "y", "z"};

    char *numeric[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};

    int size_text = strlen(text);
    printf("Text to Morse Code: ");
    for (int i = 0; i < size_text; i++)
    {
        if (text[i] == ' ')
        {
            printf("%s ", morse_code[26]);
        }
        else if (is_alpha(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (tolower(text[i]) == alpha[j][0])
                {
                    printf("%s ", morse_code[j]);
                }
            }
        }
        else if (is_numeric(text[i]))
        {
            for (int j = 0; j < 10; j++)
            {
                if (text[i] == numeric[j][0])
                {
                    printf("%s ", morse_code[j + 26]);
                }
            }
        }
        else
        {
            printf("%c ", text[i]);
        }
    }
    printf("\n");
}

int main()
{
    char text[100];

    printf("Enter the Text to Convert to Morse Code: ");
    fgets(text, sizeof(text), stdin);
    convert_to_morse(text);

    return 0;
}