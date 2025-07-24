//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Enter your message in Cat language: ");
    fgets(input, 100, stdin);

    char output[100] = "";
    char* token = strtok(input, " ");

    while (token != NULL)
    {
        if (strcmp(token, "meow") == 0)
        {
            strcat(output, "Hail and well met, noble sir/madam! ");
        }
        else if (strcmp(token, "purr") == 0)
        {
            strcat(output, "Verily, I am content to be in thine company. ");
        }
        else if (strcmp(token, "hiss") == 0)
        {
            strcat(output, "Begone, thou foul beast! ");
        }
        else if (strcmp(token, "scratch") == 0)
        {
            strcat(output, "Methinks I shall require a scratching post anon. ");
        }
        else
        {
            strcat(output, token);
            strcat(output, " ");
        }

        token = strtok(NULL, " ");
    }

    printf("\n\nYour message in medieval style: \n%s\n", output);
    return 0;
}