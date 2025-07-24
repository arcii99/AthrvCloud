//FormAI DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the given text
void compress(char* text)
{
    int len = strlen(text);
    char compressed[5000];
    int i = 0, j = 0;

    // Count the occurrence of each character
    for(i = 0; i < len; i++){
        int count = 1;
        while(i < len-1 && text[i] == text[i+1]){
            count++;
            i++;
        }
        
        // Store the compressed character
        compressed[j++] = text[i];
        if(count > 1){
            char count_str[10];
            sprintf(count_str, "%d", count); // Convert count to string
            for(int k = 0; k < strlen(count_str); k++){
                compressed[j++] = count_str[k]; // Add count to the compressed string
            }
        }
    }

    // Null terminate the compressed string
    compressed[j] = '\0';

    // Print the compressed text
    printf("Compressed text: %s\n", compressed);
}

int main()
{
    char text[5000];
    
    // Get the input text from the user
    printf("Enter the text to compress:\n");
    fgets(text, 5000, stdin);

    // Remove the newline character
    text[strcspn(text, "\n")] = '\0'; 

    // Compress the text
    compress(text);

    return 0;
}