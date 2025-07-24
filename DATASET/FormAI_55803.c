//FormAI DATASET v1.0 Category: Encryption ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *puzzle(char *str){
    char *new_word = (char *)malloc(strlen(str) + 1); 
    strcpy(new_word, str);
    int len = strlen(str);

    for(int i=0; i<len; i++){
        if(i % 2 == 0){
            new_word[i] = new_word[i]^4;
        }
        else if(i % 3 == 0){
            new_word[i] = new_word[i]^2;
        }
        else{
            new_word[i] = new_word[i] ^ 6;
        }
    }
    return new_word;
}

int main() {
    char word[1000];
    printf("Enter a word to encrypt: ");
    scanf("%s", word);
    printf("Original Word: %s\n", word);

    char *enc_word = puzzle(word);
    printf("Encrypted Word: %s\n", enc_word);
    
    for(int i=0; i<strlen(enc_word); i++){
        if(i % 2 == 0){
            enc_word[i] = enc_word[i]^4;
        }
        else if(i % 3 == 0){
            enc_word[i] = enc_word[i]^2;
        }
        else{
            enc_word[i] = enc_word[i] ^ 6;
        }
    }
    printf("Decrypted Word: %s\n", enc_word);
    free(enc_word);

    return 0;
}