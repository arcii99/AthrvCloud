//FormAI DATASET v1.0 Category: Data validation ; Style: imaginative
/*
 * This is the Data validation program where we are going to validate if the input
 * provided by the user is in a valid format. The program will take input from user
 * and perform various checks on the data. 
 *
 * This code follows all the best practices and coding standards to ensure the code
 * is readable, easy to understand, and scalable.
 *
 * Author: Chatbot
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_AGE_LENGTH 3

// Function to validate the user's input for name field
int validateName(char name[])
{
    int i;

    // Checking if the name contains only alphabets and spaces
    for(i = 0; i < strlen(name); i++)
    {
        if(!isalpha(name[i]) && name[i] != ' ')
        {
            return 0;
        }
    }

    // If ends up coming here, which means name is valid
    return 1;
}

// Function to validate the user's input for age field
int validateAge(char age[])
{
    int i;

    // Checking if the age is a valid number
    for(i = 0; i < strlen(age); i++)
    {
        if(!isdigit(age[i]))
        {
            return 0;
        }
    }

    // If ends up coming here, which means age is valid
    return 1;
}

int main()
{
    char name[MAX_NAME_LENGTH];
    char age[MAX_AGE_LENGTH];
    int isValid = 0;

    // Taking input from user to validate
    printf("Enter your Name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    printf("Enter your Age: ");
    fgets(age, MAX_AGE_LENGTH, stdin);

    // Removing the newline character (\n) from the input
    name[strcspn(name, "\n")] = 0;
    age[strcspn(age, "\n")] = 0;

    // Performing data validation checks
    if(!validateName(name))
    {
        printf("Invalid Name input! Please enter only Alphabets and Spaces.\n");
        isValid = 1;
    }

    if(!validateAge(age))
    {
        printf("Invalid Age input! Please enter only numeric values.\n");
        isValid = 1;
    }

    // If all the fields are valid
    if(isValid == 0)
    {
        printf("\nData Validation Successful!\n");
        printf("Name: %s\n", name);
        printf("Age: %s\n", age);
    }

    return 0;
}