//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[1000], word[1000];
    int i, j, count=0, sentence_length, word_length, flag;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    printf("Enter a word to count: ");
    fgets(word, 1000, stdin);
    word_length = strlen(word) - 1;

    sentence_length = strlen(sentence) - 1;

    for(i=0;i<(sentence_length-word_length+1);i++) {
        flag = 1;
        for(j=0;j<word_length;j++) {
            if(sentence[i+j]!=word[j]) {
                flag = 0;
                break;
            }
        }
        if(flag==1) {
            count++;
        }
    }

    printf("\nThe word '%s' appears %d times in the sentence '%s' \n", word, count, sentence);

    return 0;
}