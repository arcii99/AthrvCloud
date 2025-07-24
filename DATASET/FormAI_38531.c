//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: enthusiastic
// Welcome to the C Cat Language Translator!

// This program is designed to allow humans to communicate with cats in their own language.

// To begin, please enter a message in English:

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    printf("Please enter your message in English: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline character

    printf("Your message in Cat Language: ");

    // Step 1: Replace vowels with "MEOW"
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u')
        {
            printf("MEOW");
        }
        else
        {
            printf("%c", input[i]);
        }
    }

    // Step 2: Add "PURR" to end of message
    printf("PURR\n");

    printf("\nThank you for using the C Cat Language Translator!\n");
    return 0;
}