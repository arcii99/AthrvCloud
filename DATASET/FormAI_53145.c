//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <string.h>

// Struct to hold ASCII art character data
typedef struct {
    char character;
    int height;
    int width;
    char *data[20];
} Character;

// Array to hold all supported ASCII art characters
Character asciiData[] = {
    {'A', 5, 5, {"  /\\  ", " /  \\ ", "/----\\", "/    \\", "/    \\"}},
    {'B', 5, 5, {"|\\   ", "|\\    ", "|----\\", "|    |", "|____/"}},
    {'C', 5, 5, {"  /\\  ", " /    ", "/      ", "\\      ", " \\__/ "}},
    {'D', 5, 5, {"|\\   ", "| \\    ", "|     ", "|     |", "|____/"}},
    {'E', 5, 5, {"|-----|", "|------", "|      ", "|      ", "|_____|"}},
    // add more ASCII art characters here
};

// Function to get ASCII art data for a given character
Character getAsciiData(char character) {
    for(int i = 0; i < sizeof(asciiData)/sizeof(asciiData[0]); i++) {
        if(asciiData[i].character == character) {
            return asciiData[i];
        }
    }
    Character defaultData = {' ', 1, 1, {" "}};
    return defaultData;
}

// Function to print ASCII art for a given string
void printAsciiArt(char *text) {
    for(int row = 0; row < 5; row++) {
        for(int i = 0; i < strlen(text); i++) {
            Character asciiCharacter = getAsciiData(text[i]);
            printf("%s ", asciiCharacter.data[row]);
        }
        printf("\n");
    }
}

int main() {
    char *text = "HELLO WORLD";
    printAsciiArt(text);
    return 0;
}