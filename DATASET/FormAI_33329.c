//FormAI DATASET v1.0 Category: Spell checking ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_word(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '-');
}

int main() {
    char input[250];
    printf("Enter text to check for spelling errors:\n");
    fgets(input, sizeof(input), stdin);

    char* word;
    char* delimiter = " ,.\n";
    word = strtok(input, delimiter);

    while (word != NULL) {
        int len = strlen(word);
        if (is_word(word[len - 1]) && word[len - 1] != '-') {
            word[len - 1] = '\0';
        }
        int is_mistake = 0;
        int i;
        for (i = 0; i < len - 1; i++) {
            if (!is_word(word[i])) {
                is_mistake = 1;
            }
        }
        if (is_mistake == 0) {
            printf("%s is spelled correctly.\n", word);
        } else {
            printf("%s is not spelled correctly.\n", word);
        }
        word = strtok(NULL, delimiter);
    }
    return 0;
}