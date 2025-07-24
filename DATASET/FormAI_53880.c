//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

// Define the alien language alphabets
#define ALIEN_ALPHABET "qwelkbnmpf"
// Define the real world language alphabets
#define REAL_ALPHABET "abcdefghijklmnopqrstuvwxyz"

// Translate a single letter from alien
char translateLetter(char letter) {
    int position = strchr(ALIEN_ALPHABET, letter) - ALIEN_ALPHABET;
    return position < 0 || position >= strlen(REAL_ALPHABET) ? '?' : REAL_ALPHABET[position];
}

// Translate the entire alien message to real world language
char* translateMessage(char* message) {
    static char buffer[1024];
    for (int i = 0; message[i] != '\0'; i++) {
        buffer[i] = translateLetter(message[i]);
    }
    return buffer;
}

// Main function to accept input and print output
int main() {
    printf("Enter the alien message: ");
    char message[1024];
    scanf("%s", message);
    printf("The translated message is: %s", translateMessage(message));
    return 0;
}