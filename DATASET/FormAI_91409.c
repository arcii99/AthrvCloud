//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWord(char *str, char *word, int i, int j, int count) {
    if (str[i] == '\0') {
        return count;
    }
    if (tolower(str[i]) == tolower(word[j])) {
        j++;
        if (word[j] == '\0') {
            count++;
            j = 0;
        }
    } else {
        j = 0;
    }
    return countWord(str, word, i+1, j, count);
}

int countFrequency(char *str, char *word, int count) {
    char *token = strtok(str, " ");
    while (token != NULL) {
        count += countWord(token, word, 0, 0, 0);
        token = strtok(NULL, " ");
    }
    return count;
}

int main() {
    char str[1000], word[100];
    int count = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    printf("Enter a word: ");
    scanf("%s", word);
    count = countFrequency(str, word, count);
    printf("Frequency of '%s' in '%s' is %d\n", word, str, count);
    return 0;
}