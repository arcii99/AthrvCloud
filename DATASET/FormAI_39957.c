//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
void generate_password()
{
    int length = 10; // Default length of password
    char password[length+1]; // Array to hold password

    // Define possible characters to include in password
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}|;':\"<>,.?/";

    // Define length of each character array
    int lowercase_length = sizeof(lowercase) / sizeof(lowercase[0]) - 1;
    int uppercase_length = sizeof(uppercase) / sizeof(uppercase[0]) - 1;
    int digits_length = sizeof(digits) / sizeof(digits[0]) - 1;
    int symbols_length = sizeof(symbols) / sizeof(symbols[0]) - 1;

    // Seed the random number generator
    srand(time(NULL));

    // Loop to generate password one character at a time
    for (int i = 0; i < length; i++) {
        int category = rand() % 4; // Select category of character to add to password

        switch (category) {
            case 0:
            // Add lowercase character
            password[i] = lowercase[rand() % lowercase_length];
            break;

            case 1:
            // Add uppercase character
            password[i] = uppercase[rand() % uppercase_length];
            break;

            case 2:
            // Add digit character
            password[i] = digits[rand() % digits_length];
            break;

            case 3:
            // Add symbol character
            password[i] = symbols[rand() % symbols_length];
            break;
        }
    }

    // Add null character to end of password string
    password[length] = '\0';

    // Print generated password
    printf("Your new password is: %s\n", password);
}

int main()
{
    printf("Welcome to the Secure Password Generator!\n");
    printf("Generating a secure password...\n");

    // Generate password
    generate_password();

    // Exit program
    return 0;
}