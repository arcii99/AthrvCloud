//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 100

void sanitize_input(char input[])
{
    int i, j;
    char temp[BUFFER_SIZE];
    
    for (i = 0, j = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i])) // checks if the character is alphabetic
        {
            temp[j++] = toupper(input[i]); // converts to uppercase and stores in temp
        }
        else if (isdigit(input[i])) // checks if the character is a digit
        {
            temp[j++] = input[i]; // stores the digit as it is in temp
        }
        // for any other characters, it ignores them
    }
    temp[j] = '\0'; // add null character to the end of the string
    
    // copy the sanitized string from temp to input
    for (i = 0; temp[i] != '\0'; i++)
    {
        input[i] = temp[i];
    }
    input[i] = '\0'; // add null character to the end of the string
}

int main()
{
    char input[BUFFER_SIZE];
    
    printf("Enter some input: ");
    fgets(input, BUFFER_SIZE, stdin); // read input from user
    
    sanitize_input(input); // sanitize the input
    
    printf("Sanitized input: %s\n", input); // print the sanitized input
    
    return 0;
}