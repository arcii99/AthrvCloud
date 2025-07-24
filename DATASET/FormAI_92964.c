//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WIDTH 70

char* letters[] = {
    "  ___   ",
    " / _ \\  ",
    "| | | | ",
    "| | | | ",
    "| |_| | ",
    " \\___/  ",
    "",
    " __  __ ",
    "|  \\/  |",
    "| \\  / |",
    "| |\\/| |",
    "| |  | |",
    "|_|  |_|",
    "",
    " ____  ",
    "| __ ) ",
    "|  _ \\ ",
    "| |_) |",
    "|____/ ",
    "",
    " _____ ",
    "| ____|",
    "| |__  ",
    "|___ \\ ",
    " ___) |",
    "|____/ ",
    "",
    " _  __",
    "| |/ /",
    "| ' / ",
    "| . \\ ",
    "|_|\\_\\",
    "",
    " ____  ",
    "|  _ \\ ",
    "| |_) |",
    "|  _ < ",
    "|_| \\_\\",
    "",
    "  ___  ",
    " / _ \\ ",
    "| | | |",
    "| |_| |",
    " \\__\\_\\",
    "",
    " _   _ ",
    "| | | |",
    "| |_| |",
    "|  _  |",
    "|_| |_|",
    "",
    "       ",
    "     | |",
    "  ___| |",
    " / _ \\ |",
    "|  __/ |",
    " \\___|_|",
    "",
    " __   __",
    " \\ \\ / /",
    "  \\ V / ",
    "   > <  ",
    "  / . \\ ",
    " /_/ \\_\\",
    "",
    " _  __",
    "| |/ /",
    "| ' / ",
    "| . \\ ",
    "|_|\\_\\",
    "",
    " _____ ",
    "|_   _|",
    "  | |  ",
    "  | |  ",
    " _| |_ ",
    "|_____|",
    "",
    " _   _ ",
    "| | | |",
    "| | | |",
    "| |_| |",
    " \\___/ ",
    "",
    " _     ",
    "| |    ",
    "| |    ",
    "| |___ ",
    "|_____|",
    "",
    " __  __",
    "|  \\/  |",
    "| |\\/| |",
    "| |  | |",
    "|_|  |_|",
    "",
    " __     __",
    " \\ \\   / /",
    "  \\ \\_/ / ",
    "   \\   /  ",
    "    | |   ",
    "    |_|   ",
    "",
    " __   __",
    " \\ \\ / /",
    "  \\ V / ",
    "   | |  ",
    "   |_|  ",
    "",
    " _____ ",
    "|_   _|",
    "  | |  ",
    "  | |  ",
    "  |_|  ",
    "",
    "       ",
    "     | |",
    "  ___| |",
    " / _ \\ |",
    "| (_) |",
    " \\___/ ",
    "",
    "     _ ",
    "    | |",
    " ___| |",
    "/ __| |",
    "\\__ \\_|",
    "|___(_)",
    "",
    " _    _ ",
    "| |  | |",
    "| |  | |",
    "| |__| |",
    " \\____/ ",
    "",
    "       ",
    " _ __  ",
    "| '_ \\ ",
    "| |_) |",
    "| .__/ ",
    "|_|    ",
    "",
    "       ",
    " __  __",
    "|  \\/  |",
    "| |\\/| |",
    "| |  | |",
    "|_|  |_|",
    "",
    "       ",
    " __  __",
    "|  \\/  |",
    "| |\\/| |",
    "| |  | |",
    "|_|  |_|\n"
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    int length = strlen(argv[1]);
    int rows = sizeof(letters) / sizeof(char*);
    int row_width = strlen(letters[0]);
    int art_width = length * row_width;

    if (art_width > MAX_WIDTH * row_width) {
        printf("Input string too long, maximum width is %d characters.\n", MAX_WIDTH);
        return 1;
    }

    char ascii_art[rows][art_width + 1];
    memset(ascii_art, 0, sizeof(ascii_art));

    for (int i = 0; i < length; i++) {
        char character = toupper(argv[1][i]);

        if (character < 'A' || character > 'Z') {
            printf("Invalid character in string: %c\n", character);
            return 1;
        }

        int index = character - 'A';

        for (int j = 0; j < rows; j++) {
            strcat(ascii_art[j], letters[j * 26 + index]);
        }
    }

    for (int i = 0; i < rows; i++) {
        printf("%s\n", ascii_art[i]);
    }

    return 0;
}