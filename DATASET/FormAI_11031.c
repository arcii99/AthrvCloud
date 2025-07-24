//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <ctype.h>

// Function to check if a string is made up of only alphabets
int is_alpha(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[100];
    int alpha_count = 0;
    int digit_count = 0;
    int other_count = 0;

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    for (int i = 0; input[i] != '\0'; i++) {
        if (is_alpha(&input[i])) {
            alpha_count++;
        }
        else if (isdigit(input[i])) {
            digit_count++;
        }
        else if (!isspace(input[i])) {
            other_count++;
        }
    }

    printf("\nAnalysis of the given string:\n");
    printf("Number of alphabets: %d\n", alpha_count);
    printf("Number of digits: %d\n", digit_count);
    printf("Number of other characters: %d\n", other_count);

    return 0;
}