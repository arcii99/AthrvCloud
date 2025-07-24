//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Function to generate the ASCII art
void generateAsciiArt(char inputCharacter) {
    char currentChar;

    // Array of strings to store ASCII art alphabet
    char* asciiArtAlphabet[] = {
        " _____________ \n",
        "|      __     |\n",
        "|     /  \\    |\n",
        "|    /    \\   |\n",
        "|   /      \\  |\n",
        "|  /________\\ |\n",
        "|_____________|\n",
        "\n",
        " __  \n",
        "|__) \n",
        "|    \n",
        "\n",
        " __  __ \n",
        "|__)/__`|\n",
        "|  \\.__/ \n",
        "\n",
        "  ___\n",
        " |__ \\\n",
        "    ) |\n",
        "   / / \n",
        "  /_/  \n",
        "\n",
        " ____  \n",
        "|___ \\ \n",
        "  __) |\n",
        " |__ < \n",
        " |___/ \n",
        "\n",
        " _____ \n",
        "|___ / \n",
        "  |_ \\ \n",
        " ___) |\n",
        "|____/ \n",
        "\n",
        "     _ \n",
        "    / |\n",
        "    | |\n",
        "    | |\n",
        "    |_|\n",
        "\n",
        " ______ \n",
        "|___  / \n",
        "   / /  \n",
        "  / /   \n",
        " /_/    \n",
        "\n",
        "  ___  \n",
        " / _ \\ \n",
        "| (_) |\n",
        " \\__, |\n",
        "   /_/ \n",
        "\n",
        "   ___ \n",
        "  / _ \\\n",
        " | (_) |\n",
        "  \\__, |\n",
        "    /_/ \n"
    };

    // Iterate over the ASCII art alphabet to find the matching letter
    for (int i = 0; i < sizeof(asciiArtAlphabet) / sizeof(asciiArtAlphabet[0]); i++) {
        currentChar = asciiArtAlphabet[i][0];

        // If the character matches, print the corresponding ASCII art and break out of the loop
        if (currentChar == inputCharacter) {
            printf("%s", asciiArtAlphabet[i]); 
            break;
        }
    }
}

// Main function
int main() {
    char inputText[50];

    // Get user input text to convert to ASCII art
    printf("Enter text to generate ASCII art:\n");
    fgets(inputText, sizeof(inputText), stdin);

    // Iterate over each character in the input text and generate the corresponding ASCII art
    for (int i = 0; i < sizeof(inputText) / sizeof(inputText[0]); i++) {
        generateAsciiArt(inputText[i]);
    }

    return 0;
}