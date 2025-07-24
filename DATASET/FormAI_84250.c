//FormAI DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, n = 0, count = 0;
    char c, *word = NULL, **words = NULL;

    printf("Enter a sentence: ");
    while ((c = getchar()) != '\n') {
        if (c == ' ' && n > 0) {
            word[n] = '\0';
            n = 0;
            words = (char **) realloc(words, (count+1)*sizeof(char *));
            words[count] = (char *) malloc((strlen(word)+1)*sizeof(char));
            strcpy(words[count], word);
            count++;
            word = NULL;
        } else if (c != ' ') {
            n++;
            word = (char *) realloc(word, n*sizeof(char));
            word[n-1] = c;
        }
    }
    if (n > 0) {
        word[n] = '\0';
        words = (char **) realloc(words, (count+1)*sizeof(char *));
        words[count] = (char *) malloc((strlen(word)+1)*sizeof(char));
        strcpy(words[count], word);
        count++;
    }
    free(word);
    
    printf("The number of words in the sentence is: %d\n", count);
    printf("The words in the sentence are:\n");
    for (i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);

    return 0;
}