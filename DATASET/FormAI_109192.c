//FormAI DATASET v1.0 Category: Word Count Tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[1000], word[100];
    int i, j, k, count;

    printf("Enter a string: ");
    fgets(str, 1000, stdin);

    k = 0;
    count = 0;
    for (i = 0; i <= strlen(str); i++) {

        if (isalpha(str[i])) {
            word[k++] = str[i];
        }
        else if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0') {
            word[k] = '\0';

            if (strlen(word) > 0) {
                count++;
            }

            k = 0;
            memset(word, 0, sizeof(word));
        }
    }

    printf("Total words in the given string: %d\n", count);

    return 0;
}