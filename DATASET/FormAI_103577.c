//FormAI DATASET v1.0 Category: Spell checking ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function to check spelling of a word
void spellCheck(char *word){
    int n = strlen(word);
    char *dictionary[] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};

    //loop through dictionary to check if the word is spelled correctly
    for(int i = 0; i < 10; i++){
        if(strcmp(word, dictionary[i]) == 0){
            printf("%s is spelled correctly\n", word);
            return;
        }
    }

    //if word is not found in dictionary, suggest similar words
    printf("Did you mean: \n");
    for(int i = 0; i < 10; i++){
        char *suggestion = calloc(n, sizeof(char)); //allocate memory for suggestion string
        int diff = 0; //variable to keep track of number of different characters between word and suggestion

        //compare each character of word with dictionary word to create suggestion
        for(int j = 0; j < n; j++){
            if(word[j] != dictionary[i][j]){
                suggestion[j] = dictionary[i][j];
                diff++;
            } else {
                suggestion[j] = word[j];
            }
        }

        //if suggestion differs from word by only one character, suggest it
        if(diff == 1){
            printf("%s\n", suggestion);
        }

        free(suggestion); //free memory allocated for suggestion
    }
}

int main(){
    char word[] = "appel"; //word to be checked
    spellCheck(word); //call spellCheck function

    return 0;
}