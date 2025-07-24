//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: ephemeral
#include <stdio.h>

// Function to print ASCII art of a sun
void printSun() {
    printf("   \\   /    \n");
    printf("    .-.     \n");
    printf(" ― (   ) ―  \n");
    printf("    `-’     \n");
    printf("   /   \\    \n");
}

// Function to print ASCII art of a tree
void printTree() {
    printf("     /\\     \n");
    printf("    /  \\    \n");
    printf("   /    \\   \n");
    printf("  /      \\  \n");
    printf(" /________\\ \n");
    printf("      |      \n");
}

int main() {
    // Print the ASCII art of the sun and tree
    printf("Welcome to the ASCII art generator!\n\n");
    printf("Here is the ASCII art of a sun:\n");
    printSun();
    printf("\n");
    printf("And here is the ASCII art of a tree:\n");
    printTree();
    
    return 0;
}