//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>

int main() {
    char text[1000], word[100], replace[100];
    int i, j, index = 0, found = 0, len, word_len;
    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);
    printf("\nEnter a word to replace: ");
    scanf("%s", word);
    printf("\nEnter the replacement word: ");
    scanf("%s", replace);
    len = strlen(text);
    word_len = strlen(word);
    for(i = 0; i < len; i++) {
        if(text[i] == word[0]) {
            found = 1;
            for(j = 1; j < word_len; j++) {
                if(text[i+j] != word[j]) {
                    found = 0;
                    break;
                }
            }
            if(found == 1) {
                index = i;
                break;
            }
        }
    }
    if(found == 0) {
        printf("\nSorry! Word not found\n");
    } else {
        for(i = 0; i < index; i++) {
            putchar(text[i]);
        }
        for(i = 0; i < strlen(replace); i++) {
            putchar(replace[i]);
        }
        for(i = index+word_len; i < len; i++) {
            putchar(text[i]);
        }
    }
    return 0;
}