//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_art(char *input);

int main() {
    char input[100];
    printf("Enter text to convert to ASCII art: ");
    fgets(input, sizeof(input), stdin);
    // remove newline character from input
    input[strcspn(input, "\n")] = 0;
    print_art(input);
    return 0;
}

void print_art(char *input) {
    int width = strlen(input) * 5; // width of art
    int height = 7; // height of art
    char art[height][width+1]; // +1 for null terminator

    // loop through each character in input
    for (int i = 0; i < strlen(input); i++) {
        // calculate starting column for character
        int start_column = i * 5;
        char c = input[i];

        // add character to art array
        if (c == 'A' || c == 'a') {
            sprintf(art[0]+start_column, "  /\\  ");
            sprintf(art[1]+start_column, " /  \\ ");
            sprintf(art[2]+start_column, "/ /\\ \\");
            sprintf(art[3]+start_column, "\\ \\/ /");
            sprintf(art[4]+start_column, " \\  / ");
            sprintf(art[5]+start_column, "  \\/  ");
        } else if (c == 'B' || c == 'b') {
            sprintf(art[0]+start_column, "|||| ");
            sprintf(art[1]+start_column, "|   |");
            sprintf(art[2]+start_column, "|||||");
            sprintf(art[3]+start_column, "|   |");
            sprintf(art[4]+start_column, "|___|");
            sprintf(art[5]+start_column, "     ");
        } else if (c == 'C' || c == 'c') {
            sprintf(art[0]+start_column, "  ___ ");
            sprintf(art[1]+start_column, " / __|");
            sprintf(art[2]+start_column, "/ /_  ");
            sprintf(art[3]+start_column, "\\___\\|");
            sprintf(art[4]+start_column, "      ");
            sprintf(art[5]+start_column, "      ");
        } else {
            // use default art for unknown characters
            sprintf(art[0]+start_column, "     ");
            sprintf(art[1]+start_column, " ____");
            sprintf(art[2]+start_column, "|____|");
            sprintf(art[3]+start_column, "|____|");
            sprintf(art[4]+start_column, "     ");
            sprintf(art[5]+start_column, "     ");
        }
    }

    // print art array
    for (int i = 0; i < height; i++) {
        printf("%s\n", art[i]);
    }
}