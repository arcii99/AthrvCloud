//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 100
#define MAX_LINE_SIZE 1000

void tolower_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

int count_word(char* line, char* word) {
    tolower_string(line);
    tolower_string(word);

    int count = 0;
    char* ptr = line;
    while ((ptr = strstr(ptr, word)) != NULL) {
        if ((ptr == line || *(ptr - 1) == ' ') &&
            (*(ptr + strlen(word)) == '\0' || *(ptr + strlen(word)) == ' ')) {
            count++;
        }
        ptr += strlen(word);
    }

    return count;
}

int main() {
    char line[MAX_LINE_SIZE];
    char word[MAX_WORD_SIZE];

    printf("Enter a string: ");
    fgets(line, MAX_LINE_SIZE, stdin);
    line[strlen(line)-1] = '\0'; // remove the newline character from fgets

    printf("Enter a word to count: ");
    scanf("%s", word);

    int count = count_word(line, word);
    printf("The word '%s' appears %d times in the string.\n", word, count);

    return 0;
}