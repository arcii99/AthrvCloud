//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
/* Statistical User Input Sanitizer */
/* By AI Chatbot */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX_INPUT_LEN 256 /* Maximum allowable length for user's input */
#define STATS_SIZE 128 /* Maximum number of unique statistics */

/* Function prototypes */
void sanitize_input(char*);
void print_statistics(int[]);

int main()
{
    char input[MAX_INPUT_LEN]; /* Variable to store user's input */
    int statistics[STATS_SIZE] = {0}; /* Variable to store statistics */
    printf("Welcome to the Statistical User Input Sanitizer!\n");
    printf("Please enter any text (up to %d characters): ", MAX_INPUT_LEN-1);
    fgets(input, MAX_INPUT_LEN, stdin);
    printf("You entered: %s\n", input);
    sanitize_input(input);
    printf("After sanitization: %s\n", input);
    for(int i=0; i<strlen(input); i++)
    {
        if(isprint(input[i])) /* Check if character is printable */
        {
            statistics[(int)input[i]]++; /* Update statistics */
        }
    }
    printf("Statistics for input:\n");
    print_statistics(statistics);
    return 0;
}

/* Function to sanitize user input */
void sanitize_input(char* input)
{
    for(int i=0; i<strlen(input); i++)
    {
        if(!isprint(input[i])) /* Check if character is not printable */
        {
            input[i] = ' '; /* Replace with space */
        }
        if(isalpha(input[i])) /* Check if character is alphabetic */
        {
            input[i] = tolower(input[i]); /* Convert to lowercase */
        }
    }
}

/* Function to print statistics */
void print_statistics(int statistics[])
{
    for(int i=0; i<STATS_SIZE; i++)
    {
        if(statistics[i] > 0) /* Check if character appeared at least once */
        {
            printf("%c: %d\n", (char)i, statistics[i]); /* Print character and count */
        }
    }
}