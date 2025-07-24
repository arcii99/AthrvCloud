//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int convert_to_decimal(int c) {
    if (c >= '0' && c <= '9') return c - '0';
    c = tolower(c); // Convert to lowercase to simplify the checking process
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return -1; // Invalid input
}

int main() {
    char input[10], *endptr;
    long int result = 0;
    int i;
    printf("Enter a hex color code (without the #): ");
    fgets(input, 10, stdin);

    // Convert input to integer
    for (i = 0; input[i] != '\n' && i < 7; i++) {
        int val = convert_to_decimal(input[i]);
        if (val == -1) {
            printf("Invalid input!\n");
            return 1;
        }
        result = result * 16 + val;
    }

    // Print RGB values
    printf("Red: %ld\n", (result >> 16) & 0xFF);
    printf("Green: %ld\n", (result >> 8) & 0xFF);
    printf("Blue: %ld\n", result & 0xFF);

    return 0;
}