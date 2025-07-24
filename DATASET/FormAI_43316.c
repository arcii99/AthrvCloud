//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[100];
    char *asciiArt[11][8] = {
        {"   ___  ", "  / _ \\ ", " | (_) |", "  \\__, |", "    /_/ ", "        ", "        ", "        "},
        {"  _ __  ", " | '_ \\ ", " | |_) |", " | .__/ ", " |_|    ", "        ", "        ", "        "},
        {"  ___  ", " |_ _| ", "  | |  ", "   | |  ", "  |___| ", "        ", "        ", "        "},
        {"  ___  ", " |_ _| ", "  | |  ", "  / /   ", " |___| ", "        ", "        ", "        "},
        {"  _  _   ", " | || |  ", " | || |_ ", " |__   _|", "    |_|  ", "         ", "         ", "         "},
        {"  _   _ ", " | | | |", " | |_| |", " |  _  |", " |_| |_|", "        ", "        ", "        "},
        {"  __   ", "  \\ \\  ", "   > > ", "  / /  ", " /_/   ", "       ", "       ", "       "},
        {"      ", "   /\\   ", "  /  \\  ", " / /\\ \\ ", "/__/\\__\\", "        ", "        ", "        "},
        {"       ", "  /\\   ", " /  \\  ", "/ /\\ \\ ", "\\/  \\/ ", "       ", "       ", "       "},
        {"  __   ", " /_ |  ", "  | |   ", "  | |   ", "  | |   ", "      ", "      ", "      "},
        {" ____  ", "|___ \\ ", "  __) |", " |__ < ", " ___) |", "|____/ ", "        ", "        "}
    };
    
    printf("Enter your text: ");
    fgets(text, 100, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character at end
    
    // Print ASCII art representation
    int i, j;
    for(i = 0; i < 11; i++)
    {
        for(j = 0; j < strlen(text); j++)
        {
            if(text[j] >= 'A' && text[j] <= 'Z')
            {
                printf("%s", asciiArt[i][text[j] - 'A']);
            }
            else if(text[j] >= 'a' && text[j] <= 'z')
            {
                printf("%s", asciiArt[i][text[j] - 'a']);
            }
            else
            {
                printf("        ");
            }
        }
        printf("\n");
    }
    
    return 0;
}