//FormAI DATASET v1.0 Category: Spell checking ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//helper function to check if character is a letter
int is_alpha(char c){
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

int main(){

    char input[1000];
    printf("Enter the sentence you want to check: ");
    fgets(input, 1000, stdin);

    //create an array of words
    int word_count = 1, i;
    for (i = 0; i < strlen(input); i++){
        if (input[i] == ' ' && input[i + 1] != ' '){
            word_count++;
        }
    }
    char *words[word_count];
    words[0] = strtok(input, " ");
    for (i = 1; i < word_count; i++){
        words[i] = strtok(NULL, " ");
    }

    //create an array of dictionary words
    FILE *fptr = fopen("dictionary.txt", "r");
    if (fptr == NULL){
        printf("Error: dictionary file not found\n");
        return 1;
    }
    char dictionary[1000][100];
    int dict_count = 0;
    while(fgets(dictionary[dict_count], 100, fptr)){
        dict_count++;
    }
    fclose(fptr);

    //check each word in input against the dictionary words
    printf("\nSpell checking...\n");
    int error_count = 0;
    for (i = 0; i < word_count; i++){
        int j, found = 0;
        //strip special characters from word
        int len = strlen(words[i]);
        char clean_word[len];
        int count = 0;
        for (j = 0; j < len; j++){
            if (is_alpha(words[i][j])){
                clean_word[count] = tolower(words[i][j]);
                count++;
            }
        }
        clean_word[count] = '\0';
        //compare clean word against dictionary words
        for (j = 0; j < dict_count; j++){
            if (strcmp(clean_word, dictionary[j]) == 0){
                found = 1;
                break;
            }
        }
        if (!found){
            printf("* Error: '%s' is not in the dictionary\n", words[i]);
            error_count++;
        }
    }

    //print results
    if (error_count == 0){
        printf("\nSpell check complete: no errors found\n");
    }
    else{
        printf("\nSpell check complete: %d error(s) found\n", error_count);
    }

    return 0;
}