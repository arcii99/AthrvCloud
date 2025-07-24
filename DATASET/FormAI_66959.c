//FormAI DATASET v1.0 Category: Word Count Tool ; Style: ephemeral
#include<stdio.h>
#include<string.h>

int countWords(char str[]) {
    int count = 0, i, len;
    len = strlen(str);
    for(i=0;i<len;i++) {
        if(str[i]==' ' || str[i]=='\n' || str[i]=='\t') {
            count++;
        }
    }
    return count+1;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    printf("The number of words in the sentence is: %d", countWords(sentence));
    return 0;
}