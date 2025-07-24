//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 100

void print_stats(char* str) {
    int str_len = strlen(str);
    int num_vowels = 0, num_consonants = 0, num_digits = 0, num_spaces = 0;

    for(int i = 0; i < str_len; i++) {
        if(isalpha(str[i])) {
            if(tolower(str[i]) == 'a' || tolower(str[i]) == 'e' || tolower(str[i]) == 'i' || tolower(str[i]) == 'o' || tolower(str[i]) == 'u') {
                num_vowels++;
            } else {
                num_consonants++;
            }
        } else if(isdigit(str[i])) {
            num_digits++;
        } else if(isspace(str[i])) {
            num_spaces++;
        }
    }

    printf("Statistics for String: %s\n", str);
    printf("Number of vowels: %d\n", num_vowels);
    printf("Number of consonants: %d\n", num_consonants);
    printf("Number of digits: %d\n", num_digits);
    printf("Number of spaces: %d\n", num_spaces);
}

int main() {
    char* str = (char*) malloc(sizeof(char) * MAX_STR);
    printf("Enter a string: ");
    fgets(str, MAX_STR, stdin);

    if(strlen(str) > 0 && str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }

    print_stats(str);
    free(str);
    return 0;
}