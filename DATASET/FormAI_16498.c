//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function declaration
void translate(char* input_text);

int main()
{
    char input_text[100];

    printf("Welcome to C Cat Language Translator!\n");
    printf("Enter the text you want to translate: ");
    fgets(input_text, 100, stdin);

    translate(input_text);

    return 0;
}

void translate(char* input_text)
{
    char* c_cat_language[] = {"meow", "purr", "hiss", "scratch", "claw", "whisker", "nap"};

    int length = strlen(input_text);

    printf("\nTranslation: ");

    //loop through each character of the input text
    for(int i=0; i<length; i++)
    {
        char current_char = input_text[i];

        switch (current_char) {
            case 'a':
            case 'A':
                printf("%s", c_cat_language[0]);
                break;

            case 'b':
            case 'B':
                printf("%s", c_cat_language[1]);
                break;

            case 'c':
            case 'C':
                printf("%s", c_cat_language[2]);
                break;

            case 'd':
            case 'D':
                printf("%s", c_cat_language[3]);
                break;

            case 'e':
            case 'E':
                printf("%s", c_cat_language[4]);
                break;

            case 'f':
            case 'F':
                printf("%s", c_cat_language[5]);
                break;

            case 'g':
            case 'G':
                printf("%s", c_cat_language[6]);
                break;

            default:
                printf("%c", current_char);
                break;
        } 
    }
}