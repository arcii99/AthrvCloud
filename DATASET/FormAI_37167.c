//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LEN 30

void read_word(char word[], int max_len);
bool is_whitespace(char ch);
int count_words(char sentence[]);
void print_word_count(int num_words);

int main(void) {
    char sentence[1000];
    int num_words;
    
    printf("C Word Count Tool\n");
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    num_words = count_words(sentence);
    print_word_count(num_words);
    
    return 0;
}

void read_word(char word[], int max_len) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && !is_whitespace(ch)) {
        if (i < max_len) {
            word[i++] = ch;
        }
    }
    word[i] = '\0';
}

bool is_whitespace(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t';
}

int count_words(char sentence[]) {
    char word[MAX_WORD_LEN + 1];
    int count = 0;

    while (*sentence != '\0') {
        if (is_whitespace(*sentence)) {
            sentence++;
        } else {
            read_word(word, MAX_WORD_LEN);
            sentence += strlen(word);
            count++;
        }
    }
    return count;
}

void print_word_count(int num_words) {
    printf("Number of words: %d\n", num_words);
}