//FormAI DATASET v1.0 Category: Word Count Tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordCount(char str[], int length);

int main()
{
    char inputString[100];
    printf("Enter a string: ");
    fgets(inputString, 100, stdin);

    // Remove the newline character from inputString
    inputString[strcspn(inputString, "\n")] = 0;
  
    int stringLength = strlen(inputString);
    int count = wordCount(inputString, stringLength);
  
    printf("\nNumber of words in the string: %d", count);
    return 0;
}

int wordCount(char str[], int length)
{
    int count = 1;
    for(int i = 0; i < length - 1; i++)
    {
        // If there is a space or new line, increment the count
        if(str[i] == ' ' || str[i] == '\n')
        {
            count++;
        }
    }
    return count;
}