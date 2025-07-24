//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>

/* Morse Code Dictionary */
const char *morse_code[] =
{
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
    ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--",
    "-..-", "-.--", "--..", " "
};

/* Alphabetical Dictionary */
const char *alphabet[] =
{
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O",
    "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "
};

int main()
{
    char sentence[100];
    printf("Enter a sentence to convert into Morse Code: ");
    fgets(sentence, 100, stdin);  /* Reading Input */
    
    /* Conversion */
    int i, j, flag;
    for (i = 0; i < strlen(sentence); i++)
    {
        flag = 0;
        for (j = 0; j < 26; j++)
        {
            if (toupper(sentence[i]) == alphabet[j][0])
            {
                printf("%s ", morse_code[j]);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("%c ", sentence[i]);
        }
    }

    return 0;
}