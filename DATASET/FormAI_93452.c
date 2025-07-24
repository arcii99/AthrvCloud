//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: rigorous
#include <stdio.h>

int main() {
    char input[50];

    printf("Enter text to convert to ASCII art:\n");
    scanf("%[^\n]", input);

    int i;
    for (i = 0; input[i] != '\0'; i++) {

        if (input[i] >= 'a' && input[i] <= 'z') {
            printf("  __  \n");
            printf(" / _\\ \n");
            printf("/    \\\n");
            printf("\\    /\n");
            printf(" \\__/ \n");
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            printf(" _____ \n");
            printf("/__ __\\\n");
            printf("   /  \n");
            printf("  /   \n");
            printf(" /____\\\n");
        } else if (input[i] >= '0' && input[i] <= '9') {
            printf("  __  \n");
            printf(" /_\\ \\\n");
            printf("|   |\n");
            printf("|_\\_|\n");
            printf("      \n");
        } else if (input[i] == ' ') {
            printf("    \n");
            printf("    \n");
            printf("    \n");
            printf("    \n");
            printf("    \n");
        } else {
            printf("      \n");
            printf("\\\\  //\n");
            printf(" \\\\_// \n");
            printf(" //\\\\ \n");
            printf("//  \\\\\n");
        }
    }

    return 0;
}