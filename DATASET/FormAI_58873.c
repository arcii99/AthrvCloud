//FormAI DATASET v1.0 Category: Email Client ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to validate an email address
int is_valid_email(char email[])
{
    int at_index = -1, dot_index = -1;
    int i, len = strlen(email);

    // Check if there is only one @ symbol
    for (i = 0; i < len; i++)
    {
        if (email[i] == '@')
        {
            if (at_index != -1)
                return 0; // invalid email address
            at_index = i;
        }
        else if (email[i] == '.')
        {
            dot_index = i;
        }
    }
    if (at_index == -1 || dot_index == -1 || dot_index < at_index)
        return 0; // invalid email address

    // Check if there is some text before and after @ symbol
    if (at_index == 0 || at_index == len - 1)
        return 0; // invalid email address

    // Check if there is at least one letter in the domain name
    for (i = dot_index + 1; i < len; i++)
    {
        if (!isalpha(email[i]))
            return 0; // invalid email address
    }

    return 1; // valid email address
}

// Definition for a singly-linked list Node
struct Node
{
    char *email;
    struct Node *next;
};

// Function to create a new Node
struct Node *create_node(char *email)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->email = (char *)malloc(strlen(email) + 1);
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

int main()
{
    struct Node *contacts = NULL;
    char input[256];

    printf("Welcome to My C Email Client!\n\n");

    // Loop through input until user types "quit"
    while (1)
    {
        printf("Please Enter Your Command: ");
        fgets(input, 256, stdin);
        strtok(input, "\n"); // remove newline character

        // Handle "quit" command
        if (strcmp(input, "quit") == 0)
        {
            printf("\nThank You for Using My C Email Client!\n");
            break;
        }

        // Handle "add" command
        else if (strcmp(input, "add") == 0)
        {
            char email[256];
            printf("Please Enter Email Address: ");
            fgets(email, 256, stdin);
            strtok(email, "\n"); // remove newline character

            if (is_valid_email(email))
            {
                // Create new Node and add it to the linked list
                struct Node *new_node = create_node(email);
                if (contacts == NULL)
                    contacts = new_node;
                else
                {
                    struct Node *temp = contacts;
                    while (temp->next)
                        temp = temp->next;
                    temp->next = new_node;
                }
                printf("%s Added to Contacts.\n", email);
            }
            else
            {
                printf("Invalid Email Address. Please Try Again.\n");
            }
        }

        // Handle "list" command
        else if (strcmp(input, "list") == 0)
        {
            if (contacts == NULL)
            {
                printf("No Contacts Found.\n");
            }
            else
            {
                printf("Your Contacts Are:\n");
                struct Node *temp = contacts;
                while (temp)
                {
                    printf("%s\n", temp->email);
                    temp = temp->next;
                }
            }
        }

        // Handle invalid command
        else
        {
            printf("Invalid Command. Please Try Again.\n");
        }
    }

    // Free allocated memory
    struct Node *temp = contacts;
    while (temp)
    {
        struct Node *next_node = temp->next;
        free(temp->email);
        free(temp);
        temp = next_node;
    }

    // Exit the program
    return 0;
}