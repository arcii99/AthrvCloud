//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>

int main()
{
    char C_cat_language[] = {'C', 'C', 'C', 'M', 'E', 'O', 'W', 'O', 'P', 'L'};
    char C_language[10];

    printf("Welcome to the C Cat language translator!\n\n");
    printf("Enter the word in C Cat language (all caps with no spaces): ");

    for(int i=0; i<10; i++)
    {
        scanf("%c", &C_language[i]);

        if(C_language[i] == 'C')
        {
            printf("Meow ");
        }
        else if(C_language[i] == 'M')
        {
            printf("Purr ");
        }
        else if(C_language[i] == 'E')
        {
            printf("Hiss ");
        }
        else if(C_language[i] == 'O')
        {
            printf("Yawn ");
        }
        else if(C_language[i] == 'W')
        {
            printf("Scratch ");
        }
        else if(C_language[i] == 'P')
        {
            printf("Lick ");
        }
        else if(C_language[i] == 'L')
        {
            printf("Jump ");
        }
    }
    printf("\n");

    return 0;
}