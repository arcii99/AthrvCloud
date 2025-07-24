//FormAI DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {

    char input_string[1000];
    char new_string[1000];
    int num_vowels = 0;

    printf("Enter a string: ");
    fgets(input_string, sizeof(input_string), stdin);

    // count number of vowels and create new string without vowels
    for (int i = 0; i < strlen(input_string); i++) {
        char c = input_string[i];
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') {
            num_vowels++;
        } else {
            strncat(new_string, &input_string[i], 1);
        }
    }

    // output new string without vowels
    printf("The new string without vowels is: %s\n", new_string);

    // output number of vowels and whether it's odd or even
    printf("The string had %d vowels. ", num_vowels);
    if (num_vowels % 2 == 0) {
        printf("The number of vowels is even.\n");
    } else {
        printf("The number of vowels is odd.\n");
    }

    return 0;
}