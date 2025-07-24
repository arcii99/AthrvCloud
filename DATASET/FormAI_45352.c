//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    printf("Welcome to the C Cat Language Translator!\n");
    printf("Enter the sentence you want to translate into C Cat language: ");
    scanf("%[^\n]", input); 
    getchar(); //to flush the new line character from input buffer

    printf("Translation:\n");
    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == ' ')
            printf(" meow");
        else if(input[i] >= 'a' && input[i] <= 'z')
            printf(" purr%c", input[i]);
        else if(input[i] >= 'A' && input[i] <= 'Z')
            printf(" PURR%c", input[i] + 32);
        else
            printf("%c", input[i]);
    }
    printf("\n");
    return 0;
}