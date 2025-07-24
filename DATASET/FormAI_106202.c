//FormAI DATASET v1.0 Category: Text processing ; Style: romantic
#include <stdio.h>
#include <string.h>

int main()
{
    char loveNote[1000];
    printf("Enter a love note: ");
    fgets(loveNote, 1000, stdin);

    // Removing trailing new line
    loveNote[strcspn(loveNote, "\n")] = 0;

    char romanticMessage[1000];
    for (int i = 0; i < strlen(loveNote); i++)
    {
        if (loveNote[i] == 'l' || loveNote[i] == 'L')
        {
            strcat(romanticMessage, "I Love You More Than C Language\n");
        }
        else if (loveNote[i] == 'p' || loveNote[i] == 'P')
        {
            strcat(romanticMessage, "You Are My Programming Partner For Life\n");
        }
        else if (loveNote[i] == 'c' || loveNote[i] == 'C')
        {
            strcat(romanticMessage, "You Are My Compiler\n");
        }
        else
        {
            strcat(romanticMessage, "You Are The Reason C Syntax Makes Sense To Me\n");
        }
    }

    printf("Romantic message for your love:\n%s", romanticMessage);

    return 0;
}