//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

void translate(char message[])
{
    int i;
    for(i = 0; message[i] != '\0'; i++)
    {
        if(message[i] == 'A')
        {
            printf("Y");
        }
        else if(message[i] == 'B')
        {
            printf("Z");
        }
        else if(message[i] >= 'C' && message[i] <= 'Z')
        {
            printf("%c", message[i] - 2);
        }
        else
        {
            printf("%c", message[i]);
        }
    }
}

int main()
{
    char message[100];
    printf("Enter message to translate: ");
    fgets(message, 100, stdin); // read input from user

    translate(message);

    return 0;
}