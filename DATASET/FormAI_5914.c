//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>

void printHappy() {
    printf("           *********\n");
    printf("        **;;;;;;;;;;;**\n");
    printf("      **;;;;;\"\";;\"\";;;**\n");
    printf("     *;;;;;/    \\;;;;;;*\n");
    printf("   **;;;;;;  o  o  ;;;;;;**\n");
    printf("  **;;;;;;;;(    );;;;;;;;**\n");
    printf(" **;;;;;__/    \\__/;;;;;;**\n");
    printf("**;;;;;;/  |  |  \\;;;;;;;**\n");
    printf("**;;;;;/____|____\\;;;;;;**\n");
    printf(" **;;;;;;;;;;;;;;;;;;;**\n");
    printf("  **;;;;;;;;;;;;;;%;%%%**\n");
    printf("   **;;;;/~~\\;;;;;;%%%**\n");
    printf("     **;;/    \\;;;;;%%%**\n");
    printf("        ***********%%%%%\n");
    printf("               %%%%%%%\n");
    printf("                %%%%%\n");
}

int main() {
    char text[50];

    printf("Enter some text to convert to ASCII art: ");
    fgets(text, 50, stdin);

    printf("\n%s\n", text);

    // Iterate through each character in the text
    for (int i = 0; text[i] != '\0'; i++) {

        // Convert the character to its ASCII value
        int asciiValue = (int) text[i];

        // Print the corresponding ASCII art for the character
        if (asciiValue >= 65 && asciiValue <= 90) { // Uppercase letters
            asciiValue -= 64; // Convert A-Z to 1-26
            printf("      /\\\\_____/\\\n");
            printf("     / %c _ %c   \\\n", asciiValue + 64, asciiValue + 64);
            printf("    /   (_)     \\\n");
            printf("   / /|       |\\ \\\n");
            printf("  /_/ |_______| \\_\\\n");
        } else if (asciiValue >= 97 && asciiValue <= 122) { // Lowercase letters
            asciiValue -= 96; // Convert a-z to 1-26
            printf("      /\\\\_____/\\\n");
            printf("     / %c _ %c   \\\n", asciiValue + 96, asciiValue + 96);
            printf("    /   (_)     \\\n");
            printf("   / /|       |\\ \\\n");
            printf("  /_/ |_______| \\_\\\n");
        } else if (asciiValue >= 48 && asciiValue <= 57) { // Numbers
            printf("       _____\n");
            printf("     /    %c \\\n", asciiValue);
            printf("    /      |\n");
            printf("   /       |\n");
            printf("  /______/\\|\n");
        } else if (asciiValue == 32) { // Space
            printf("          \n");
            printf("          \n");
            printf("          \n");
            printf("          \n");
            printf("          \n");
        } else { // Other characters
            printf("       _____\n");
            printf("     /      \\\n");
            printf("    /        \\\n");
            printf("   /          \\\n");
            printf("  /____________\\\n");
        }

    }

    printf("\n");

    printHappy();

    return 0;
}