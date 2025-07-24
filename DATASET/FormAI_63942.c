//FormAI DATASET v1.0 Category: Data validation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// function prototypes
int is_int(char *);
int is_float(char *);

int main()
{
    char input[100];

    printf("Welcome to the happy data validation program!\n\n");
    printf("Enter an integer: ");
    fgets(input, sizeof(input), stdin);

    // validate integer input
    while (!is_int(input))
    {
        printf("That's not an integer! Please enter an integer: ");
        fgets(input, sizeof(input), stdin);
    }
    printf("Great job, you entered an integer!\n\n");

    printf("Enter a floating-point number: ");
    fgets(input, sizeof(input), stdin);

    // validate floating point input
    while (!is_float(input))
    {
        printf("That's not a floating-point number! Please enter a floating-point number: ");
        fgets(input, sizeof(input), stdin);
    }
    printf("Awesome, you entered a floating-point number!\n\n");

    printf("Thanks for using the happy data validation program!\n");

    return 0;
}

// function to check if input is an integer
int is_int(char *input)
{
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(input[i]) && !isspace(input[i]))
        {
            return 0;
        }
    }
    return 1;
}

// function to check if input is a floating-point number
int is_float(char *input)
{
    int len = strlen(input);
    int decimal = 0;
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(input[i]) && !isspace(input[i]) && input[i] != '.')
        {
            return 0;
        }
        if (input[i] == '.' && decimal == 0)
        {
            decimal = 1;
        }
        else if (input[i] == '.' && decimal == 1)
        {
            return 0;
        }
    }
    return 1;
}