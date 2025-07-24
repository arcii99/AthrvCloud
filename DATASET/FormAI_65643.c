//FormAI DATASET v1.0 Category: Funny ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* message = "Hello, World!";

    printf("%s\n", message);

    printf("Let's see how many vowels are in the message: ");

    int vowels = 0;

    for(int i = 0; i < strlen(message); i++)
    {
        char c = tolower(message[i]);

        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowels++;
        }
    }

    printf("%d\n", vowels);

    printf("Let's scramble the message by rearranging the letters in each word: ");

    char* newMessage = malloc(sizeof(char) * strlen(message));

    char* word = strtok(message, " ");

    while(word != NULL)
    {
        int length = strlen(word);

        char temp[length];

        for(int i = 0; i < length; i++)
        {
            temp[i] = word[i];
        }

        for(int i = 0; i < length; i++)
        {
            int index = rand() % length;

            char tempChar = temp[i];

            temp[i] = temp[index];

            temp[index] = tempChar;
        }

        strcat(newMessage, temp);

        strcat(newMessage, " ");

        word = strtok(NULL, " ");
    }

    printf("%s\n", newMessage);

    free(newMessage);

    printf("Now let's create a pyramid of the letters in the message: \n");

    int pyramidHeight = strlen(message);

    for(int i = 0; i < pyramidHeight; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("%c ", message[j]);
        }

        printf("\n");
    }

    for(int i = pyramidHeight - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            printf("%c ", message[j]);
        }

        printf("\n");
    }

    return 0;
}