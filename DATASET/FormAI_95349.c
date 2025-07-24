//FormAI DATASET v1.0 Category: String manipulation ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void remove_spaces(char *str);
void capitalize_word(char *str);
void replace_vowels(char *str);

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    remove_spaces(str);
    capitalize_word(str);
    replace_vowels(str);

    printf("Final string: %s", str);
    return 0;
}

/* Removes any spaces in the given string */
void remove_spaces(char *str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

/* Capitalizes the first word in the given string */
void capitalize_word(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
            break;
        }
    }
}

/* Replaces any vowels in the given string with '*' */
void replace_vowels(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        switch (str[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                str[i] = '*';
                break;
            default:
                break;
        }
    }
}