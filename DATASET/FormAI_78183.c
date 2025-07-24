//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <string.h>

void alienTranslator(char *word){
    int len = strlen(word);
    if(len<1){
        return;
    }
    int i=0, j=1;
    int count = 1;
    while(j<len){
        if(word[i] == word[j]){
            count++;
            j++;
        }
        else{
           printf("%d%c", count, word[i]);
           i = j;
           j++;
           count = 1;
        }
    }
    printf("%d%c", count, word[i]);
}

int main()
{
    char word[50];
    printf("Enter a word in Alien language:");
    scanf("%s",&word);
    printf("The translation of %s to Earth language is: ", word);
    alienTranslator(word);
    return 0;
}