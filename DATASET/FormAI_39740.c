//FormAI DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000], output[1000] = {0};
    int i, j, len, vowels = 0, consonants = 0, digits = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    for (i = 0, j = 0; i < len; i++) {
        switch (input[i]) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                vowels++;
                output[j++] = input[i] + 1;
                break;
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                digits++;
                output[j++] = input[i] - 1;
                break;
            default:
                if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
                    consonants++;
                    output[j++] = input[i] + 2;
                }
                break;
        }
    }

    printf("Input string: %s", input);
    printf("Output string: %s\n", output);

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);

    return 0;
}