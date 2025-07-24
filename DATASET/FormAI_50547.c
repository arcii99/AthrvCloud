//FormAI DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void compress_string(char *string)
{
    int i, j, count;
    char compressed_string[MAX_SIZE];
    
    // Iterate through input string
    for (i = 0, j = 0; string[i] != '\0'; i++)
    {
        count = 1;
        
        // Count occurrences of each character in string
        while (string[i] == string[i + 1])
        {
            count++;
            i++;
        }
        
        // Add compressed count and current character to new string
        compressed_string[j++] = count + '0';
        compressed_string[j++] = string[i];
    }
    
    // Add null terminator to compressed string
    compressed_string[j] = '\0';
    
    // Print compressed string
    printf("Compressed String: %s\n", compressed_string);
}

int main()
{
    char string[MAX_SIZE];
    
    // Get input string from user
    printf("Enter string to compress: ");
    fgets(string, MAX_SIZE, stdin);
    string[strlen(string) - 1] = '\0';
    
    // Compress input string
    compress_string(string);

    return 0;
}