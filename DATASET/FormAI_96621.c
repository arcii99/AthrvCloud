//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    printf("Enter the phrase in C Alien Language: ");
    fgets(input, 1000, stdin);

    char output[1000] = "";
    int i = 0;

    while (input[i] != '\0')
    {
        if (input[i] == 'C')
        {
            strcat(output, "01");
        }
        else if (input[i] == 'A')
        {
            strcat(output, "10");
        }
        else if (input[i] == 'T')
        {
            strcat(output, "11");
        }
        else if (input[i] == ' ')
        {
            strcat(output, " ");
        }
        else
        {
            strcat(output, "*");
        }

        i++;
    }

    printf("Translation into binary: %s\n", output);

    return 0;
}