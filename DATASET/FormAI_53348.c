//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1024
#define COMMAND_BUFFER_SIZE 128

void checkResponse(char* response)
{
    if(response[0] == '-')
    {
        printf("Error occured: %s", response);
        exit(EXIT_FAILURE);
    }
}

void getUserInput(char* string, int max_length)
{
    fgets(string, max_length, stdin);
    strtok(string, "\n");
}

void printMenu()
{
    printf("\nWhat would you like to do?\n");
    printf("1. View List of Emails\n");
    printf("2. Read an Email\n");
    printf("3. Delete an Email\n");
    printf("4. Exit\n");
    printf("> ");
}

int main(int argc, char* argv[])
{
    char buffer[BUFFER_SIZE], command[COMMAND_BUFFER_SIZE], response[BUFFER_SIZE];
    char user[BUFFER_SIZE], pass[BUFFER_SIZE], email_num[BUFFER_SIZE], server[BUFFER_SIZE];
    int option, num_emails, i;

    printf("Welcome to the POP3 Client!\n");

    printf("Please enter your email address: ");
    getUserInput(user, BUFFER_SIZE);

    printf("Please enter your password: ");
    getUserInput(pass, BUFFER_SIZE);

    printf("Please enter the server address: ");
    getUserInput(server, BUFFER_SIZE);

    // Connect to server
    sprintf(command, "telnet %s 110", server);
    FILE* pop3 = popen(command, "w");
    fputs(buffer, pop3);
    fgets(response, BUFFER_SIZE, pop3);
    checkResponse(response);

    // Login
    sprintf(command, "USER %s\n", user);
    fputs(command, pop3);
    fgets(response, BUFFER_SIZE, pop3);
    checkResponse(response);

    sprintf(command, "PASS %s\n", pass);
    fputs(command, pop3);
    fgets(response, BUFFER_SIZE, pop3);
    checkResponse(response);

    while(1)
    {
        printMenu();

        // Get user option
        scanf("%d", &option);
        getchar(); // remove newline character

        switch(option)
        {
            case 1:
                // List emails
                sprintf(command, "LIST\n");
                fputs(command, pop3);
                fgets(response, BUFFER_SIZE, pop3);
                checkResponse(response);

                num_emails = atoi(strtok(response, " "));
                printf("You have %d emails:\n", num_emails);

                for(i = 0; i < num_emails; i++)
                {
                    fgets(response, BUFFER_SIZE, pop3);
                    printf("%s", response);
                }

                break;
            case 2:
                // Read email
                printf("Please enter email number: ");
                getUserInput(email_num, BUFFER_SIZE);

                sprintf(command, "RETR %s\n", email_num);
                fputs(command, pop3);
                fgets(response, BUFFER_SIZE, pop3);
                checkResponse(response);

                while(1)
                {
                    fgets(response, BUFFER_SIZE, pop3);

                    if(strncmp(response, ".\r\n", 3) == 0)
                        break;

                    printf("%s", response);
                }

                break;
            case 3:
                // Delete email
                printf("Please enter email number: ");
                getUserInput(email_num, BUFFER_SIZE);

                sprintf(command, "DELE %s\n", email_num);
                fputs(command, pop3);
                fgets(response, BUFFER_SIZE, pop3);
                checkResponse(response);

                break;
            case 4:
                // Quit
                sprintf(command, "QUIT\n");
                fputs(command, pop3);
                fgets(response, BUFFER_SIZE, pop3);
                checkResponse(response);

                pclose(pop3);
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}