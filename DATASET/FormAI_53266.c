//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Function to generate ASCII art of given text
void generateAsciiArt(char text[]) {
    // ASCII art characters for each letter
    char art[26][8][8] = {
        {
            "  _____ ",
            " / ____|",
            "| |     ",
            "| |     ",
            "| |     ",
            "| |____ ",
            " \\_____|",
        }, // A
        {
            "  ______",
            " |___  /",
            "    / / ",
            "   / /  ",
            "  / /   ",
            " / /__  ",
            "/_____| ",
        }, // B
        {
            "  ______",
            " |___  /",
            "    / / ",
            "   / /  ",
            "  / /   ",
            " / /__  ",
            "/_____| ",
        }, // C
        {
            "  _____ ",
            " / ____|",
            "| |     ",
            "| |     ",
            "| |     ",
            "| |____ ",
            " \\_____|",
        }, // D
        {
            " ______ ",
            "|___  / ",
            "   / /  ",
            "  / /   ",
            " / /___ ",
            "/_____/ ",
        }, // E
        {
            " ______ ",
            "|___  / ",
            "   / /  ",
            "  / /   ",
            " / /    ",
            "/_/     ",
        }, // F
        {
            "  ______ ",
            " /  ____|",
            "|  |     ",
            "|  |     ",
            "|  |____ ",
            " \\______|",
        }, // G
        {
            " _    _ ",
            "| |  | |",
            "| |__| |",
            "|  __  |",
            "| |  | |",
            "|_|  |_|",
        }, // H
        {
            " _______",
            "|__   __|",
            "   | |   ",
            "   | |   ",
            "   | |   ",
            "   |_|   ",
        }, // I
        {
            "   _____",
            "  / ____|",
            " | (___  ",
            "  \\___ \\ ",
            "  ____) |",
            " |_____/ ",
        }, // J
        {
            " _    _ ",
            "| |  / /",
            "| |_/ / ",
            "|  __/  ",
            "| |     ",
            "|_|     ",
        }, // K
        {
            " _      ",
            "| |     ",
            "| |     ",
            "| |     ",
            "| |____ ",
            "|______|",
        }, // L
        {
            " __  __ ",
            "|  \\/  |",
            "| \\  / |",
            "| |\\/| |",
            "| |  | |",
            "|_|  |_|",
        }, // M
        {
            " _    _ ",
            "| \\  / |",
            "|  \\/  |",
            "| |\\/| |",
            "| |  | |",
            "|_|  |_|",
        }, // N
        {
            "  _____ ",
            " / ___ \\",
            "| |   | |",
            "| |   | |",
            "| |___| |",
            " \\_____/",
        }, // O
        {
            " ______ ",
            "|___  / ",
            "   / /  ",
            "  / /   ",
            " / /___ ",
            "|_____/ ",
        }, // P
        {
            "  _____ ",
            " / ___ \\",
            "| |   | |",
            "| |   | |",
            "| |___| |",
            " \\____\\_\\",
        }, // Q
        {
            " ______ ",
            "|___  / ",
            "   / /  ",
            "  / /   ",
            " / / \\ \\",
            "|_|  |_|",
        }, // R
        {
            "  _____ ",
            " / ____|",
            "| |     ",
            " \\ \\    ",
            "  \\ \\   ",
            "   \\_\\  ",
        }, // S
        {
            " _______",
            "|__   __|",
            "   | |   ",
            "   | |   ",
            "   | |   ",
            "   |_|   ",
        }, // T
        {
            " _    _ ",
            "| |  | |",
            "| |  | |",
            "| |  | |",
            "| |__| |",
            " \\____/ ",
        }, // U
        {
            "__      __",
            "\\ \\    / /",
            " \\ \\  / / ",
            "  \\ \\/ /  ",
            "   \\  /   ",
            "    \\/    ",
        }, // V
        {
            "__      __",
            "\\ \\    / /",
            " \\ \\  / / ",
            "  \\ \\/ /  ",
            "   \\  /   ",
            "    \\/    ",
        }, // W
        {
            "__   __",
            "\\ \\ / /",
            " \\ V / ",
            "  > <  ",
            " / . \\ ",
            "/_/ \\_\\",
        }, // X
        {
            "__   __",
            "\\ \\ / /",
            " \\ V / ",
            "  \\ /  ",
            "  | |  ",
            "  |_|  ",
        }, // Y
        {
            " ______",
            "|___  /",
            "   / / ",
            "  / /  ",
            " / /__ ",
            "/_____|",
        }, // Z
    };

    // Loop through each row of the ASCII art characters
    for (int i = 0; i < 8; i++) {
        // Loop through each letter in the input text
        for (int j = 0; text[j] != '\0'; j++) {
            // Get the index of the current letter in the ASCII art array
            int letterIndex = (int)text[j] - 65; // Using ASCII values, A = 65

            // Print the ASCII art character for the current letter at the current row
            printf("%s ", art[letterIndex][i]);
        }

        printf("\n"); // Move to the next row
    }
}

int main() {
    // Get input text from user
    char text[100];
    printf("Enter text to convert to ASCII art: ");
    fgets(text, sizeof(text), stdin);

    // Generate ASCII art of the input text
    generateAsciiArt(text);

    return 0;
}