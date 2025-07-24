//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

// Constants
#define ALIEN_CHARS "rnztfyqwbxpmuhvlosgdjaceki"
#define MAX_INPUT_LENGTH 100

// Function to translate the Alien language to English
void translate(char *alienText) {
    // Loop over each character in the Alien text
    for (int i = 0; i < strlen(alienText); i++) {
        // Find the index of the current Alien character in the ALIEN_CHARS string
        int index = strchr(ALIEN_CHARS, alienText[i]) - ALIEN_CHARS;
        
        // If the character is not found in the ALIEN_CHARS string, ignore it
        if (index < 0) {
            continue;
        }
        
        // Print the English equivalent of the Alien character
        switch (index) {
            case 0:
                printf("a");
                break;
            case 1:
                printf("b");
                break;
            case 2:
                printf("c");
                break;
            case 3:
                printf("d");
                break;
            case 4:
                printf("e");
                break;
            case 5:
                printf("f");
                break;
            case 6:
                printf("g");
                break;
            case 7:
                printf("h");
                break;
            case 8:
                printf("i");
                break;
            case 9:
                printf("j");
                break;
            case 10:
                printf("k");
                break;
            case 11:
                printf("l");
                break;
            case 12:
                printf("m");
                break;
            case 13:
                printf("n");
                break;
            case 14:
                printf("o");
                break;
            case 15:
                printf("p");
                break;
            case 16:
                printf("q");
                break;
            case 17:
                printf("r");
                break;
            case 18:
                printf("s");
                break;
            case 19:
                printf("t");
                break;
            case 20:
                printf("u");
                break;
            case 21:
                printf("v");
                break;
            case 22:
                printf("w");
                break;
            case 23:
                printf("x");
                break;
            case 24:
                printf("y");
                break;
            case 25:
                printf("z");
                break;
            default:
                break;
        }
    }

    printf("\n");
}

// Main function
int main() {
    // Get user input
    char alienText[MAX_INPUT_LENGTH];
    printf("Enter Alien text: ");
    fgets(alienText, MAX_INPUT_LENGTH, stdin);
    
    // Translate the Alien text to English
    translate(alienText);
    
    return 0;
}