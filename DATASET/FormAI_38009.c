//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: innovative
#include<stdio.h>
#include<string.h>

// Function prototype declaration
void translate(char []);

// Main function
int main()
{
    char phrase[100];

    // Input phrase from the user
    printf("Enter phrase in C Cat Language: ");
    fgets(phrase, 100, stdin);

    // Remove newline character from the end of the phrase
    phrase[strcspn(phrase, "\n")] = '\0';

    // Function call to translate the phrase
    translate(phrase);

    return 0;
}

// Function definition for translation
void translate(char phrase[])
{
    int i, j, len;
    len = strlen(phrase);

    printf("\nTranslation in English: ");

    // Loop through each character of the phrase
    for(i=0; i<len; i++)
    {
        // Condition to check if the character is 'm'
        if(phrase[i] == 'm')
        {
            // If 'm' is found, replace it with 'r'
            printf("r");
        }
        else
        {
            // Otherwise, print the character as it is
            printf("%c", phrase[i]);
        }
    }

    printf("\n");
}