//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main()
{
    char input[50];
    int num = 0;

    // Welcome the user
    printf("Greetings! My name is Holmes and I'll be assisting you with your hexadecimal conversions today.\n");
    printf("Please enter the hexadecimal value you wish to convert: ");
    fgets(input, 50, stdin);
    
    // Handle input validation
    if (input[0] == '\n')
    {
        printf("I'm sorry, it seems you have not entered a valid hexadecimal value. Please try again.\n");
        return 1;
    }

    // Ensure the input is valid hexadecimal characters
    for(int i = 0; i < strlen(input) - 1; i++)
    {
        char c = input[i];
        if(c >= '0' && c <= '9') {
            num = num * 16 + (c - '0');
        }
        else if(c >= 'A' && c <= 'F') {
            num = num * 16 + (c - 'A' + 10);
        }
        else if(c >= 'a' && c <= 'f') {
            num = num * 16 + (c - 'a' + 10);
        }
        else
        {
            printf("I'm sorry, it seems you have entered an invalid hexadecimal value. Please try again.\n");
            return 1;
        }
    }

    printf("The decimal conversion of the hexadecimal value is: %d\n", num);

    return 0;
}