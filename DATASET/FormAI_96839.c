//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: all-encompassing
#include <stdio.h>

/* Function to translate the input string from Alien Language */
void translate(char* input) {
    int i = 0;
    while(input[i]) {
        char c = input[i];
        int ascii_value = (int) c;
        // Convert ASCII value to corresponding decimal value in the Alien Language
        int alien_value = ascii_value * 2 + 5;
        printf("%d", alien_value);
        i++;
    }
    printf("\n");
}

int main() {
    char input[100];
    printf("Enter a string in Alien Language: ");
    scanf("%s", input);

    printf("The translated string in decimal values is: ");
    translate(input);

    return 0;
}