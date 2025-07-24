//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const int MAX_LENGTH = 100;

int main()
{
    char input[MAX_LENGTH];
    printf("Please enter text: ");
    fgets(input, MAX_LENGTH, stdin);
    
    for(int i=0; input[i]!='\0'; i++)
    {
        int ascii = (int) input[i];
        if(isalpha(input[i]))
        {
            // Convert upper case letters to lower case letters
            if(isupper(input[i]))
            {
                ascii += 32;
            }
            
            // Subtract 97 from ASCII value of letter and print corresponding number of spaces
            for(int j=0; j<ascii-97; j++)
            {
                printf(" ");
            }
            // Print the letter as ASCII art
            printf("|   %c   |\n", input[i]);
            for(int j=0; j<ascii-97; j++)
            {
                printf(" ");
            }
            printf(" \\\n");
        }
        else if(isspace(input[i]))
        {
            printf("\n");
        }
        else
        {
            printf("Invalid input: %c\n", input[i]);
        }
    }
    
    return 0;
}