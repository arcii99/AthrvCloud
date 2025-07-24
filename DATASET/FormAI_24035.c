//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mind-bending
/* Welcome to the mind-bending world of C compression algorithms! 
   Here's a unique compression algorithm that will blow your mind */

#include <stdio.h>

void mindCompression(char *data)
{
    int i, j, count;
    char compressed[1000];
    int index = 0;
    
    for(i = 0; data[i] != '\0'; i++)
    {
        compressed[index++] = data[i];  // append the character
        
        // check for repeating characters
        for(j = i + 1, count = 1; data[j] == data[i]; j++, count++);
        
        // if repeating characters were found, compress them
        if(count > 1)
        {
            compressed[index++] = count + '0';  // add count as the character after the repeated characters
            i = j - 1;  // update i to skip the characters that have already been compressed
        }
    }
    
    compressed[index] = '\0';  // add null character to indicate end of string
    
    printf("Compressed Data: %s\nOriginal Data: %s\n", compressed, data);
}

int main()
{
    char data[] = "abbcccdddd";  // sample data to compress
    mindCompression(data);  // call the unique compression function
    
    return 0;
}