//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

/* Function to translate C Cat language to English */
int translateCatToEng(char cCat[])
{
    if (strcmp(cCat, "meow") == 0)
    {
        printf("Hello!\n");
        return 1;
    }
    else if (strcmp(cCat, "purr") == 0)
    {
        printf("I am happy.\n");
        return 1;
    }
    else if (strcmp(cCat, "hiss") == 0)
    {
        printf("I am angry.\n");
        return 1;
    }
    else
    {
        printf("Sorry, I don't understand.\n");
        return 0;
    }
}

int main()
{
    char cCat[10];

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter a phrase in C Cat language: ");
    scanf("%s", cCat);

    while (strcmp(cCat, "bye") != 0)
    {
        translateCatToEng(cCat);
        printf("Enter another phrase in C Cat language (type 'bye' to exit): ");
        scanf("%s", cCat);
    }

    printf("Goodbye!\n");
    return 0;
}