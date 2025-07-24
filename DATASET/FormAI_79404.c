//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    char alienLang[50][20] = {"Vdfe", "Eze", "Ydu", "Mwq", "Fkw"};
    char humanLang[50][20] = {"Hello", "How", "Are", "You", "Today"};
    char input[20];
    int i, j;

    printf("Welcome to the C Alien Language Translator.\n");
    printf("Please enter a sentence in Alien Language:\n");
    scanf("%[^\n]", input);

    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            printf(" ");
            continue;
        }
        for (j = 0; j < 5; j++)
        {
            if (alienLang[j][0] == input[i])
            {
                printf("%s", humanLang[j]);
                break;
            }
        }
    }
    printf("\nThank you for using the C Alien Language Translator.\n");
    return 0;
}