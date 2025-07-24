//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: energetic
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

char buffer[MAX_WORD_LENGTH];
int words[MAX_WORDS];
int n = 0;

void clear_buffer() {
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        buffer[i] = '\0';
    }
    return;
}

int compare_words(char buffer[], char word[]) {
    int i = 0, j = 0;
    while (buffer[i] != '\0' || word[j] != '\0') {
        if (tolower(buffer[i]) != tolower(word[j])) {
            return 0;
        }
        i++;
        j++;
    }
    if (buffer[i] == '\0' && word[j] == '\0') {
        return 1;
    }
    return 0;
}

int find_word(char buffer[]) {
    for (int i = 0; i < n; i++) {
        if (compare_words(buffer, words[i])) {
            return i;
        }
    }
    return -1;
}

void add_word(char buffer[]) {
    int index = find_word(buffer);
    if (index == -1) {
        words[n] = buffer;
        n++;
    } else {
        words[index]++;
    }
    clear_buffer();
    return;
}

int main() {
    char c;
    int i = 0;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            buffer[i] = c;
            i++;
        } else {
            add_word(buffer);
            i = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", words[i], i);
    }
    return 0;
}