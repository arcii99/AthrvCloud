//FormAI DATASET v1.0 Category: Compression algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// function to compress the string using a customized algorithm
void compress_string(char *str)
{
    int length = strlen(str); // get the length of the string 
    char compressed[MAX_SIZE] = ""; // the compressed string
    int i = 0;
    
    while (i < length) // iterate through the original string
    {
        int count = 1; // to count the number of consecutive characters
        int j = i + 1;
        
        // count the number of consecutive characters
        while (j < length && str[i] == str[j])
        {
            count++;
            j++;
        }
        
        // include the character and the count in the compressed string
        if (count == 1)
        {
            strncat(compressed, &str[i], 1);
        }
        else
        {
            char count_str[MAX_SIZE];
            snprintf(count_str, sizeof count_str, "%d", count);
            strncat(compressed, &str[i], 1);
            strcat(compressed, count_str);
        }
        
        i = i + count; // update the index to skip the already counted characters
    }
    
    // copy the compressed string into the original string
    strcpy(str, compressed);
}

// driver code to test the compression algorithm
int main()
{
    char input_string[MAX_SIZE];
    printf("Enter a string to be compressed: ");
    fgets(input_string, MAX_SIZE, stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // remove the newline character
    printf("Original string: %s\n", input_string);
    
    compress_string(input_string);
    printf("Compressed string: %s\n", input_string);
    
    return 0;
}