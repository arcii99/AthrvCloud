//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generate_password(int length)
{
    char password[length+1];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";
    int charset_size = sizeof(charset) - 1;
    srand(time(NULL));

    // Loop through length and add random characters from charset
    for (int i = 0; i < length; i++)
    {
        password[i] = charset[rand() % charset_size];
    }
    password[length] = '\0';

    // Print the generated password
    printf("\nYour secure password is: %s\n\n", password);
}

int main()
{
    int length;

    // Ask the user to input desired password length
    printf("Welcome to the password generator!\n\n");
    printf("How many characters would you like your password to be? (Between 8 and 50): ");
    scanf("%d", &length);

    // Check if user input is valid
    if (length < 8 || length > 50)
    {
        printf("Invalid input. Password length must be between 8 and 50 characters.\n");
        return 1;
    }

    // Generate the password and show it to the user
    generate_password(length);

    return 0;
}