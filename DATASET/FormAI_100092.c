//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100], output[1000] = "";

    printf("Welcome to the C Cat Language Translator! Meow!\n");
    printf("Please input your sentence: ");
    scanf("%[^\n]", input);

    strcat(output, "Meow! ");

    for(int i=0; i<strlen(input); i++)
    {
        switch(input[i])
        {
            case ' ': strcat(output, " Meow!"); break;
            case 'a': strcat(output, " meow"); break;
            case 'b': strcat(output, " meooow"); break;
            case 'c': strcat(output, " meoooww"); break;
            // more cases for the rest of the alphabet
            default: strcat(output, " meoooooooow"); break;
        }
    }

    strcat(output, " Meow!");

    printf("%s\n", output);

    return 0;
}