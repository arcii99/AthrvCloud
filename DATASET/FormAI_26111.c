//FormAI DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100 // define maximum word length

int main()
{
    char str[MAX_WORD_LENGTH]; // declare string to read input from user
    int count = 0; // declare integer count to count total number of words
    int i = 0; // declare integer i as a loop counter
    
    printf("Enter a string: ");
    fgets(str, MAX_WORD_LENGTH, stdin); // read string from user
    
    // loop through the string
    while(str[i] != '\0')
    {
        if(isspace(str[i]))
        {
            count++; // increment the count of words
        }
        i++; // increment the loop counter
    }
    
    printf("The number of words in the given string is %d\n", count + 1); // print the total number of words
    
    return 0; // return 0 to exit program
}