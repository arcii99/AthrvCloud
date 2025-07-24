//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main()
{
    char alienLanguage[] = {'@', '&', '%', '$', '#', '!', '?'};
    char input[100];
    int i, j;

    printf("Welcome to the Alien Language Translator!\n");
    printf("Please enter your message in the alien language:\n");

    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;

    printf("\nTranslating...\n");
    printf("Your message in English is:\n");

    for (i = 0; i < strlen(input); i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (input[i] == alienLanguage[j])
            {
                switch(j)
                {
                    case 0:
                        printf("Romeo, ");
                        break;
                    case 1:
                        printf("O Romeo, ");
                        break;
                    case 2:
                        printf("wherefore art thou Romeo? ");
                        break;
                    case 3:
                        printf("What's in a name? That which we call a rose\nBy any other word would smell as sweet. ");
                        break;
                    case 4:
                        printf("My bounty is as boundless as the sea,\nMy love as deep; the more I give to thee,\nThe more I have, for both are infinite. ");
                        break;
                    case 5:
                        printf("But, soft! what light through yonder window breaks?\nIt is the east, and Juliet is the sun. ");
                        break;
                    case 6:
                        printf("Good night, good night! parting is such sweet sorrow,\nThat I shall say good night till it be morrow. ");
                        break;
                }
            }
        }
    }

    return 0;
}