//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the ASCII art
#define MAX_SIZE 200

// Define the character set used for the ASCII art
#define CHAR_SET "@#$%&*+=-:. "

// Define the number of characters in the character set
#define CHAR_SET_SIZE strlen(CHAR_SET)

// Function to convert a given character to its corresponding ASCII art
char* char_to_ascii_art(char c) {
    static char ascii_art[MAX_SIZE];
    int i, j, idx;
    float intensity;

    // Calculate the index of the character in the character set
    idx = ((int) c) % CHAR_SET_SIZE;

    // Calculate the intensity of the character based on its ASCII value
    intensity = ((int) c) / 255.0;

    // Generate the ASCII art for the character based on its intensity
    for (i = 0; i < MAX_SIZE; i++) {
        j = (i % 2 == 0) ? idx : (CHAR_SET_SIZE - 1 - idx);
        ascii_art[i] = (intensity > 0.0) ? CHAR_SET[j] : ' ';
        intensity -= 0.05;
        if (intensity < 0.0)
            intensity = 0.0;
    }
    ascii_art[MAX_SIZE-1] = '\0';

    return ascii_art;
}

int main() {
    char input[MAX_SIZE];
    printf("Enter the text to convert to ASCII art:\n");
    fgets(input, MAX_SIZE-1, stdin);

    printf("ASCII art:\n");
    for (int i = 0; i < strlen(input); i++) {
        printf("%s", char_to_ascii_art(input[i]));
    }

    return 0;
}