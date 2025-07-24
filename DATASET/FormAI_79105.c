//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
    char message[100];
    printf("Enter message to convert to ASCII art: ");
    fgets(message, sizeof(message), stdin); // read input string from user

    int len = strlen(message);
    char ascii_art[5][100]; // create 2D array to store ASCII art representation

    // convert each character to corresponding ASCII art
    for (int i = 0; i < len; i++) {
        switch(message[i]) {
            case 'A':
            case 'a':
                strcpy(ascii_art[0], "  /\\");
                strcpy(ascii_art[1], " /  \\");
                strcpy(ascii_art[2], "/    \\");
                strcpy(ascii_art[3], "/____\\");
                strcpy(ascii_art[4], "");
                break;
            case 'B':
            case 'b':
                strcpy(ascii_art[0], " ____ ");
                strcpy(ascii_art[1], "| __ )");
                strcpy(ascii_art[2], "|  _ \\");
                strcpy(ascii_art[3], "|____/");
                strcpy(ascii_art[4], "");
                break;
            case 'C':
            case 'c':
                strcpy(ascii_art[0], "  ___ ");
                strcpy(ascii_art[1], " / __|");
                strcpy(ascii_art[2], "| (__ ");
                strcpy(ascii_art[3], " \\___|");
                strcpy(ascii_art[4], "");
                break;
            case 'D':
            case 'd':
                strcpy(ascii_art[0], " ____ ");
                strcpy(ascii_art[1], "|  _ \\");
                strcpy(ascii_art[2], "| | | |");
                strcpy(ascii_art[3], "|____/");
                strcpy(ascii_art[4], "");
                break;
            case 'E':
            case 'e':
                strcpy(ascii_art[0], " _____");
                strcpy(ascii_art[1], "| ___ \\");
                strcpy(ascii_art[2], "| |_/ /");
                strcpy(ascii_art[3], "|____/");
                strcpy(ascii_art[4] ,"");
                break;
            default:
                strcpy(ascii_art[0], "      ");
                strcpy(ascii_art[1], "      ");
                strcpy(ascii_art[2], "      ");
                strcpy(ascii_art[3], "");
                strcpy(ascii_art[4], "");
                break;
        }
        // print ASCII art for each character
        for (int j = 0; j < 5; j++) {
            printf("%s ", ascii_art[j]);
        }
        printf("\n");
    }
    return 0;
}