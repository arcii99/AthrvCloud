//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

// Morse code lookup table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
    "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", " ", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
    "---..", "----.", "-----"
};

// Character lookup function
char* lookup(char c) {
    if (c >= 'a' && c <= 'z') {
        return morse_table[c - 'a'];
    } else if (c >= '0' && c <= '9') {
        return morse_table[c - '0' + 26];
    } else if (c == ' ') {
        return morse_table[36];
    } else {
        return "";
    }
}

int main() {
    char input[100];
    printf("Enter a message to convert to Morse code: ");
    fgets(input, 100, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    for (int i = 0; i < strlen(input); i++) {
        char *code = lookup(tolower(input[i]));
        printf("%s ", code);
    }
    printf("\n");
    return 0;
}