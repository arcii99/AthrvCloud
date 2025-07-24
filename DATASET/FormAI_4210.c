//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int count = 1;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    for(int i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == ' ' && sentence[i+1] != ' ') {
            count++;
        }
    }

    printf("The word count is: %d", count);

    return 0;
}