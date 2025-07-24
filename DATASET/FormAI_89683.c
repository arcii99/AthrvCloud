//FormAI DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
/* Romeo and Juliet's Phone Book */

#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, flag = 0;
    char phonebook[5][20] = {"Romeo", "0123456789", "Juliet", "9876543210", "Friar"};

    printf("Welcome to Romeo and Juliet's Phone Book!\n");
    printf("Enter the name of the person you want to search for:\n");
    char name[20];
    scanf("%s", name);

    n = sizeof(phonebook)/sizeof(phonebook[0]);
    for (i = 0; i < n; i += 2)
    {
        if (strcmp(name, phonebook[i]) == 0)
        {
            printf("Found record for %s: %s\n", name, phonebook[i+1]);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("Sorry, could not find a record for %s.\n", name);
        printf("Would you like to add this person to the phone book? (y/n)\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y')
        {
            printf("Enter %s's phone number:\n", name);
            char number[20];
            scanf("%s", number);
            strcat(phonebook[n], name);
            strcat(phonebook[n], number);
            printf("Added %s: %s to the phone book.\n", name, number);
        }
        else
        {
            printf("Goodbye!\n");
        }
    }

    return 0;
}