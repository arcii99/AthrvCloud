//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char input[50];
    int i;

    printf("Enter a string: ");
    fgets(input, 50, stdin); /* takes user input */

    for(i = 0; input[i] != '\0'; i++) /* loop through each character */
    {
        /* check if character is a lowercase letter */
        if(input[i] >= 'a' && input[i] <= 'z') 
        {
            input[i] = input[i] - 32; /* convert lowercase to uppercase */
        }
        /* check if character is a symbol or number */
        else if(input[i] < 'A' || (input[i] > 'Z' && input[i] < 'a') || input[i] > 'z')
        {
            input[i] = ' '; /* replace with space */
        }
    }

    printf("Sanitized string: %s\n", input); /* prints sanitized input */

    return 0;
}