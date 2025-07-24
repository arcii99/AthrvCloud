//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: complete
#include <stdio.h>
#include <ctype.h>

void count_char_freq(char *str, int freq[]) {
    int i = 0;
    while (str[i] != '\0') {
        if (isalpha(str[i])) {
            freq[tolower(str[i]) - 'a']++;
        }
        i++;
    }
}

void print_char_freq(int freq[]) {
    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, freq[i]);
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    int freq[26] = {0};
    count_char_freq(str, freq);
    printf("Character frequencies:\n");
    print_char_freq(freq);
    return 0;
}