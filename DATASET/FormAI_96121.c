//FormAI DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100], newString[100], revString[100], temp;
    int choice, i, j, length;

    printf("Enter a string: ");
    scanf("%s", string);

    length = strlen(string);

    while(1)
    {
        printf("\n--------String Manipulator--------\n");
        printf("1. Reverse the String\n");
        printf("2. Remove a character from the string\n");
        printf("3. Replace a character in the string\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // Reverse the String
                j = 0;
                for(i=length-1; i>=0; i--)
                {
                    revString[j++] = string[i];
                }
                revString[j] = '\0';
                printf("Reversed String: %s\n", revString);
                break;

            case 2:
                // Remove a Character from the String
                printf("Enter the character to remove: ");
                scanf(" %c", &temp);
                j = 0;
                for(i=0; i<length; i++)
                {
                    if(string[i] != temp)
                    {
                        newString[j++] = string[i];
                    }
                }
                newString[j] = '\0';
                printf("String after removing character '%c': %s\n", temp, newString);
                break;

            case 3:
                // Replace a Character in the String
                char oldChar, newChar;
                printf("Enter the character to replace: ");
                scanf(" %c", &oldChar);
                printf("Enter the new character: ");
                scanf(" %c", &newChar);
                for(i=0; i<length; i++)
                {
                    if(string[i] == oldChar)
                    {
                        string[i] = newChar;
                    }
                }
                printf("String after replacing character '%c' with '%c': %s\n", oldChar, newChar, string);
                break;

            case 4:
                // Exit the Program
                printf("Exiting program...\n");
                exit(0);

            default:
                // Invalid input
                printf("Invalid choice, please try again.\n");
                break;
        }

        // Copy the current string to the original string variable
        strcpy(string, newString);
        length = strlen(string);
    }

    return 0;
}