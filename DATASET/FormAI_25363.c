//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int main() {
    char sentence[MAX_SIZE];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SIZE, stdin);

    int vowels_count = 0;
    int consonants_count = 0;
    int digits_count = 0;
    int spaces_count = 0;

    int length = strlen(sentence);
    for (int i = 0; i < length; i++) {
        char c = tolower(sentence[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels_count++;
        } else if (isdigit(c)) {
            digits_count++;
        } else if (isalpha(c)) {
            consonants_count++;
        } else if (isspace(c)) {
            spaces_count++;
        }
    }

    printf("\nSentence analysis:\n");
    printf("Vowels count: %d\n", vowels_count);
    printf("Consonants count: %d\n", consonants_count);
    printf("Digits count: %d\n", digits_count);
    printf("Spaces count: %d\n", spaces_count);

    return 0;
}