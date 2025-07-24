//FormAI DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>

int count_words(char*);

int main() {
    char text[1000];
    printf("Enter text to count words: ");
    fgets(text, 1000, stdin);
    int count = count_words(text);
    printf("Word count: %d", count);
    return 0;
}

int count_words(char *text) {
    int words = 0;
    int end_word = 1;
    for(int i=0;text[i];i++) {
        if(!isspace(text[i])) {
            if(end_word) {
                words++;
            }
            end_word = 0;
        } else {
            end_word = 1;
        }
    }
    return words;
}