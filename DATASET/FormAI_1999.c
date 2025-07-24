//FormAI DATASET v1.0 Category: Spell checking ; Style: retro
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char word[100];
    char dict[][20] = {"apple", "banana", "cherry", "orange", "pear", "pineapple", "strawberry"};

    printf("Enter a sentence to check for spelling errors:\n");
    fgets(sentence, 1000, stdin);

    char* token = strtok(sentence, " ");

    while(token != NULL){
        int found = 0;
        for(int i = 0; i < 7; i++){
            if(strcasecmp(token, dict[i]) == 0){
                found = 1;
                break;
            }
        }
        if(!found){
            printf("\nDid you mean: ");
            for(int i = 0; i < strlen(token); i++){
                for(int j = 0; j < 7; j++){
                    strncpy(word, token, i);
                    word[i] = '\0';
                    strcat(word, dict[j]);
                    if(strcasecmp(word, token) == 0){
                        printf("%s ", word);
                    }
                }
            }
        }
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    
    return 0;
}