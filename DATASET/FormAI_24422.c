//FormAI DATASET v1.0 Category: String manipulation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

int main(void) {
    char original_str[] = "Donald Knuth is a computer scientist";
    char new_str[50];
    int i, j = 0, len = strlen(original_str);

    // Remove all vowels
    for (i = 0; i < len; i++) {
        switch (original_str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                continue;
            default:
                new_str[j++] = original_str[i];
        }
    }

    new_str[j] = '\0';

    printf("Original string: %s\n", original_str);
    printf("New string: %s\n", new_str);

    // Reverse the new string
    len = strlen(new_str);
    for (i = 0; i < len/2; i++) {
        char temp = new_str[i];
        new_str[i] = new_str[len-i-1];
        new_str[len-i-1] = temp;
    }

    printf("Reversed new string: %s\n", new_str);

    // Convert each character to its respective ASCII value and add to a sum
    int sum = 0;
    for (i = 0; i < len; i++) {
        sum += (int) new_str[i];
    }

    printf("Sum of ASCII values: %d\n", sum);

    return 0;
}