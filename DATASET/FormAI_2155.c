//FormAI DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int count = 0;
    printf("Enter a string: ");
    fgets(str,100,stdin); // Reads input from user
    
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i] == ' ' || str[i] == '\n') // If string at i contains a space or a newline character
        {
            count++; // Increment count
        }
    }
    if(str[strlen(str) - 1] != ' ' && str[strlen(str) - 1] != '\n') // If last character of string is not space or newline
    {
        count++; // Increment count
    }
        
    printf("Word count: %d", count);
    return 0;
}