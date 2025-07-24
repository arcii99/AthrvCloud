//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: excited
#include <stdio.h>   /* Header for Standard I/O operations */
#include <stdlib.h>  /* Header for Standard Library operations */
#include <stdbool.h> /* Header for Boolean operations */

/* This program checks the validity of the input number by calculating its checksum */

int main()
{
    char input_digit;  /* Input digit read from user */
    int digit_count = 0, checksum = 0; /* Count of input digits and checksum value */
    bool is_valid = false; /* Flag to indicate if input number is valid */
    
    printf("Please enter a number to validate (up to 10 digits): ");
    
    /* Read input digits from user until maximum of 10 digits or non-digit character is reached */
    while((input_digit = getchar()) != '\n' && digit_count < 10)
    {
        /* Check if input digit is valid */
        if(input_digit >= '0' && input_digit <= '9')
        {
            /* Convert ASCII digit into integer digit and add to checksum */
            checksum += input_digit - '0';
            digit_count++;
        }
        else
        {
            printf("Invalid input detected. Program terminated.\n");
            return 1;
        }
    }
    
    /* Calculate and validate checksum */
    if(digit_count == 10) /* Check if input number has 10 digits */
    {
        is_valid = (checksum % 10 == 0);
    }
    else if (digit_count == 9) /* Check if input number has 9 digits */
    {
        is_valid = ((checksum + 9) % 10 == 0);
    }
    else if (digit_count == 8) /* Check if input number has 8 digits */
    {
        is_valid = ((checksum + 18) % 10 == 0);
    }
    else
    {
        printf("Invalid input detected. Program terminated.\n");
        return 1;
    }
    
    /* Display input number and validation result */
    if(is_valid)
    {
        printf("The input number is valid!\n");
    }
    else
    {
        printf("The input number is NOT valid!\n");
    }

    /* Happy coding! */
    return 0;
}