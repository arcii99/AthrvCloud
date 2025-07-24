//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h>
#include <string.h>

// Define ALIEN LANGUAGE mappings
const char* alienChars[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

char decode(char code) {
    int i;
    for (i = 0; i < sizeof(alienChars); i++) {
        if (code == alienChars[i][0]) {
            return i;
        }
    }
    return '\0';
}

int decodeNumber(char* alienString) {
    int length = strlen(alienString);
    int result = 0;
    int i;
    for (i = length - 1; i >= 0; i--) {
        int decodedValue = decode(alienString[i]); // decode each digit to an integer
        if (decodedValue == '\0') { // if a character cannot be decoded, return an error value
            return -1;
        }
        // multiply each number by 16 raised to the power of its position in the string
        result += decodedValue * pow(16, length - i - 1);
    }
    return result;
}

int main() {
    char alienString[100];
    printf("Enter an Alien Language Number:");
    scanf("%s", alienString);
    int decoded = decodeNumber(alienString);

    if (decoded >= 0) {
        printf("The decoded value is: %d\n", decoded);
    } else {
        printf("Unable to decode Alien Language Number.\n");
    }

    return 0;
}