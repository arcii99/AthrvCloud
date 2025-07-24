//FormAI DATASET v1.0 Category: Word Count Tool ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int wordCount = 0, flag = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for(int i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t') {
            flag = 0;
        }
        else if(flag == 0) {
            flag = 1;
            wordCount++;
        }
    }

    printf("\nNumber of words in the sentence: %d\n", wordCount);

    return 0;
}