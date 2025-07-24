//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <string.h>

// Declare variables for max and min values in Alien Language
int max = 0;
int min = 1000000;

// Declare a function to convert Alien Language to English
void translate(char *alien, char *english) {
    int i, j;
    // Loop through Alien Language string
    for (i = 0; i < strlen(alien); i += 6) {
        int value = 0;
        // Convert each set of 6 characters to integer
        for (j = 0; j < 6; j++) {
            value <<= 1;
            if (alien[i + j] == '1') {
                value += 1;
            }
        }
        // Check if integer value is the new max or min
        if (value > max) {
            max = value;
        }
        if (value < min) {
            min = value;
        }
        // Convert integer value to corresponding English character
        english[i/6] = (char) (value + 96);
    }
    // Add null terminator to English string
    english[i/6] = '\0';
}

int main() {
    char alienLanguage[] = "1101011101011101011111101111110111101111010110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110";
    char english[900];
    // Call the translate function
    translate(alienLanguage, english);
    // Print Alien Language and corresponding English translations
    printf("Alien Language: %s\n", alienLanguage);
    printf("English: %s\n", english);
    printf("Max value: %d\n", max);
    printf("Min value: %d\n", min);
    return 0;
}