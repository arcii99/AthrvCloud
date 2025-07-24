//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[1000];
    char word[100];
    int i = 0, j = 0, count = 0, len = 0, flag = 0;

    printf("Enter a string: ");  
    fgets(str, sizeof(str), stdin);

    printf("Enter a word to count: ");
    scanf("%s", word);

    while (str[len] != '\0') {
        len++;
    }

    while (i < len) {
        if (str[i] == word[j]) {
            while (str[i] == word[j] && word[j] != '\0') {
                i++;
                j++;
            }
            if (word[j] == '\0') {
                flag = 1;
                count++;
            }
            j = 0;
        }
        else {
            i++;
        }
    }

    if (flag == 1) {
        printf("The word \"%s\" appears %d times in the string.\n", word, count);
    }
    else {
        printf("The word \"%s\" does not appear in the string.\n", word);
    }

    return 0;
}