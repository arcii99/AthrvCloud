//FormAI DATASET v1.0 Category: System administration ; Style: mind-bending
/* Welcome to the Matrix */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

/* Constant definitions for the program */
#define PASSWORD_LENGTH 10
#define MAX_ATTEMPTS 3

/* Function prototypes */
void create_password(char *password);
bool authenticate(char *password, int attempts);
bool is_valid_choice(char *choice);

int main()
{
    /* Welcome message */
    printf("Welcome to the Matrix.\n");

    /* Generate a random password for the user to authenticate */
    char password[PASSWORD_LENGTH + 1]; // add 1 for null terminator
    create_password(password);

    /* Authenticate the user */
    bool authenticated = false;
    for (int i = 0; i < MAX_ATTEMPTS; i++)
    {
        authenticated = authenticate(password, i + 1);
        if (authenticated)
        {
            printf("Authentication successful.\n");
            break;
        }
        else
        {
            if (i == MAX_ATTEMPTS - 1)
            {
                printf("You have exceeded the maximum number of attempts.\n");
                printf("Program exiting.\n");
                exit(0);
            }
            else
            {
                printf("Authentication failed. Please try again.\n");
            }
        }
    }

    /* Main menu */
    bool exit_program = false;
    while (!exit_program)
    {
        printf("\nPlease choose an option:\n");
        printf("1) Reboot the system\n");
        printf("2) Shutdown the system\n");
        printf("3) Log out of the system\n");
        printf("4) Exit the Matrix\n");

        char choice[2];
        scanf("%s", choice);

        if (is_valid_choice(choice))
        {
            int choice_int = atoi(choice); // convert from string to integer

            switch (choice_int)
            {
                case 1:
                    printf("Rebooting the system...\n");
                    break;
                case 2:
                    printf("Shutting down the system...\n");
                    break;
                case 3:
                    printf("Logging out...\n");
                    exit_program = true;
                    break;
                case 4:
                    printf("Exiting the Matrix...\n");
                    exit(0);
                default:
                    printf("Invalid choice. Please try again.\n");
                    break;
            }
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

/* This function creates a random password */
void create_password(char *password)
{
    srand(time(NULL)); // initialize random seed

    /* Generate random characters in ASCII range 33-126 */
    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        password[i] = rand() % 94 + 33;
    }

    /* Add null terminator */
    password[PASSWORD_LENGTH] = '\0';

    printf("Please enter password to authenticate: %s\n", password);
}

/* This function prompts the user for a password and authenticates it */
bool authenticate(char *password, int attempts)
{
    char user_password[PASSWORD_LENGTH + 1]; // add 1 for null terminator

    /* Prompt the user for the password */
    printf("Please enter password to authenticate (attempt %d of %d): ", attempts, MAX_ATTEMPTS);
    scanf("%s", user_password);

    /* Authenticate the password */
    if (strcmp(user_password, password) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* This function checks if the user's choice is valid */
bool is_valid_choice(char *choice)
{
    /* Check if choice is a single digit */
    if (strlen(choice) == 1 && choice[0] >= '1' && choice[0] <= '4')
    {
        return true;
    }
    else
    {
        return false;
    }
}