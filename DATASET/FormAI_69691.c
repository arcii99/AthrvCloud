//FormAI DATASET v1.0 Category: Data validation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int age;
    char gender;
    float height;

    printf("Please enter your age: ");
    if(scanf("%d", &age) != 1 || age <= 0) // Check if input is numeric and positive
    {
        printf("Invalid input! Please enter a positive number for your age.\n");
        return 0;
    }

    printf("Please enter your gender (m/f): ");
    fflush(stdin); // Clear input buffer
    scanf("%c", &gender);

    if(gender != 'm' && gender != 'f') // Check if input is either 'm' or 'f'
    {
        printf("Invalid input! Please enter 'm' for male and 'f' for female.\n");
        return 0;
    }

    printf("Please enter your height in meters: ");
    if(scanf("%f", &height) != 1 || height <= 0) // Check if input is numeric and positive
    {
        printf("Invalid input! Please enter a positive number for your height.\n");
        return 0;
    }

    printf("Your age is %d, gender is %c, and height is %.2f meters.\n", age, gender, height);

    return 0;
}