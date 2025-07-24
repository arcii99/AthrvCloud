//FormAI DATASET v1.0 Category: Text processing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char text[1000], word[100];
    int i, j, k, flag, count = 0;

    printf("Enter any text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the word to replace: ");
    scanf("%s", word);

    char newWord[100];
    printf("Enter the new word: ");
    scanf("%s", newWord);

    int n = strlen(text);
    int m = strlen(word);
    int p = strlen(newWord);

    for(i=0; i<n; i++) {
        flag = 1;

        for(j=0; j<m; j++) {
            if(text[i+j] != word[j]) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            count++;

            for(k=0; k<p; k++) {
                text[i] = newWord[k];
                i++;
            }
            i--;
        }
    }

    printf("\nThe new text is: %s\n", text);
    printf("The word %s was replaced %d times.\n", word, count);

    return 0;
}