//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char input[1000];
    printf("Enter text to generate ASCII art:");
    fgets(input, 1000, stdin);

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
            case 'a':
                printf("           \n");
                printf("     /\\    \n");
                printf("    /  \\   \n");
                printf("   /____\\  \n");
                printf("  /      \\ \n");
                break;
            case 'b':
                printf(" ________ \n");
                printf(" |       |\n");
                printf(" |_______\\\n");
                printf(" |       |\n");
                printf(" |_______/ \n");
                break;
            case 'c':
                printf("  ______  \n");
                printf(" /      \\\n");
                printf("/        \\\n");
                printf("\\        /\n");
                printf(" \\______/ \n");
                break;

            //remaining letters

            default:
                printf("     _    \n");
                printf("    | |   \n");
                printf("    | |   \n");
                printf("    |_|    \n");
                printf("           \n");
        }
    }
}