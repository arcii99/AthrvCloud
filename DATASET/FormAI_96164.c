//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void alienTranslator(char*, int); // function prototype

int main()
{
    char input[100];
    int length;

    printf("Enter the alien word(s) to translate: ");
    scanf("%[^\n]s", input);  // read input until newline character is encountered
    length = strlen(input);
    
    printf("\nAlien language input: %s\n", input);
    alienTranslator(input, length);

    return 0;
}

void alienTranslator(char *s, int n)
{
    printf("Translation into romantic language: ");

    for(int i=0; i<n; i++)
    {
        if(isalpha(s[i])) // check if character is alphabet
        {
            if(i%2 == 0) // even position character
            {
                if(islower(s[i])) // lower case letter
                    printf("%c", s[i]-32); // convert to upper case and print
                else
                    printf("%c", s[i]); // already an upper case letter
            }
            else // odd position character
            {
                if(isupper(s[i])) // upper case letter
                    printf("%c", s[i]+32); // convert to lower case and print
                else
                    printf("%c", s[i]); // already a lower case letter
            }
        }
        else // not an alphabet
            printf("%c", s[i]); // print as is
    }
    printf("\n");
}