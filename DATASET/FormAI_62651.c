//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress given string using my unique algorithm "HocusPocus"
char *HocusPocus(char *str)
{
    char *compressed_str = (char *) malloc(sizeof(char) * strlen(str)); // allocate memory to store compressed string
    int count = 1, i, j = 0;
    
    for (i = 0; i < strlen(str); i++) // loop through the characters of given string
    {
        if (str[i] == str[i+1]) // check if current character is same as next one
        {
            count++; // increment count
        }
        else
        {
            compressed_str[j++] = str[i]; // store the character in compressed string
            compressed_str[j++] = (char)(count + '0'); // store the count as character in compressed string
            count = 1; // reset the count
        }
    }
    compressed_str[j] = '\0'; // terminate the string with null character
    
    return compressed_str; // return the compressed string
}

int main()
{
    char str[100], *compressed_str;
    printf("Welcome to HocusPocus Compression Algorithm!\n");
    do {
        printf("Enter any string (or type 'exit' to quit): ");
        scanf("%s", str);
        
        if (strcmp(str, "exit") == 0) { // check if user wants to exit
            printf("Thanks for using HocusPocus; Goodbye!\n");
            break;
        }
        
        compressed_str = HocusPocus(str); // call HocusPocus function to compress the given string
        printf("The compressed string is: %s\n", compressed_str);
        
        free(compressed_str); // free memory allocated to compressed string
    } while (1);
    
    return 0;
}