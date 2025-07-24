//FormAI DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>
#include <ctype.h>

/* This program counts the number of words in a given string */

int main(void)
{
    printf("Enter a string: ");
    
    char string[100];
    fgets(string, 100, stdin); //get string input from user
    
    int count = 0;
    int flag = 0;
    
    for(int i = 0; string[i]!='\0'; i++)
    {
        if(isalpha(string[i])) //check if the character is an alphabet
        {
            if(flag == 0)
            {
                count++; //increment count if alphabet is encountered
                flag = 1;
            }
        }
        else
        {
            flag = 0;
        }
    }
    
    printf("Number of words in the given string: %d", count);
    
    return 0;
}