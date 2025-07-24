//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include<stdio.h>
#include<string.h>

int main() {
    char input[100];
    printf("Enter a line of text: ");
    fgets(input,100,stdin);

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        putchar(input[i]);

        // Replace vowels with "*"
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U') {
            putchar('*');
        }

        // Replace " " with "_"
        if (input[i] == ' ') {
            putchar('_');
        }

        // Rotate letter by 13 (for ROT13 cipher)
        if (input[i] >= 'A' && input[i] <= 'Z') {
            putchar(((input[i] - 'A') + 13) % 26 + 'A');
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            putchar(((input[i] - 'a') + 13) % 26 + 'a');
        }

        // Convert letters to their corresponding ASCII values
        printf("%d ", input[i]);
    }

    return 0;
}