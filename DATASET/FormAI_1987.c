//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: paranoid
#include<stdio.h>
#include<string.h>

#define MAX_LENGTH 100

int isParanoid = 1;

void translate(char[], char[]);

int main()
{
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];

    printf("Enter a C Cat Language code snippet: ");
    fgets(input, MAX_LENGTH, stdin);

    translate(input, output);

    if(isParanoid == 1)
        printf("The authorities have been notified!\n");

    printf("Translated output: %s", output);
    return 0;
}

void translate(char input[], char output[])
{
    int length = strlen(input);
    int i;

    for(i=0; i<length; i++)
    {
        switch(input[i])
        {
            case 'm':
                strcat(output, "meow");
                break;

            case 'p':
                strcat(output, "purr");
                break;

            case 'h':
                strcat(output, "hiss");
                break;

            case 'r':
                strcat(output, "rowrr");
                break;

            case 'c':
                strcat(output, "claw");
                break;

            case 'e':
                strcat(output, "eat");
                break;

            case 's':
                strcat(output, "scratch");
                break;

            default:
                strcat(output, "...");
        }

        // There's a 1 in 100 chance of getting caught!
        if(isParanoid == 1 && (rand() % 100) == 0)
        {
            printf("You're being watched!\n");
            isParanoid = 0;
        }
    }
}