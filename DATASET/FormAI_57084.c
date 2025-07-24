//FormAI DATASET v1.0 Category: Compression algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 

// Function to encode a given string using Run Length Encoding (RLE)
char* encode(char* input_string)
{
    int len = strlen(input_string); 
    
    // Allocate memory for output string
    char* output_string = (char*)malloc(len * 2 + 1);
 
    int count = 1;
    int j = 0;
  
    // Traverse through the input string and encode
    for(int i = 1; i <= len; i++)
    {
        // If the current character is not same as previous
        if(input_string[i] != input_string[i - 1])
        {
            // Append the count of previous character to the output string
            output_string[j++] = input_string[i-1];
            sprintf(&output_string[j], "%d", count);
            j += strlen(&output_string[j]);
            count = 1;
        }
        else
        {
            // Increment count of the character if it is same as previous
            count++;
        }
    }
    
    // Append the last character and its count to the output string
    output_string[j++] = input_string[len - 1];
    sprintf(&output_string[j], "%d", count);
    j += strlen(&output_string[j]);
    output_string[j] = '\0';  // Null terminate the output string
    
    return output_string;
}

// Function to decode a given string using Run Length Encoding (RLE)
char* decode(char* input_string)
{
    int len = strlen(input_string); 
    
    // Allocate memory for output string
    char* output_string = (char*)malloc(MAX_SIZE);
    output_string[0] = '\0'; // Initialize output string to empty
    
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        // Find the current character
        char curr_char = input_string[i];
        
        // Find the count of current character
        while(input_string[i+1] >= '0' && input_string[i+1] <= '9') {
            count = count * 10 + (input_string[++i] - '0');
        }
        
        // Append the current character to the output string count times
        for(int j = 0; j < count; j++) {
            strcat(output_string, &curr_char);
        }
        count = 0;
    }
    
    return output_string;
}

int main()
{
    char input_string[] = "AAAABBBCCDAA"; // String to be encoded and decoded
    char* encoded_string = encode(input_string);  // Encode the input string
    char* decoded_string = decode(encoded_string);  // Decode the encoded string

    printf("Input string: %s\n", input_string);
    printf("Encoded string: %s\n", encoded_string);
    printf("Decoded string: %s\n", decoded_string);

    free(encoded_string);
    free(decoded_string);
    
    return 0;
}