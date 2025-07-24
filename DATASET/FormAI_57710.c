//FormAI DATASET v1.0 Category: Data validation ; Style: excited
#include <stdio.h>
#include <ctype.h>

int main()
{
    double num;

    printf("Please enter a number between 0 and 100: ");
    scanf("%lf", &num);

    if(num < 0.0 || num > 100.0) // Check if the number is within the acceptable range
    {
        printf("Invalid input. The number should be between 0 and 100.\n");
        return 1;
    }

    char str[100];

    printf("Please enter a string containing only alphabets: ");
    scanf("%s", str);

    for(int i=0; str[i]!='\0'; i++) // Check if the string contains only alphabets
    {
        if(!isalpha(str[i]))
        {
            printf("Invalid input. The string should contain only alphabets.\n");
            return 1;
        }
    }

    printf("Congratulations! You entered valid data.\n");

    return 0;
}