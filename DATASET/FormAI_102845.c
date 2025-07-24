//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: excited
#include <stdio.h>
#include <string.h>

// Define the Alien Language translation table
char alienTable[26] = {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'};

// Translate a single character to Alien Language
char translateToAlien(char c) {
    if (c >= 'A' && c <= 'Z') {
        return toupper(alienTable[c - 'A']);
    } else if (c >= 'a' && c <= 'z') {
        return alienTable[c - 'a'];
    } else {
        return c;
    }
}

// Translate a string to Alien Language
void translateToAlienString(char *str) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        str[i] = translateToAlien(str[i]);
    }
}

// Test the Alien Language translator
int main() {
    char testString[] = "Hello, World!";
    printf("English: %s\n", testString);
    translateToAlienString(testString);
    printf("Alien Language: %s\n", testString);
    return 0;
}