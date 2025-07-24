//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: funny
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    char output[100];
    
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please enter a sentence in the C Alien language:\n");
    scanf("%[^\n]", input);

    for(int i = 0; i < strlen(input); i++)
    {
        if(input[i] == 'c' || input[i] == 'C')
        {
            output[i] = 'g';
        }
        else if(input[i] == 'a' || input[i] == 'A')
        {
            output[i] = 'l';
        }
        else if(input[i] == 'b' || input[i] == 'B')
        {
            output[i] = 'i';
        }
        else if(input[i] == 'd' || input[i] == 'D')
        {
            output[i] = 'k';
        }
        else if(input[i] == 'e' || input[i] == 'E')
        {
            output[i] = 'o';
        }
        else if(input[i] == 'f' || input[i] == 'F')
        {
            output[i] = 'p';
        }
        else if(input[i] == 'g' || input[i] == 'G')
        {
            output[i] = 'r';
        }
        else if(input[i] == 'h' || input[i] == 'H')
        {
            output[i] = 's';
        }
        else if(input[i] == 'i' || input[i] == 'I')
        {
            output[i] = 'u';
        }
        else if(input[i] == 'j' || input[i] == 'J')
        {
            output[i] = 'w';
        }
        else if(input[i] == 'k' || input[i] == 'K')
        {
            output[i] = 'd';
        }
        else if(input[i] == 'l' || input[i] == 'L')
        {
            output[i] = 'a';
        }
        else if(input[i] == 'm' || input[i] == 'M')
        {
            output[i] = 'z';
        }
        else if(input[i] == 'n' || input[i] == 'N')
        {
            output[i] = 'x';
        }
        else if(input[i] == 'o' || input[i] == 'O')
        {
            output[i] = 'e';
        }
        else if(input[i] == 'p' || input[i] == 'P')
        {
            output[i] = 'f';
        }
        else if(input[i] == 'q' || input[i] == 'Q')
        {
            output[i] = 'y';
        }
        else if(input[i] == 'r' || input[i] == 'R')
        {
            output[i] = 'g';
        }
        else if(input[i] == 's' || input[i] == 'S')
        {
            output[i] = 'h';
        }
        else if(input[i] == 't' || input[i] == 'T')
        {
            output[i] = 'n';
        }
        else if(input[i] == 'u' || input[i] == 'U')
        {
            output[i] = 'i';
        }
        else if(input[i] == 'v' || input[i] == 'V')
        {
            output[i] = 'q';
        }
        else if(input[i] == 'w' || input[i] == 'W')
        {
            output[i] = 'j';
        }
        else if(input[i] == 'x' || input[i] == 'X')
        {
            output[i] = 'n';
        }
        else if(input[i] == 'y' || input[i] == 'Y')
        {
            output[i] = 'q';
        }
        else if(input[i] == 'z' || input[i] == 'Z')
        {
            output[i] = 'm';
        }
        else
        {
            output[i] = input[i];
        }
    }
    
    printf("\nTranslated sentence: %s\n", output);
    printf("Thank you for using the C Alien Language Translator!");

    return 0;
}