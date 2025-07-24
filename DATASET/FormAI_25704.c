//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to convert a character to ASCII art
void printAsciiArt(char c) {
    switch(c) {
        case 'A':
            printf("  /\\ \n");
            printf(" /  \\ \n");
            printf("/----\\ \n");
            printf("\\----/ \n");
            printf(" \\  / \n");
            printf("  \\/ \n");
            break;
        case 'B':
            printf(" ____ \n");
            printf("|__  | \n");
            printf("   | | \n");
            printf("   | | \n");
            printf("   | | \n");
            printf("  _| |_\n");
            break;
        case 'C':
            printf("  ____ \n");
            printf(" /___ \\ \n");
            printf("|    \\ \\\n");
            printf("|     | |\n");
            printf("|     | |\n");
            printf("|____/ / \n");
            break;
        case 'D':
            printf(" _____ \n");
            printf("|  __ \\ \n");
            printf("| |  | |\n");
            printf("| |  | |\n");
            printf("| |__| |\n");
            printf("|_____/ \n");
            break; 
        case 'E':
            printf(" ______\n");
            printf("|  ____|\n");
            printf("| |__   \n");
            printf("|  __|  \n");
            printf("| |____ \n");
            printf("|______|\n");
            break;
        case 'F':
            printf(" ______ \n");
            printf("|  ____|\n");
            printf("| |__   \n");
            printf("|  __|  \n");
            printf("| |     \n");
            printf("|_|     \n");
            break;
        case 'G':
            printf("  _____\n");
            printf(" / ___ \\\n");
            printf("| /   | |\n");
            printf("| |   | |\n");
            printf("| \\___| |\n");
            printf(" \\_____/ \n");
            break;
        case 'H':
            printf(" _    _ \n");
            printf("| |  | |\n");
            printf("| |__| |\n");
            printf("|  __  |\n");
            printf("| |  | |\n");
            printf("|_|  |_|\n");
            break;
        case 'I':
            printf("  ____ \n");
            printf(" |_  _|\n");
            printf("   ||  \n");
            printf("   ||  \n");
            printf(" _ ||_ \n");
            printf("|_____|\n");
            break;
        case 'J':
            printf("      _ \n");
            printf("     | |\n");
            printf("     | |\n");
            printf(" _   | |\n");
            printf("| |__| |\n");
            printf(" \\____/ \n");
            break;
        case 'K':
            printf(" _  __\n");
            printf("| |/ /\n");
            printf("| ' / \n");
            printf("|  <  \n");
            printf("| . \\ \n");
            printf("|_|\\_\\\n");
            break;
        case 'L':
            printf(" _     \n");
            printf("| |    \n");
            printf("| |    \n");
            printf("| |    \n");
            printf("| |____\n");
            printf("|______|\n");
            break;
        case 'M':
            printf(" __  __ \n");
            printf("|  \\/  |\n");
            printf("| \\  / |\n");
            printf("| |\\/| |\n");
            printf("| |  | |\n");
            printf("|_|  |_|\n");
            break;
        case 'N':
            printf(" _   _ \n");
            printf("| \\ | |\n");
            printf("|  \\| |\n");
            printf("| . ` |\n");
            printf("| |\\  |\n");
            printf("|_| \\_|\n");
            break;
        case 'O':
            printf("  ____ \n");
            printf(" /    \\\n");
            printf("| /\\  |\n");
            printf("| | | |\n");
            printf("| \\__/ |\n");
            printf(" \\____/ \n");
            break;
        case 'P':
            printf(" _____ \n");
            printf("|  __ \\\n");
            printf("| |__) |\n");
            printf("|  _  /\n");
            printf("| | \\ \\\n");
            printf("|_|  \\_\\\n");
            break;
        case 'Q':
            printf("  ____  \n");
            printf(" /    \\ \n");
            printf("| /\\  |\n");
            printf("| | | |\n");
            printf("| \\__/ |\n");
            printf(" \\____\\\_\\\n");
            break;
        case 'R':
            printf(" _____ \n");
            printf("|  __ \\\n");
            printf("| |__) |\n");
            printf("|  _  /\n");
            printf("| | \\ \\_\n");
            printf("|_|  \\__|\n");
            break;
        case 'S':
            printf("  _____ \n");
            printf(" / ____|\n");
            printf("| (___ \n");
            printf(" \\___ \\\n");
            printf(" ____\\ |\n");
            printf("|______|\n");
            break;
        case 'T':
            printf(" ______ \n");
            printf("|___  /\n");
            printf("  / / \n");
            printf(" / /  \n");
            printf("/_/   \n");
            printf("       \n");
            break;
        case 'U':
            printf(" _    _ \n");
            printf("| |  | |\n");
            printf("| |  | |\n");
            printf("| |  | |\n");
            printf("| |__| |\n");
            printf(" \\____/ \n");
            break;
        case 'V':
            printf("__      __\n");
            printf("\\ \\    / /\n");
            printf(" \\ \\  / / \n");
            printf("  \\ \\/ /  \n");
            printf("   \\  /   \n");
            printf("    \\/    \n");
            break;
        case 'W':
            printf("__          __\n");
            printf("\\ \\        / /\n");
            printf(" \\ \\  /\\  / / \n");
            printf("  \\ \\/  \\/ /  \n");
            printf("   \\  /\\  /   \n");
            printf("    \\/  \\/    \n");
            break;
        case 'X':
            printf("__   __\n");
            printf("\\ \\ / /\n");
            printf(" \\ V / \n");
            printf("  > <  \n");
            printf(" / . \\ \n");
            printf("/_/ \\_\\\n");
            break;
        case 'Y':
            printf("__     __\n");
            printf("\\ \\   / /\n");
            printf(" \\ \\_/ / \n");
            printf("  \\   /  \n");
            printf("   | |   \n");
            printf("   |_|   \n");
            break;
        case 'Z':
            printf(" ______\n");
            printf("|____  |\n");
            printf("    / / \n");
            printf("   / /  \n");
            printf("  / /   \n");
            printf(" /_/    \n");
            break;
        case ' ':
            printf("\n\n\n\n\n\n");
            break;
        default:
            printf("    ___   \n");
            printf("   /   \\  \n");
            printf("  /  o  \\\n");
            printf(" |      |\n");
            printf("  \\_____/ \n");
    }
}

int main() {
    char input[MAX_LEN];
    printf("Enter a string: ");
    fgets(input, MAX_LEN, stdin);
    input[strcspn(input,"\n")] = '\0'; // Remove \n from input
    
    int len = strlen(input);
    for(int i=0; i<len; i++) {
        printAsciiArt(input[i]);
    }
    return 0;
}