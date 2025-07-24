//FormAI DATASET v1.0 Category: Word Count Tool ; Style: retro
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char input[1000]; // declare a character array of size 1000
    int i, count = 1; // initialize count as 1

    printf("Enter a sentence: "); // prompt user for input
    fgets(input, 1000, stdin); // read input
    printf("\n");

    for(i = 0;i < strlen(input);i++) // loop through each character in input
    {
        if(isspace(input[i])) // if a whitespace is found
        {
            count++; // increase word count
        }
    }

    printf("The number of words is: %d", count); // print the word count

    return 0;
}