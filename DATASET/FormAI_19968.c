//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 1000

int main(int argc, char const *argv[]) {

    char sentence[MAX], word[MAX], ch;
    int count = 0, i, j, k, n, flag;

    printf("Enter a sentence: ");
    fgets(sentence, MAX, stdin);

    n = strlen(sentence);

    for (i = 0; i < n; i++) {
        ch = sentence[i];
        if (isalpha(ch)) {
            word[count] = tolower(ch);
            count++;
        }
        else if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (count > 0) {
                word[count] = '\0';
                flag = 0;
                for (j = 0; j < count; j++) {
                    if (word[j] != word[count - j - 1]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    printf("Palindrome: %s\n", word);
                }
                count = 0;
            }
        }
    }

    return 0;
}