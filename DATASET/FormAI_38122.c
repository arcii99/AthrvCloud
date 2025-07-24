//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
#include<stdio.h>

// Function to compress the given string using Run Length Encoding algorithm
// The input string may have any character with a count greater than 1
void compress(char* str)
{
    // Initialize variables
    int count = 1;
    char prev = str[0];
    
    // Iterate through the string
    for(int i=1; str[i]!='\0'; i++)
    {
        // If current character is same as previous, increase count
        if(str[i] == prev)
        {
            count++;
        }
        else // Else, print previous character and its count, then update variables
        {
            printf("%c%d", prev, count);
            count = 1;
            prev = str[i];
        }
    }
    
    // Print the last character and its count
    printf("%c%d", prev, count);
}

int main()
{
    // Get input string from user
    char str[1000];
    printf("Enter string to be compressed: ");
    scanf("%s", str);
    
    // Call compression function on given string
    printf("Compressed string: ");
    compress(str);
    
    return 0;
}