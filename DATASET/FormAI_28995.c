//FormAI DATASET v1.0 Category: Text processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[1000], word[100], replacement[100], newSentence[1000];
    int count = 0, i, j, k, position = 0;
  
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
  
    printf("Enter a word to replace: ");
    fgets(word, sizeof(word), stdin);
  
    printf("Enter a replacement word: ");
    fgets(replacement, sizeof(replacement), stdin);
  
    for(i = 0; i < strlen(sentence)-1; i++){
        if(sentence[i] == ' ' || sentence[i] == '\n' || sentence[i] == '\t'){
            count++;
        }
    }
  
    for(i = 0; i <= count; i++){
        sscanf(sentence+position, "%s", word);
        position += strlen(word)+1;
  
        if(strcmp(word, replacement) == 0){
            strcat(newSentence, " ");
            strcat(newSentence, replacement);
        }
        else{
            strcat(newSentence, " ");
            strcat(newSentence, word);
        }
    }
  
    printf("Original sentence: %s", sentence);
    printf("New sentence: %s", newSentence);
  
    return 0;
}