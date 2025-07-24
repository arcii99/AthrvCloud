//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>

void strip_punctuations(char *);
void to_lower_case(char *);
int is_palindrome(char *);

int main() {
    char str[1000];

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    strip_punctuations(str);
    to_lower_case(str);

    if(is_palindrome(str))
        printf("\nThe entered string is a palindrome.\n");
    else
        printf("\nThe entered string is not a palindrome.\n");

    return 0;
}

void strip_punctuations(char *str) {
    char punctuations[] = ".,;:\"\'?!(){}[]1234567890";

    for(int i = 0; i < strlen(punctuations); i++) {
        char *found_punc = strchr(str, punctuations[i]);

        while(found_punc != NULL) {
            int index = found_punc - str;
            memmove(&str[index], &str[index + 1], strlen(str) - index);
            found_punc = strchr(str, punctuations[i]);
        }
    }
}

void to_lower_case(char *str) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

int is_palindrome(char *str) {
    int length = strlen(str);

    for(int i = 0; i < length / 2; i++) {
        if(str[i] != str[length - i - 2])
            return 0;
    }

    return 1;
}