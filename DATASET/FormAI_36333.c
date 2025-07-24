//FormAI DATASET v1.0 Category: Word Count Tool ; Style: authentic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIMIT 10000

//Function Prototypes
int count_words(char *string, int length);

int main()
{
    char input_string[MAX_LIMIT];
    int length, word_count;

    printf("Welcome to the C Word Count Tool! \n");
    printf("Please enter a string (maximum 10,000 characters): \n");

    // Takes input from user
    fgets(input_string, MAX_LIMIT, stdin);

    length = strlen(input_string);

    // Calling function count_words
    word_count = count_words(input_string, length);

    printf("The number of words in the string you entered is: %d\n", word_count);

    return 0;
}

//Function to count the number of words
int count_words(char *string, int length)
{
    int count=0;
    int i;

    for(i = 0; i < length; i++)
    {
        // Check for word boundary  
        if(isspace(string[i]) || string[i] == '\0' || string[i] == '\n')
        {
            count++;
        }
    }

    return count;
}