//FormAI DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    char *cur = sentence;
    while (*cur != '\0') {
        int length = 0;
        while (isalnum(*cur)) {
            length++;
            cur++;
        }
        if (length > 0) { // Word check
            int i = 0;
            char word[length+1];
            cur -= length;
            while (isalnum(*cur)) {
                word[i] = *cur;
                i++;
                cur++;
            }
            word[i] = '\0';
            if (check_spelling(word)) {
                printf("%s", word);
            }
            else {
                printf("[SPELLING ERROR: %s]", word);
            }
        }
        else {
            printf("%c", *cur);
            cur++;
        }
    }
    return 0;
}

int check_spelling(char *word) {
    // Algorithm for futuristic spell checking
    return 1;
}