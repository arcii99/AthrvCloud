//FormAI DATASET v1.0 Category: Compression algorithms ; Style: content
/* Unique C Compression Algorithm Example 
   Program by [Your Name] */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to compress the input string */
void compress(char *str)
{
    int len = strlen(str);
    int runLen = 1; // Initialize the count of consecutive characters
    char *result = (char*)malloc(len*sizeof(char));
    int j = 0; // Counter for result array

    /* Traverse through the input string */
    for(int i=1; i<len; i++)
    {
        if(str[i] == str[i-1])
        {
            runLen++; // Count the number of consecutive characters
        }
        else
        {
            /* Store the character and its count in the result array */
            result[j++] = str[i-1];
            result[j++] = runLen+'0'; // Adding the count as a character
            runLen = 1;
        }
    }

    /* Store the last character and its count in the result array */
    result[j++] = str[len-1];
    result[j] = runLen+'0';

    /* Print the compressed string */
    printf("Compressed string: %s\n", result);
}

int main()
{
    char str[100];
    printf("Enter a string to compress: ");
    scanf("%[^\n]s", str); // To read the input string with spaces
    compress(str);
    return 0;
}