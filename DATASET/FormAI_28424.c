//FormAI DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <string.h>

int countWords(char* sentence);

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    printf("Total number of words: %d\n", countWords(sentence));
    return 0;
}
 
int countWords(char* sentence) {
    int count = 0;
    char* token = strtok(sentence, " \n\t\r\f\v");
    while(token) {
        count++;
        token = strtok(NULL, " \n\t\r\f\v");
    }
    return count;
}