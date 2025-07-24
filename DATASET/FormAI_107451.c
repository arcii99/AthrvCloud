//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_INPUT_SIZE 100
#define ASCII_SIZE 7

char ascii_art[10][10][ASCII_SIZE] = {
        {
                "  __  ",
                " /  | ",
                "(_   _|",
                "  | |  ",
                "  | |_ ",
                "  |   |",
                "  |___|"
        },
        {
                "      ",
                "      ",
                "  -|--",
                " / ||_|",
                "   / | ",
                "  /  | ",
                "|___/  "
        },
        {
                " _   ",
                "| |  ",
                "| |_ ",
                "| __|",
                "| |_ ",
                " \\__|",
                "     "
        },
        {
                " ___  ",
                "|__ \\ ",
                "   ) |",
                "  / / ",
                " |_|_ ",
                " (_)__",
                "     /"
        },
        {
                " _   _ ",
                "| \\ | |",
                "|  \\| |",
                "| . ` |",
                "| |\\  |",
                "\\_| \\_/",
                "       "
        },
        {
                "  ___ ",
                " / _ \\",
                "| (_) |",
                " \\__, |",
                "   / / ",
                "  /_/  ",
                "       "
        },
        {
                "   __ ",
                "  / / ",
                " / /_ ",
                "| '_ \\",
                "| (_) |",
                " \\___/ ",
                "       "
        },
        {
                " _   _",
                "| | | |",
                "| | | |",
                "| |_| |",
                " \\___/ ",
                "       ",
                "       "
        },
        {
                "  ___ ",
                " / _ \\",
                "| (_) |",
                " \\__, |",
                "   / / ",
                "  /_/  ",
                "       "
        },
        {
                " __  __",
                "|  \\/  |",
                "| \\  / |",
                "| |\\/| |",
                "| |  | |",
                "|_|  |_|",
                "        "
        }
};

void print_ascii_art(char *word) {
    int len = strlen(word);
    int height = 7;
    int width = (len * 8) - 1;
    char ascii[height][width];
    memset(ascii, ' ', sizeof(ascii));

    for (int i = 0; i < len; i++) {
        char c = word[i];
        if (!isalpha(c)) {
            continue;
        }
        int index = toupper(c) - 'A';
        if (index < 0 || index >= 26) {
            continue;
        }

        int shift = i * 8;
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < ASCII_SIZE; k++) {
                ascii[j][shift + k] = ascii_art[index][j][k];
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char word[MAX_INPUT_SIZE];
    printf("Enter a word: ");
    scanf("%s", word);
    print_ascii_art(word);

    return 0;
}