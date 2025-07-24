//FormAI DATASET v1.0 Category: String manipulation ; Style: innovative
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int choice, length, i = 0, j;

    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);

    length = strlen(str);

    do {

        printf("\nPlease select one of the following options:\n\n");

        printf("1. Reverse the string\n");
        printf("2. Count the number of words in the string\n");
        printf("3. Convert the string into uppercase\n");
        printf("4. Convert the string into lowercase\n");
        printf("5. Replace a word in the string\n");
        printf("6. Exit the program\n");

        printf("\nEnter your choice (1-6):\n");
        scanf("%d", &choice);

        getchar(); // to clear the buffer

        switch(choice)
        {
            case 1:
                printf("\nReversed string: ");

                for(i = length-1; i >= 0; i--)
                    printf("%c", str[i]);
                break;

            case 2:
                printf("\nNumber of words in the string: ");

                for(i = 0, j = 0; i < length; i++)
                {
                    if(str[i] == ' ' || str[i] == '\n')
                        j++;
                }

                printf("%d", j);
                break;

            case 3:
                printf("\nUppercase string: ");

                for(i = 0; i < length; i++)
                    printf("%c", toupper(str[i]));
                break;

            case 4:
                printf("\nLowercase string: ");

                for(i = 0; i < length; i++)
                    printf("%c", tolower(str[i]));
                break;

            case 5:
                printf("\nEnter the word you want to replace:\n");
                char word_to_replace[10];
                char new_word[10];
                fgets(word_to_replace, sizeof(word_to_replace), stdin);
                printf("\nEnter the new word:\n");
                fgets(new_word, sizeof(new_word), stdin);

                int found = 0;
                char *pos;

                pos = strstr(str, word_to_replace);

                if(pos != NULL)
                {
                    found = 1;
                    int index = pos - str;

                    int length_difference = strlen(new_word) - strlen(word_to_replace);

                    // Checking if the new word will increase the length of the string or not
                    if(length_difference > 0)
                    {
                        // Shifting the characters towards the end
                        for(i = length - 1; i >= index + strlen(word_to_replace); i--)
                            str[i + length_difference] = str[i];
                    }
                    else if(length_difference < 0)
                    {
                        // Shifting the characters towards the beginning
                        for(i = index + strlen(new_word); i <= length; i++)
                            str[i + length_difference] = str[i];
                    }

                    // Replacing the word with the new one
                    for(i = 0; i < strlen(new_word); i++)
                        str[index + i] = new_word[i];
                }

                if(found)
                    printf("\nString after replacing '%s' with '%s':\n%s", word_to_replace, new_word, str);
                else
                    printf("\nWord not found in the string!");
                break;

            case 6:
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while(choice != 6);

    return 0;
}