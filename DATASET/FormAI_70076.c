//FormAI DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[100];
    printf("Enter a sentence: ");
    gets(input); // read in input sentence
    
    int length = strlen(input);
    int i, j;
    for(i=0, j=0; i<length; i++) 
    {
        if(input[i] >= 'a' && input[i] <= 'z') // lower case letter
        {
            output[j++] = input[i] - ('a' - 'A'); // convert to upper case
        }
        else if(input[i] >= 'A' && input[i] <= 'Z') // upper case letter
        {
            output[j++] = input[i] + ('a' - 'A'); // convert to lower case
        }
        else if(input[i] == ' ') // space character
        {
            output[j++] = input[i]; // copy space
        }
        else // any other character
        {
            output[j++] = '*'; // replace with asterisk
        }
    }
    output[j] = '\0'; // terminate output string
    
    printf("Processed sentence: %s\n", output); // print processed sentence
    return 0;
}