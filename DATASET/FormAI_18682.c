//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Welcome to the cheerful C Antivirus scanner!\n");
    printf("Please enter a file path to scan: ");
    fgets(input, sizeof(input), stdin);
    // Remove \n from input
    input[strcspn(input, "\n")] = 0;
    printf("Scanning...\n");

    // Mock virus scanner result - always returns true
    printf("Great news! The file %s is free from viruses!\n", input);
    return 0;
}