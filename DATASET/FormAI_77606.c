//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char* morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    printf("Enter a string to convert to Morse code: ");
    fgets(str, 100, stdin);

    printf("\nMorse code: ");

    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z') // For lowercase letters
        {
            printf("%s ", morse[str[i] - 'a']);
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') // For uppercase letters
        {
            printf("%s ", morse[str[i] - 'A']);
        }
        else if (str[i] == ' ') // For spaces
        {
            printf("  ");
        }
        else // For symbols and numbers (ignored)
        {
            continue;
        }
    }

    return 0;
}