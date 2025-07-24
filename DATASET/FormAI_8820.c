//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[100] = "";
    int i, j;

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Type in a sentence in C Cat Language: ");
    gets(input);

    for(i=0; i<strlen(input); i++)
    {
        if(input[i] == 'c' || input[i] == 'C')
        {
            if(i % 2 == 0)
                strcat(output, "meow ");
            else
                strcat(output, "MEOW ");
        }
        else if(input[i] == ' ')
        {
            strcat(output, " ");
        }
        else
        {
            srand(i);
            int rand_num = rand() % 4;
            if(rand_num == 0)
                strcat(output, "purr ");
            else if(rand_num == 1)
                strcat(output, "hiss ");
            else if(rand_num == 2)
                strcat(output, "mrr ");
            else
                strcat(output, "yowl ");
        }
    }

    printf("\nTranslated Sentence: %s\n", output);
    return 0;
}