//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main()
{ 
    //declaring variables
    char input_string[1000], compressed_string[1000];
    int compressed_index = 0, count = 1, i;

    //getting user input
    printf("Enter a string to compress: ");
    fgets(input_string, sizeof(input_string), stdin); 

    //compressing the string
    for (i = 0; i < strlen(input_string); i++) 
    { 
        //checking if character is repeated
        if (input_string[i] == input_string[i + 1]) 
        { 
            count++; 
        } 
        else 
        { 
            //if character is not repeated, then add to compressed string
            compressed_string[compressed_index++] = input_string[i]; 
          
            //adding the count of repeated characters
            if (count > 1) 
            { 
                char count_string[10];
                sprintf(count_string, "%d", count); 
                strcat(compressed_string, count_string); 
                compressed_index = compressed_index + strlen(count_string); 
                count = 1; 
            } 
        } 
    } 
      
    printf("The compressed string is: %s", compressed_string); 

    return 0;
}