//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>

// Function to convert the input character into ASCII art
void ascii_art(char c)
{
    switch(c)
    {
        case 'A':
            printf("          //\n");
            printf("         // \n");
            printf("        //  \n");
            printf("       //===\n");
            printf("      //   \\\n");
            printf("     //     \\\n");
            printf("    //       \\\n");
            break;
        case 'B':
            printf("  ____ \n");
            printf(" |___ \\\n");
            printf("     \\ \\\n");
            printf("     / /\n");
            printf("    / / \n");
            printf("   /_/  \n");
            break;
        case 'C':
            printf("   _____ \n");
            printf(" / ____|\n");
            printf("| |     \n");
            printf("| |     \n");
            printf("| |___  \n");
            printf(" \\_____|    \n");
            break;
        // Add cases for all the remaining letters and symbols
        default:
            printf("Invalid input!\n");
    }
}

int main()
{
    char input;
    printf("Enter a character: ");
    scanf("%c", &input);
    ascii_art(input);
    return 0;
}