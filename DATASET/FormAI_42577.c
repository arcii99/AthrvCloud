//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *string)
{
    int i, j, count;
    char compressed[1000];
    int length = strlen(string);
    
    // Compression loop
    for(i = 0, j = 0; i < length;)
    {
        compressed[j++] = string[i];
        count = 1;
        while(string[++i] == compressed[j - 1])
            count++;
        if(count > 1)
        {
            char temp[10];
            sprintf(temp, "%d", count);
            strcat(compressed, temp);
            j += strlen(temp);
        }
    }
    compressed[j] = '\0';
    
    printf("\nCompressed String:\n%s", compressed);
}

int main()
{
    printf("Welcome to the unique compression algorithm program!\n");
    
    char string[1000];
    printf("\nPlease enter the string you would like to compress: ");
    fgets(string, 1000, stdin);
    
    printf("\nYour original string:\n%s", string);
    
    // Call the compression function
    compress(string);
    
    printf("\nThank you for using our program!\n");
    
    return 0;
}