//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <string.h>

void textToMorseCode(char input[100]); //function prototype

int main()
{
    printf("Enter text to convert to Morse code: ");
    char input[100];
    gets(input);
    textToMorseCode(input); //calling the function
    return 0;
}

void textToMorseCode(char input[100])
{
    printf("\nMorse code output:\n");

    char *morse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." }; //morse code dictionary

    int length = strlen(input);
    for(int i=0;i<length;i++)
    {
        char ch = input[i];
        if(ch == ' ')
        {
            printf(" ");
            continue;
        }
        else if (ch >= 'a' && ch <= 'z')  //lowercase letters
        {
            printf("%s ", morse[ch-97]);
        }
        else if (ch >= 'A' && ch <= 'Z') //uppercase letters
        {
            printf("%s ", morse[ch-65]);
        }
        else if (ch >= '0' && ch <= '9') //numbers
        {
            printf("%s ", morse[ch-48+26]);
        }
    }

    printf("\n"); //new line for better formatting
}