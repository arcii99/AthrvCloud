//FormAI DATASET v1.0 Category: Syntax parsing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *token;
    struct node *next;
} Node;

void parseSyntax(char *input)
{
    char *token = strtok(input, " \n\t"); // tokenize input string
    
    Node *head = NULL; // linked list to store tokens
    
    while(token)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->token = token;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }

        token = strtok(NULL, " \n\t"); // get next token
    }

    // Check the syntax
    Node *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->token, "if") == 0 && temp->next == NULL)
            printf("Error: if statement requires a condition.\n");
        else if (strcmp(temp->token, "for") == 0 && temp->next == NULL)
            printf("Error: for loop requires a condition.\n");
        else if (strcmp(temp->token, "while") == 0 && temp->next == NULL)
            printf("Error: while loop requires a condition.\n");
        else if (strcmp(temp->token, "do") == 0 && temp->next != NULL && strcmp(temp->next->token, "while") != 0)
            printf("Error: do-while loop requires a condition.\n");
        else if (strcmp(temp->token, "switch") == 0 && temp->next == NULL)
            printf("Error: switch statement requires a switch expression.\n");
        else if (strcmp(temp->token, "case") == 0 && temp->next == NULL)
            printf("Error: case statement requires a case label.\n");
        else if (strcmp(temp->token, "default") == 0 && temp->next == NULL)
            printf("Error: default statement should be the last in switch case.\n");
        else if (strcmp(temp->token, "{") == 0)
        {
            int count = 0;
            while (temp != NULL)
            {
                if (strcmp(temp->token, "{") == 0)
                    count++;
                else if (strcmp(temp->token, "}") == 0)
                    count--;
                temp = temp->next;
            }
            if (count != 0)
                printf("Error: brackets not matched correctly.\n");
        }
        temp = temp->next;
    }

    // free memory
    temp = head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}

int main()
{
    char input[1000];
    printf("Enter syntax to be parsed: \n");
    fgets(input, 1000, stdin);

    parseSyntax(input);

    return 0;
}