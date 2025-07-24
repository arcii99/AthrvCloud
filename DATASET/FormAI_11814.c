//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include<stdio.h>
#include<ctype.h>

char ascii_art[26][7][6] = { // ASCII art array representing each letter of the alphabet
    { // A
        "  /\\ ",
        " /  \\",
        "/____\\",
        "\\    /",
        " \\  / ",
        "  \\/  "
    },
    { // B
        " ____ ",
        "|    \\",
        "|____/",
        "|    \\",
        "|____/",
        "      "
    },
    { // C
        "  ___ ",
        " /    ",
        "/     ",
        "\\     ",
        " \\___ ",
        "      "
    },
    { // D
        " ____ ",
        "|    \\",
        "|     \\",
        "|     /",
        "|____/",
        "      "
    },
    { // E
        " _____",
        "|    ",
        "|____",
        "|    ",
        "|____",
        "      "
    },
    { // F
        " _____",
        "|    ",
        "|____",
        "|    ",
        "|    ",
        "      "
    },
    { // G
        "  ___ ",
        " /    ",
        "/  __ ",
        "\\    \\",
        " \\___ ",
        "      "
    },
    { // H
        "    ",
        "|   |",
        "|___|",
        "|   |",
        "|   |",
        "     "
    },
    { // I
        "  |  ",
        "  |  ",
        "  |  ",
        "  |  ",
        "__|__",
        "     "
    },
    { // J
        "    |",
        "    |",
        "    |",
        "|   |",
        "|___|",
        "     "
    },
    { // K
        "|   /",
        "|  / ",
        "|/   ",
        "|\\   ",
        "| \\  ",
        "|  \\ "
    },
    { // L
        "|    ",
        "|    ",
        "|    ",
        "|    ",
        "|____",
        "      "
    },
    { // M
        "    ",
        "|\\/|",
        "|  |",
        "|  |",
        "|  |",
        "    "
    },
    { // N
        "    ",
        "|\\  |",
        "| \\ |",
        "|  \\|",
        "|   |",
        "     "
    },
    { // O
        "  ___ ",
        " /   \\",
        "/     \\",
        "\\     /",
        " \\___/ ",
        "       "
    },
    { // P
        " ____ ",
        "|    \\",
        "|____/",
        "|    ",
        "|    ",
        "      "
    },
    { // Q
        "  ___ ",
        " /   \\",
        "/     \\",
        "\\  /\\/",
        " \\_\_\\ ",
        "       "
    },
    { // R
        " ____ ",
        "|    \\",
        "|____/",
        "|\\    ",
        "| \\   ",
        "|  \\  "
    },
    { // S
        "  ___ ",
        "/     ",
        "\\____ ",
        "     \\",
        "_____/",
        "      "
    },
    { // T
        "_______",
        "   |   ",
        "   |   ",
        "   |   ",
        "   |   ",
        "       "
    },
    { // U
        "    ",
        "|   |",
        "|   |",
        "|   |",
        " \\_/ ",
        "     "
    },
    { // V
        "    ",
        "|   |",
        "|   |",
        "|   |",
        " \\_/ ",
        "     "
    },
    { // W
        "      ",
        "|   | |",
        "|   | |",
        "|  / \\|",
        "|_/   |",
        "       "
    },
    { // X
        "\\   /",
        " \\_/ ",
        " / \\ ",
        "|   |",
        " \\_/ ",
        "      "
    },
    { // Y
        "\\   /",
        " \\_/ ",
        " / \\ ",
        "   |  ",
        "   |  ",
        "      "
    },
    { // Z
        " ____",
        "    /",
        "  /  ",
        " /   ",
        "/____",
        "     "
    }
};

int main() {
    char text[100];
    printf("Enter some text (max. 100 characters): ");
    fgets(text, 100, stdin); // input text from user

    printf("\n");

    for (int row = 0; row < 6; row++) { // iterate over rows of the ASCII art
        for (int i = 0; text[i] != '\0'; i++) { // iterate over characters of the input text
            char c = toupper(text[i]); // convert character to uppercase

            if (c >= 'A' && c <= 'Z') { // check if the character is a letter
                printf("%s ", ascii_art[c - 'A'][row]); // print the ASCII art for the letter
            } else {
                printf("      "); // print a blank space
            }
        }
        printf("\n");
    }

    return 0;
}