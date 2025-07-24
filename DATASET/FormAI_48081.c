//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int validateName(char*);

int main()
{
    char name[MAX_LENGTH];
    int nameValidation;

    printf("Enter your name: ");
    fgets(name, MAX_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0;

    nameValidation = validateName(name);

    if(nameValidation == 0)
    {
        printf("Invalid name.\n");
    }
    else
    {
        printf("Valid name.\n");
    }

    return 0;
}

int validateName(char* name)
{
    int i;
    int length = strlen(name);

    if(length == 0 || length > 50)
    {
        return 0;
    }

    for(i = 0; i < length; i++)
    {
        if(isspace(name[i]) || isalpha(name[i]))
        {
            continue;
        }
        else
        {
            return 0;
        }
    }

    return 1;
}