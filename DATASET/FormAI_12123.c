//FormAI DATASET v1.0 Category: String manipulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    // Declare a character array of size 100
    char phrase[100];
    int i, j;
   
    // Ask the user to input a phrase
    printf("Enter a phrase: ");
    scanf("%s", phrase);
   
    // Loop through each character in the phrase
    for(i = 0; i < strlen(phrase); i++)
    {
        // If the character is a space, shift the rest of the characters to the left by one position
        if(phrase[i] == ' ')
        {
            for(j = i; j < strlen(phrase); j++)
            {
                phrase[j] = phrase[j+1];
            }
        }
    }
   
    // Print the modified phrase
    printf("The phrase without spaces is: %s", phrase);
   
    return 0;
}