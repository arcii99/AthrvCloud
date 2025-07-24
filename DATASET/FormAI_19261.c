//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include<stdio.h>
#include<string.h>

int main()
{
    char phrase[1000];//variable to store user input
    printf("Welcome to the C Cat Language Translator\n");

    while(1) //infinite loop
    {
        printf("\nEnter a phrase in C Cat Language or 'exit' to quit: ");
        fgets(phrase, 1000, stdin); //get user input

        if(strcmp(phrase, "exit\n") == 0) //check if user wants to exit
        {
            printf("Goodbye!\n");
            break; //break out of the loop
        }

        //loop through each character of the phrase
        for(int i=0; i<strlen(phrase); i++)
        {
            if(phrase[i] == 'C') //if current character is C
            {
                printf("nya"); //translate to nya
            }
            else if(phrase[i] == 'c') //if current character is c
            {
                printf("meow"); //translate to meow
            }
            else //if current character is not C or c
            {
                printf("%c", phrase[i]); //print the character as is
            }
        }
    }

    return 0;
}