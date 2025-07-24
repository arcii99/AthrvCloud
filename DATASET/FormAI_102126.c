//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>

// Function to print the "H" character
void printH() {
    printf("    ██\n");
    printf("    ██\n");
    printf("██████\n");
    printf("    ██\n");
    printf("    ██\n\n");
}

// Function to print the "A" character
void printA() {
    printf("██      ██\n");
    printf("██      ██\n");
    printf("██████████\n");
    printf("██      ██\n");
    printf("██      ██\n\n");
}

// Function to print the "P" character
void printP() {
    printf("██████\n");
    printf("██   ██\n");
    printf("██████\n");
    printf("██\n");
    printf("██\n\n");
}

// Function to print the "Y" character
void printY() {
    printf("██      ██\n");
    printf(" ██    ██ \n");
    printf("  ██████  \n");
    printf("   ██ ██  \n");
    printf("   ██ ██  \n\n");
}

int main() {
    printf("\nWelcome to the Happy Text to ASCII Art Generator!\n\n");

    printf("Enter the text you want to convert to ASCII art (Maximum 10 characters): ");
    char text[10];
    fgets(text, 10, stdin);

    printf("\nYour ASCII Art: \n\n");

    // Loop through all characters and print their corresponding ASCII art
    for (int i = 0; text[i] != '\0'; i++) {
        switch (text[i]) {
            case 'H':
                printH();
                break;
            case 'A':
                printA();
                break;
            case 'P':
                printP();
                break;
            case 'Y':
                printY();
                break;
            default:
                printf("Invalid character entered.\n");
                break;
        }
    }

    return 0;
}