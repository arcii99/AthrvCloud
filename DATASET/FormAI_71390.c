//FormAI DATASET v1.0 Category: Text processing ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char input_string[100];
    int choice, string_length = 0;

    printf("Enter a string:\n");
    fgets(input_string, sizeof(input_string), stdin);
    string_length = strlen(input_string);

    do
    {
        printf("\nChoose an operation to perform:\n");
        printf("1. Convert to uppercase\n");
        printf("2. Convert to lowercase\n");
        printf("3. Replace a character\n");
        printf("4. Reverse the string\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                for (int i = 0; i < string_length; i++)
                {
                    input_string[i] = toupper(input_string[i]);
                }
                printf("Resulting string: %s", input_string);
                break;
            case 2:
                for (int i = 0; i < string_length; i++)
                {
                    input_string[i] = tolower(input_string[i]);
                }
                printf("Resulting string: %s", input_string);
                break;
            case 3:
                char replace_char;
                printf("Enter the character to replace:\n");
                fflush(stdin);
                scanf("%c", &replace_char);
                for (int i = 0; i < string_length; i++)
                {
                    if (input_string[i] == replace_char)
                    {
                        input_string[i] = '_';
                    }
                }
                printf("Resulting string: %s", input_string);
                break;
            case 4:
                for (int i = 0; i < string_length / 2; i++)
                {
                    char temp = input_string[i];
                    input_string[i] = input_string[string_length - 1 - i];
                    input_string[string_length - 1 - i] = temp;
                }
                printf("Resulting string: %s", input_string);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Try again.");
                break;
        }
    } while (choice != 5);

    return 0;
}