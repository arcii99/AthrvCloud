//FormAI DATASET v1.0 Category: Text processing ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[100];
    printf("Enter your message: ");
    fgets(sentence, sizeof(sentence), stdin);

    int length = strlen(sentence);

    printf("\n\nYour message in medieval style: ");

    for(int i = 0; i < length; i++)
    {
        if(sentence[i] >= 'a' && sentence[i] <= 'z')
        {
            printf("%c", sentence[i] - ('a' - 'A'));
        }
        else if(sentence[i] >= 'A' && sentence[i] <= 'Z')
        {
            printf("%c", sentence[i]);
        }
        else if(sentence[i] == ' ')
        {
            printf("%c", sentence[i]);
        }
        else
        {
            printf("%c", sentence[i] + 3);
        }
    }

    printf("\n\n");

    return 0;
}