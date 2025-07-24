//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));     // Seed random number generator with current time
    int length, num, spec, i, char_type;  // Declare variables
    char password[50] = {0};  // Initialize password array with null values
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";  // Lowercase and uppercase letters
    char numbers[] = "0123456789";  // Numbers
    char special[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?`~";  // Special characters
    printf("Welcome to the Secure Password Generator\n");
    printf("-----------------------------------------\n");
    printf("Enter the desired length of the password: ");
    scanf("%d", &length);   // Take user input for length of password
    printf("How many numbers should be included in the password? ");
    scanf("%d", &num);  // Take user input for number of numbers in password
    printf("How many special characters should be included in the password? ");
    scanf("%d", &spec);  // Take user input for number of special characters in password
    for(i=0; i<length; i++)   // Loop through password characters
    {
        // Determine randomly which type of character to add to the password
        char_type = rand() % 3;  
        if(char_type == 0 && num > 0)  // Add a number to the password if needed
        {
            password[i] = numbers[rand() % 10];
            num--;
        }
        else if(char_type == 1 && spec > 0)  // Add a special character
        {
            password[i] = special[rand() % 29];
            spec--;
        }
        else  // Add a letter
        {
            password[i] = letters[rand() % 52];
        }
    }
    printf("\nYour new secure password is: %s\n", password);  // Print generated password
    return 0;  // End program
}