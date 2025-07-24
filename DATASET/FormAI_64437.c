//FormAI DATASET v1.0 Category: Word Count Tool ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for(int i=0; i<strlen(sentence); i++) {
        if(sentence[i] == ' ' && sentence[i+1] != ' ') {
            wordCount++;
        }
    }

    printf("The sentence \"%s\" has %d words.\n", sentence, wordCount+1);
    return 0;
}