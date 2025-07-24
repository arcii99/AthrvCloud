//FormAI DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_WORDS 5000

int main(void) {

    char c;
    char word[MAX_WORD_LEN+1];
    int wordCount = 0;
    int words[MAX_WORDS] = { 0 };

    while ((c = getchar()) != EOF) {
        if (isalpha(c) || (c == '-' && isalpha(getchar()))) {
            int i = 0;
            word[i] = tolower(c);
            while (((c = getchar()) != EOF) && (isalpha(c) || c == '-')) {
                i++;
                if (i < MAX_WORD_LEN)
                    word[i] = tolower(c);
            }
            if (i >= MAX_WORD_LEN) {
                while ((c = getchar()) != EOF && isalpha(c));
            }
            word[i+1] = '\0';
            words[wordCount++] = hash(word);
            if (wordCount >= MAX_WORDS) {
                printf("Error: too many words.\n");
                return -1;
            }
        }
    }

    printf("Total word count: %d\n", wordCount);
    printf("Unique word count: %d\n", uniqueWordCount(words, wordCount));

    return 0;
}

int hash(char *str) {
    // An implementation of djb2 hash algorithm (http://www.cse.yorku.ca/~oz/hash.html)
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % MAX_WORDS;
}

int uniqueWordCount(int *words, int wordCount) {
    int uniqueWords = 0;
    int lastWord = -1;
    for (int i = 0; i < wordCount; i++) {
        if (words[i] != -1 && words[i] != lastWord) {
            uniqueWords++;
            lastWord = words[i];
            for (int j = i+1; j < wordCount; j++) {
                if (words[j] == lastWord) {
                    words[j] = -1;
                }
            }
        }
    }
    return uniqueWords;
}