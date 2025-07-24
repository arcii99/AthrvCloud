//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: secure
#include <stdio.h>

// Function to print ASCII art of a letter
void printLetter(char letter) {
    switch(letter) {
        case 'a':
            printf("    /\\ \n");
            printf("   /  \\ \n");
            printf("  /----\\\n");
            printf(" /      \\\n");
            printf("/        \\\n");
            break;
        case 'b':
            printf(" ______\n");
            printf("|  ___ \\\n");
            printf("| |   \\ \\\n");
            printf("| |___/ /\n");
            printf("|  ___ \\ \n");
            printf("| |   \\ \\\n");
            printf("|_|    \\_\\\n");
            break;
        // Add more cases for other letters
        default: // If a letter is not recognized, print a space
            printf(" \n");
            printf(" \n");
            printf(" \n");
            printf(" \n");
            printf(" \n");
            break;
    }
}

// Function to print ASCII art of a word
void printWord(char* word) {
    int i = 0;
    while(word[i] != '\0') {
        printLetter(word[i]);
        i++;
    }
}

int main() {
    // Example usage
    char* word = "hello";
    printWord(word);
    return 0;
}