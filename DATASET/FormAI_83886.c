//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: complete
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int i, j, len;
    
    printf("Enter a string in the C Alien Language : ");
    fgets(input, 100, stdin); // Reading input from user using fgets() method
    
    len = strlen(input);
    
    for(i=0; i<len; i++)
    {
        if(input[i] == 'X') // Condition to replace X with A
        {
            input[i] = 'A';
        }
        else if(input[i] == 'Y') // Condition to replace Y with B
        {
            input[i] = 'B';
        }
        else if(input[i] == 'Z') // Condition to replace Z with C
        {
            input[i] = 'C';
        }
    }
    
    printf("\nThe input string in human language is : ");
    puts(input); // Printing output to console using puts() method
    
    return 0;
}