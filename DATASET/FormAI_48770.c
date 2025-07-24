//FormAI DATASET v1.0 Category: Firewall ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <unistd.h>

/* Function prototypes */
void init_firewall();
void add_rule(char* rule);
int io_handler();
void terminate(int signal);

/* Constants */
#define MAX_RULES       1000
#define MAX_INPUT_SIZE  1024
#define MAX_ACL_SIZE    (MAX_RULES * MAX_INPUT_SIZE)

/* Global variables */
char g_acl[MAX_ACL_SIZE];
int g_rule_count = 0;

int main()
{
    init_firewall();

    while (io_handler() == 0);

    return 0;
}

/* Initialize the firewall */
void init_firewall()
{
    /* Clean the access control list */
    memset(g_acl, 0, sizeof(g_acl));
}

/* Add a new rule to the access control list */
void add_rule(char* rule)
{
    /* Check if the rule already exists in the access control list */
    if (strstr(g_acl, rule) != NULL)
    {
        printf("Error: Rule already exists\n");
        return;
    }

    /* Check if the access control list is full */
    if (g_rule_count == MAX_RULES)
    {
        printf("Error: Access control list is full\n");
        return;
    }

    /* Add the rule to the access control list */
    strcat(g_acl, rule);
    strcat(g_acl, "\n");

    /* Increment the rule count */
    g_rule_count++;
}

/* Handle the input/output */
int io_handler()
{
    /* Read the input */
    printf("Enter rule ('exit' to quit): ");
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strlen(input)-1] = '\0';

    /* Check if the user wants to exit */
    if (strcmp(input, "exit") == 0)
    {
        terminate(0);
    }

    /* Parse the input */
    if (strncmp(input, "allow ", 6) == 0 ||
        strncmp(input, "deny ", 5) == 0)
    {
        add_rule(input);
    }
    else
    {
        printf("Error: Invalid input\n");
    }

    return 0;
}

/* Terminate the firewall */
void terminate(int signal)
{
    printf("Stopping firewall\n");
    exit(0);
}