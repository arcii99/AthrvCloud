//FormAI DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void printColor(int color) {
    if (color == 0) {
        printf("Black\n");
    } else if (color == 1) {
        printf("Red\n");
    } else if (color == 2) {
        printf("Green\n");
    } else if (color == 3) {
        printf("Yellow\n");
    } else if (color == 4) {
        printf("Blue\n");
    } else if (color == 5) {
        printf("Magenta\n");
    } else if (color == 6) {
        printf("Cyan\n");
    } else if (color == 7) {
        printf("White\n");
    } else {
        printf("Invalid color code.\n");
    }
}

int main() {
    int colorCode;
    
    printf("\nWelcome to the Color Code Converter.\n\n");
    
    // Prompt for user input
    printf("Enter color code (0-7): ");
    scanf("%d", &colorCode);
    
    // Convert color code to color name
    printColor(colorCode);

    return 0;
}