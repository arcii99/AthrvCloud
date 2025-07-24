//FormAI DATASET v1.0 Category: Error handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>

void handle_error(int error_code);

int main()
{
    int input_num;
    
    printf("Enter a number: ");
    scanf("%d", &input_num);
    
    if(input_num < 0)
    {
        handle_error(-1);
    }
    else if(input_num > 10)
    {
        handle_error(1);
    }
    else
    {
        printf("Your number is valid!\n");
    }
    
    return 0;
}

void handle_error(int error_code)
{
    switch(error_code)
    {
        case -1:
            printf("Error: Number cannot be negative.\n");
            exit(-1);
            break;
        case 1:
            printf("Error: Number cannot be greater than 10.\n");
            exit(-1);
            break;
        default:
            printf("Unknown error occurred.\n");
            break;
    }
}