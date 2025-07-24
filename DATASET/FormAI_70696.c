//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: systematic
#include <stdio.h>
#include <string.h>

int main()
{

    /* Morse code conversion table */
    const char *morse_code_table[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    /* Character set and morse code for each character */
    const char *characters[] = {
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L",
        "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
        "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
    };

    int i, j;
    char text[100];
    printf("Enter text to be converted to Morse code: ");
    fgets(text, 100, stdin); /* Getting user input */

    /* Removing newline character from the input */
    for(i=0; text[i]; i++)
    {
        if(text[i] == '\n')
        {
            text[i] = '\0';
            break;
        }
    }
  
    int len = strlen(text);

    /* Converting each character of the input to Morse code using the conversion table */
    for(i=0; i<len; i++)
    {
        if(text[i] == ' ')
        {
            printf("/ ");
        }
        else
        {
            for(j=0; j<36; j++)
            {
                if(strncmp(characters[j], &text[i], 1) == 0)
                {
                    printf("%s ", morse_code_table[j]);
                    break;
                }
            }
        }
    }

    printf("\n");

    return 0;
}