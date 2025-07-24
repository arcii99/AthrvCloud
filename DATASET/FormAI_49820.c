//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input_string[1000];

    printf("Enter a string of text: ");
    fgets(input_string, sizeof(input_string), stdin);

    // count number of words
    int word_count = 0;
    char* split_string = strtok(input_string, " ");
    while (split_string != NULL) {
        word_count++;
        split_string = strtok(NULL, " ");
    }
    printf("The input string contains %d words.\n\n", word_count);

    // count occurrence of each letter
    int letter_count[26] = { 0 };
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] >= 'a' && input_string[i] <= 'z') {
            letter_count[input_string[i] - 'a']++;
        } else if (input_string[i] >= 'A' && input_string[i] <= 'Z') {
            letter_count[input_string[i] - 'A']++;
        }
    }
    printf("Number of occurrences of each letter in the input string:\n");
    for (int i = 0; i < 26; i++) {
        if (letter_count[i] > 0) {
            printf("%c: %d\n", i+'a', letter_count[i]);
        }
    }
    printf("\n");

    // count occurrence of each vowel
    int vowel_count[5] = { 0 };
    for (int i = 0; i < strlen(input_string); i++) {
        char c = input_string[i];
        switch(c) {
            case 'a':
            case 'A':
                vowel_count[0]++;
                break;
            case 'e':
            case 'E':
                vowel_count[1]++;
                break;
            case 'i':
            case 'I':
                vowel_count[2]++;
                break;
            case 'o':
            case 'O':
                vowel_count[3]++;
                break;
            case 'u':
            case 'U':
                vowel_count[4]++;
                break;
        }
    }
    printf("Number of occurrences of each vowel in the input string:\n");
    printf("a: %d\n", vowel_count[0]);
    printf("e: %d\n", vowel_count[1]);
    printf("i: %d\n", vowel_count[2]);
    printf("o: %d\n", vowel_count[3]);
    printf("u: %d\n", vowel_count[4]);

    return 0;
}