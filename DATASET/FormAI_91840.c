//FormAI DATASET v1.0 Category: Spell checking ; Style: random
#include<stdio.h>
#include<string.h>

void checkSpelling(char* word, char* dictionary[], int size){
    int i; 
    for(i = 0; i < size; i++){
        if(strcmp(dictionary[i], word) == 0){
            printf("'%s' is spelled correctly!\n", word);
            return;
        }
    }
    printf("Did you mean ");
    int j;
    for(j = 0; j < size - 1; j++){
        printf("'%s', ", dictionary[j]);
    }
    printf("or '%s'?\n", dictionary[size - 1]);
}

int main(){
    char* dictionary[] = {"zebra", "apple", "banana", "orange", "pear", "kiwi", "grape", "lemon", "lime", "cherry", "plum", "apricot", "peach", "pear", "blueberry", "raspberry", "watermelon", "canteloupe", "pineapple", "papaya", "mango", "strawberry"};
    int dictionarySize = sizeof(dictionary)/sizeof(char*);
    
    printf("Welcome to the spell checker!\nPlease enter a word: ");
    char word[20];
    scanf("%s", word);
    
    checkSpelling(word, dictionary, dictionarySize);
    
    return 0;
}