//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: authentic
#include<stdio.h>
#include<string.h>

int main()
{
    char input[100], output[100];
    printf("Welcome to the C Cat Language Translator\n");
    printf("Type 'exit' to end the program\n");
    while(1)
    {
        printf("Please enter a sentence in C Cat Language: ");
        fgets(input, 100, stdin);
        //Remove newline character from input string
        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "exit") == 0)
        {
            printf("Exiting the program...\n");
            break;
        }
        else
        {
            //Translate C Cat Language to English
            if(strcmp(input, "meow") == 0)
            {
                strcpy(output, "Hello");
            }
            else if(strcmp(input, "purr") == 0)
            {
                strcpy(output, "Thank you");
            }
            else if(strcmp(input, "hiss") == 0)
            {
                strcpy(output, "Sorry");
            }
            else if(strcmp(input, "scratch") == 0)
            {
                strcpy(output, "I am hungry");
            }
            else if(strcmp(input, "lick") == 0)
            {
                strcpy(output, "I am happy");
            }
            else
            {
                strcpy(output, "I don't understand");
            }

            printf("C Cat Language: %s\n", input);
            printf("English: %s\n", output);
        }
    }
    return 0;
}