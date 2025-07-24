//FormAI DATASET v1.0 Category: Mailing list manager ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_LIST_SIZE 100

struct entry
{
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

int main()
{
    struct entry list[MAX_LIST_SIZE];
    int count = 0;
    char choice[10];
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    int i;

    while (1)
    {
        printf("\nEnter choice (add/list/delete/quit): ");
        fflush(stdout);
        fgets(choice, 10, stdin);
        choice[strcspn(choice, "\n")] = 0;

        if (strcmp(choice, "quit") == 0)
        {
            break;
        }
        else if (strcmp(choice, "add") == 0)
        {
            printf("Enter name: ");
            fflush(stdout);
            fgets(name, MAX_NAME_LEN, stdin);
            name[strcspn(name, "\n")] = 0;

            // paranoid check for buffer overflow
            if (strnlen(name, MAX_NAME_LEN) == MAX_NAME_LEN && name[MAX_NAME_LEN-1] != '\n')
            {
                printf("Invalid input.\n");
                continue;
            }

            printf("Enter email: ");
            fflush(stdout);
            fgets(email, MAX_EMAIL_LEN, stdin);
            email[strcspn(email, "\n")] = 0;

            // paranoid check for buffer overflow
            if (strnlen(email, MAX_EMAIL_LEN) == MAX_EMAIL_LEN && email[MAX_EMAIL_LEN-1] != '\n')
            {
                printf("Invalid input.\n");
                continue;
            }

            // check if list is full
            if (count >= MAX_LIST_SIZE)
            {
                printf("List is full.\n");
                continue;
            }

            // add entry to list
            strcpy(list[count].name, name);
            strcpy(list[count].email, email);
            count++;

            printf("Entry added.\n");
        }
        else if (strcmp(choice, "list") == 0)
        {
            if (count == 0)
            {
                printf("List is empty.\n");
                continue;
            }

            printf("Name\t\tEmail\n");
            printf("----\t\t-----\n");
            for (i = 0; i < count; i++)
            {
                printf("%s\t\t%s\n", list[i].name, list[i].email);
            }
        }
        else if (strcmp(choice, "delete") == 0)
        {
            if (count == 0)
            {
                printf("List is empty.\n");
                continue;
            }

            printf("Enter name to delete: ");
            fflush(stdout);
            fgets(name, MAX_NAME_LEN, stdin);
            name[strcspn(name, "\n")] = 0;

            // paranoid check for buffer overflow
            if (strnlen(name, MAX_NAME_LEN) == MAX_NAME_LEN && name[MAX_NAME_LEN-1] != '\n')
            {
                printf("Invalid input.\n");
                continue;
            }

            for (i = 0; i < count; i++)
            {
                if (strcmp(list[i].name, name) == 0)
                {
                    // shift remaining entries left
                    for (; i < count - 1; i++)
                    {
                        strcpy(list[i].name, list[i+1].name);
                        strcpy(list[i].email, list[i+1].email);
                    }

                    // clear last entry
                    list[count-1].name[0] = '\0';
                    list[count-1].email[0] = '\0';
                    count--;

                    printf("Entry deleted.\n");
                    break;
                }
            }

            // entry not found
            if (i == count)
            {
                printf("Entry not found.\n");
            }
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}