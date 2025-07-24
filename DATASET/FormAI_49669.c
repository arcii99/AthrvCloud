//FormAI DATASET v1.0 Category: QR code generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CODE_SIZE 21

// Function to generate a random alphanumeric character
char rand_char() {
    int r = rand() % 62;

    if (r < 26) {
        return (char) (r + 65); // A-Z
    } else if (r < 52) {
        return (char) (r + 71); // a-z
    } else {
        return (char) (r - 4); // 0-9
    }
}

// Function to generate a QR code
void generate_code(char* code) {
    int i;

    // Generate random characters
    for (i = 0; i < CODE_SIZE; i++) {
        code[i] = rand_char();
    }

    // Insert separators
    code[5] = '-';
    code[11] = '-';
    code[17] = '-';

    // Null terminate
    code[CODE_SIZE] = '\0';
}

int main() {
    char code[CODE_SIZE+1];

    // Seed random number generator
    srand(time(NULL));

    // Generate code
    generate_code(code);

    // Print code
    printf("QR Code: %s\n", code);

    return 0;
}