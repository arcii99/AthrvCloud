//FormAI DATASET v1.0 Category: Password management ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{   
    char password[20];
    char confirm_password[20];
    char stored_password[] = "mypassword123"; // our stored password
    int attempts = 3; // number of password attempts allowed

    printf("Welcome to the cheerful Password Management system!\n");
    printf("Please enter your desired password (maximum of 20 characters):\n");

    fgets(password, 20, stdin); // read user input

    while (1) // loop until a valid password is entered
    {
        if (strlen(password) < 8) // check if password meets the length requirement
        {
            printf("Your password needs to be at least 8 characters long.\n");
            printf("Please enter your password again:\n");
            fgets(password, 20, stdin);
        }
        else if (strcmp(password, stored_password) == 0) // check if password matches the stored password
        {
            printf("Congratulations! You've successfully logged in.\n");
            break;
        }
        else // if password doesn't meet requirements or doesn't match stored password
        {
            attempts--;
            printf("Invalid password. Please try again. You have %d attempts left.\n", attempts);
            printf("Please enter your password again:\n");
            fgets(password, 20, stdin);

            if (attempts == 0) // lock out user after three failed attempts
            {
                printf("You have entered an incorrect password too many times. Please contact customer support.\n");
                return 0;
            }
        }
    }

    // Once the user is logged in, we can guide them to change their password if they want

    printf("Would you like to change your password? (Y/N)\n");
    char answer = getchar();
    while(getchar() != '\n'); // flush the input buffer
    if (answer == 'Y' || answer == 'y') // if they want to change password
    {
        printf("Please enter your new password:\n");
        fgets(password, 20, stdin); // get the new password

        while (1) // loop until a valid password is entered
        {
            if (strlen(password) < 8) // check if password meets the length requirement
            {
                printf("Your password needs to be at least 8 characters long.\n");
                printf("Please enter your password again:\n");
                fgets(password, 20, stdin);
            }
            else // if password meets the length requirement
            {
                printf("Please confirm your new password:\n");
                fgets(confirm_password, 20, stdin); // get the confirmation password

                if (strcmp(password, confirm_password) == 0) // if passwords match
                {
                    printf("Your password has been changed successfully!\n");
                    strcpy(stored_password, password); // update the stored password
                    break;
                }
                else // if passwords don't match
                {
                    printf("Your confirmation password doesn't match. Please try again.\n");
                    printf("Please enter your new password again:\n");
                    fgets(password, 20, stdin); // get the new password again
                }
            }
        }
    }

    printf("Thank you for using our cheerful Password Management system! Have a great day!\n");
    return 0;
}