//FormAI DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *sentence);

int main(){
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    printf("Number of words in sentence: %d", countWords(sentence));
    return 0;
}

int countWords(char *sentence){
    int count = 0, i;
    for(i=0;sentence[i]!='\0';i++){
        if(sentence[i]==' ' || sentence[i]=='\n' || sentence[i]=='\t'){
            count++;
        }
    }
    return count+1;
}