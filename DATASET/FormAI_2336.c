//FormAI DATASET v1.0 Category: Compression algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARACTERS 255

int main()
{
    char *input_text = malloc(MAX_CHARACTERS * sizeof(char));
    printf("Enter the text to be compressed: ");
    fgets(input_text, MAX_CHARACTERS, stdin);
    input_text[strcspn(input_text, "\n")] = '\0'; // Remove trailing newline character
    
    int input_len = strlen(input_text);
    char *compressed_text = malloc((MAX_CHARACTERS + 1) * sizeof(char));
    int compressed_len = 0;
    int count = 1;
    
    // Compress the input text
    for(int i = 0; i < input_len; i++)
    {
        if(i < input_len-1 && input_text[i] == input_text[i+1])
        {
            count++;
        }
        else
        {
            compressed_text[compressed_len++] = input_text[i];
            compressed_len += sprintf(&compressed_text[compressed_len], "%d", count);
            count = 1;
        }
    }
    
    // Print the compressed text
    printf("Compressed Text: %s\n", compressed_text);
    
    free(input_text);
    free(compressed_text);
    
    return 0;
}