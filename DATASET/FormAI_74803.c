//FormAI DATASET v1.0 Category: Text processing ; Style: mind-bending
// Welcome to the Mind-bending Text Processing Program

#include <stdio.h>
#include <string.h>

// Function declaration
void mind_bend(char *str);
void reverse(char *str);
void upper_lower(char *str);

int main()
{
    char str[100];

    printf("Enter the text you want to mind-bend: ");
    fgets(str, 100, stdin);

    // Removing the trailing newline character
    str[strcspn(str, "\n")] = 0;

    mind_bend(str);

    return 0;
}

void mind_bend(char *str)
{
    printf("\n\n⚡️ Mind-bending your text ⚡️\n\n");

    reverse(str);

    upper_lower(str);

    printf("Your mind-bent text is: %s\n\n", str);
}

void reverse(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    printf("Reversed text: %s\n", str);
}

void upper_lower(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            str[i] = toupper(str[i]);
        }
        else
        {
            str[i] = tolower(str[i]);
        }
    }

    printf("Converted text: %s\n", str);
}