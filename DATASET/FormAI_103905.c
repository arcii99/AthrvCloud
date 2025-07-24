//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert character to binary representation
char* asciiToBinary(int ascii) {
    char *binary = malloc(sizeof(char) * 9);
    int i;
    for (i = 0; i < 8; i++, ascii <<= 1) {
        binary[i] = ((ascii & 0x80) ? '1' : '0');
    }
    binary[i] = '\0';
    return binary;
}

// Function to generate ASCII art from given text
void generateASCIIFromText(char *text) {
    int length = strlen(text);
    int i, j, k;
    for (i = 0; i < length; i++) {
        char *binary = asciiToBinary(text[i]);
        for (j = 0; j < 5; j++) {
            for (k = 0; k < 8; k++) {
                if (binary[k] == '0') {
                    printf(" ");
                } else {
                    printf("*");
                }
            }
            printf("\n");
        }
        free(binary);
    }
}

int main() {
    char *text = "HELLO WORLD";
    
    printf("Generating ASCII art...\n\n");
    generateASCIIFromText(text);
    
    return 0;
}