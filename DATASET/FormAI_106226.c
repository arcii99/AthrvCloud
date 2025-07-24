//FormAI DATASET v1.0 Category: Email Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

char *get_newline_position(char *string);
void strip_newline(char *string);
void print_menu();
void print_error(char *message);
void print_email(char *subject, char *to, char *message);

int main()
{
    char to[MAX_LINE_SIZE], subject[MAX_LINE_SIZE], message[MAX_LINE_SIZE];
    char *newline_position;

    printf("Welcome to the Puzzling Email Client\n\n");

    while(1)
    {
        print_menu();

        fgets(subject, MAX_LINE_SIZE, stdin);
        strip_newline(subject);

        if(strcmp(subject, "exit") == 0)
        {
            printf("Goodbye!\n");
            break;
        }

        printf("To: ");
        fgets(to, MAX_LINE_SIZE, stdin);
        strip_newline(to);

        printf("Message: ");
        fgets(message, MAX_LINE_SIZE, stdin);
        strip_newline(message);

        // Check for an Easter egg
        if(strcmp(subject, "How do you like your eggs?") == 0 &&
           strcmp(to, "Nobody") == 0 &&
           strcmp(message, "You can't make an omelette without breaking some eggs.") == 0)
        {
            printf("*** Congratulations! You found the Easter egg!***\n");
        }
        else
        {
            print_email(subject, to, message);
        }
    }

    return 0;
}

char *get_newline_position(char *string)
{
    char *p = strchr(string, '\n');
    return p;
}

void strip_newline(char *string)
{
    char *p = get_newline_position(string);
    if(p)
    {
        *p = '\0';
    }
}

void print_menu()
{
    printf("Please enter the following information:\n");
    printf("Subject (or 'exit' to quit): ");
}

void print_error(char *message)
{
    printf("\n%s\n\n", message);
}

void print_email(char *subject, char *to, char *message)
{
    printf("\n\n******************************************************************************\n");
    printf("To: %s\n", to);
    printf("Subject: %s\n\n", subject);
    printf("%s\n", message);
    printf("******************************************************************************\n\n");
}