//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: visionary
#include <stdio.h>

void generateArt(char inputChar) {
    switch (inputChar) {
        case 'A':
            printf("      /\\\n");
            printf("     //\\\\\n");
            printf("    //  \\\\\n");
            printf("   //    \\\\\n");
            printf("  //======\\\\\n");
            printf(" //        \\\\\n");
            printf("//          \\\\\n");
            break;
        case 'B':
            printf(" _______\n");
            printf("|       \\\n");
            printf("|______  \\\n");
            printf("|       \\\n");
            printf("|_______\\\n");
            break;
        case 'C':
            printf("   ______\n");
            printf(" /       \\\n");
            printf("|    ___  \\\n");
            printf("|   /   \\  \\\n");
            printf(" \\        /\n");
            printf("  \\______/\n");
            break;
        // Add more alphabet characters here
        
        default:
            printf("Invalid input character\n");
            break;
    }
}

int main() {
    char inputChar;
    printf("Enter an alphabet character: ");
    scanf("%c", &inputChar);
    generateArt(inputChar);
    return 0;
}