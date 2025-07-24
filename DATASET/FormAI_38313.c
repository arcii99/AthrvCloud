//FormAI DATASET v1.0 Category: Online Examination System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function to display the welcome message
void welcome()
{
    printf("\n************   Welcome to the Online Examination System    ************\n");
    printf("---------------------------------------------------------------------\n\n");
}

// Function to display the menu
void menu()
{
    printf("\nChoose the appropriate option below:\n");
    printf("1. Login\n");
    printf("2. Exit\n\n");
}

// Function to validate the user input is a number or not
int isNum(char str[])
{
    int i, len = strlen(str);
    for(i=0; i<len; i++)
    {
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// Function to check the login credentials
int checkLogin(char username[], char password[])
{
    // Here you can implement your own logic to check the login credentials.
    // As this is just an example program, I am always returning successful login.
    return 1;
}

// Function for the exam
void exam()
{
    // Here you can implement your own exam logic
    // As this is just an example program, I am just displaying a message.
    printf("\n\nThis is just an example exam program. You can implement your own exam logic.\n\n");
}

int main()
{
    char option[5], username[30], password[30];
    int choice, isValid;

    // Display the welcome message
    welcome();

    do {
        // Display the menu
        menu();

        // Read the user choice
        printf("Enter your choice: ");
        fgets(option, 5, stdin);

        // Validate the input
        isValid = isNum(option);
        if(!isValid)
        {
            printf("\nInvalid input. Please enter a number!\n");
            continue;
        }

        // Convert the option to integer
        choice = atoi(option);

        switch(choice)
        {
            case 1:
                printf("\n\nWelcome to the Login Portal...\n");

                // Read the username and password
                printf("Enter your username: ");
                fgets(username, 30, stdin);

                printf("Enter your password: ");
                fgets(password, 30, stdin);

                // Remove the newline character from username and password
                username[strcspn(username, "\n")] = 0;
                password[strcspn(password, "\n")] = 0;

                // Check the login credentials
                if(checkLogin(username, password))
                {
                    printf("\n\nCongratulations! Login successfull...\n");

                    // Call the exam function
                    exam();
                }
                else
                {
                    printf("\n\nInvalid username or password. Please try again...\n");
                }
                break;

            case 2:
                printf("\n\nThank you for using the Online Examination System. Goodbye!\n\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please select a valid option!\n");
        }

    } while(1);

    return 0;
}