//FormAI DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function to remove all vowels from a given string
char* remove_vowels(char* str) {
    char* new_str = (char*) malloc(strlen(str) * sizeof(char));
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u' &&
           str[i] != 'A' && str[i] != 'E' && str[i] != 'I' && str[i] != 'O' && str[i] != 'U') {
            new_str[j++] = str[i];
        }
    }
    new_str[j] = '\0';
    return new_str;
}

// function to check whether a given character is a digit or not
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// function to extract all digits from a given string and return the sum of those digits
int sum_of_digits(char* str) {
    int sum = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(is_digit(str[i])) {
            sum += str[i] - '0';
        }
    }
    return sum;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);
    printf("Original string: %s\n", str);

    char* new_str = remove_vowels(str);
    printf("String with vowels removed: %s\n", new_str);
    free(new_str);

    int sum = sum_of_digits(str);
    printf("Sum of digits in the string: %d\n", sum);

    return 0;
}