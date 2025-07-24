//FormAI DATASET v1.0 Category: String manipulation ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    char first_name[20];
    char last_name[20];
    char full_name[40];
    int num_chars;
    
    // Get user input for first and last name
    printf("Enter your first name: ");
    scanf("%s", first_name);
    printf("Enter your last name: ");
    scanf("%s", last_name);
    
    // Concatenate first and last name into full name
    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);
    
    // Print full name and number of characters
    printf("Your full name is: %s\n", full_name);
    num_chars = strlen(full_name);
    printf("Your name has %d characters.", num_chars);
    
    return 0;
}