//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    int length = strlen(input);

    char reversed[length + 1];
    int count = 0;
    for (int i = length - 1; i >= 0; i--) {
        reversed[count++] = input[i];
    }
    reversed[count] = '\0';

    printf("Reversed string: %s\n", reversed);

    char vowels[length + 1];
    char consonants[length + 1];
    int vcount = 0;
    int ccount = 0;
    for (int i = 0; i < length; i++) {
        char c = input[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels[vcount++] = c;
        } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            consonants[ccount++] = c;
        }
    }
    vowels[vcount] = '\0';
    consonants[ccount] = '\0';

    printf("Vowels: %s\n", vowels);
    printf("Consonants: %s\n", consonants);

    char swapped[length + 1];
    for (int i = 0; i < length; i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z') {
            swapped[i] = c - 'a' + 'A';
        } else if (c >= 'A' && c <= 'Z') {
            swapped[i] = c - 'A' + 'a';
        } else {
            swapped[i] = c;
        }
    }
    swapped[length] = '\0';

    printf("Swapped case: %s\n", swapped);

    char capitalized[length + 1];
    int capitalize_next = 1;
    for (int i = 0; i < length; i++) {
        char c = input[i];
        if (c >= 'a' && c <= 'z' && capitalize_next) {
            capitalized[i] = c - 'a' + 'A';
            capitalize_next = 0;
        } else if (c >= 'A' && c <= 'Z' && !capitalize_next) {
            capitalized[i] = c - 'A' + 'a';
        } else {
            capitalized[i] = c;
        }
        if (c == ' ' || c == '\n' || c == '\t') {
            capitalize_next = 1;
        }
    }
    capitalized[length] = '\0';

    printf("Capitalized: %s\n", capitalized);

    return 0;
}