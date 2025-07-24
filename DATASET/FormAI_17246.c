//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: calm
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 50 // Maximum number of words to be input

int main() {
    char text[1000], word[100], c;
    int i, j, freq[SIZE], count = 0, len;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    len = strlen(text);
    if (len > 0 && text[len-1] == '\n') //remove new line character at the end of the input
        text[--len] = '\0';

    for (i = 0; i < len; i++) {
        c = text[i];
        if (isalnum(c) || ispunct(c) && c != '\'') {
            word[j++] = c;
        } else if (isspace(c)) {
            word[j] = '\0';
            if (strlen(word) > 0) {
                count++;
                for (j = 0; j < count; j++) {
                    if (strcmp(word, word[j]) == 0) {
                        freq[j]++;
                        break;
                    }
                }
                if (j == count) {
                    strcpy(word[count-1], word);
                    freq[count-1]++;
                }
            }
            j = 0;
        }
    }

    //Print out the results
    printf("\nNumber of words in the text : %d\n", count);
    printf("Word                Frequency\n");
    for (i = 0; i < count; i++)
        printf("%-19s%d\n", word[i], freq[i]);

    return 0;
}