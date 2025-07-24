//FormAI DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_LENGTH 10000 // maximum length of the string

// function to count the number of words in the string
int countWords(char *str)
{
    int count = 0, word_flag = 0; // count is the word count and word_flag is used to check if a word is being processed
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalnum(str[i])) // if character is alphanumeric
        {
            if (!word_flag) // if word_flag is not set, it means we started to process a new word
            {
                word_flag = 1;
                count++;
            }
        }
        else // if character is not alphanumeric
        {
            word_flag = 0;
        }
    }
    return count;
}

// main function
int main()
{
    char str[MAX_LENGTH]; // input string
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin); // get string from user

    int word_count = countWords(str); // get the word count

    printf("The word count in the given string is %d\n", word_count);

    return 0; // exit program
}