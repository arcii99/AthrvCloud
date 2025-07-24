//FormAI DATASET v1.0 Category: Spell checking ; Style: systematic
#include <stdio.h>
#include <string.h>

char* dictionary[] = {"apple", "banana", "cherry", "grape", "orange", "peach", "pear", "pineapple", "plum", "watermelon"};

int dictionarySize = sizeof(dictionary)/sizeof(dictionary[0]);

int isPresent(char* word){
    for(int i=0;i<dictionarySize;i++){
        if(!strcmp(dictionary[i], word)){ // if the word is present in the dictionary
            return 1;
        }
    }
    return 0;
}

void spellChecker(char* input){
    char* word = strtok(input, ".,:;?! ");
    while(word != NULL){
        if(!isPresent(word)){
            printf("%s is not spelled correctly.\n", word);
        }
        word = strtok(NULL, ".,:;?! ");
    }
}

int main(){
    char input[100];
    printf("Enter text to spellcheck: ");
    fgets(input, 100, stdin);
    spellChecker(input);
    return 0;
}