//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main(){

    char input_sentence[1000];
    printf("Enter a sentence in C Alien Language: ");
    fgets(input_sentence, sizeof(input_sentence), stdin);

    int i, j;

    //Replace k with g, r with z and w with q
    for(i = 0; i < strlen(input_sentence); i++){
        if(input_sentence[i] == 'k'){
            input_sentence[i] = 'g';
        }
        else if(input_sentence[i] == 'r'){
            input_sentence[i] = 'z';
        }
        else if(input_sentence[i] == 'w'){
            input_sentence[i] = 'q';
        }
    }

    //Reverse the entire sentence
    char reversed_sentence[1000];
    for(i = strlen(input_sentence) - 1, j = 0; i >= 0; i--, j++){
        reversed_sentence[j] = input_sentence[i];
    }
    reversed_sentence[j] = '\0';

    printf("Translated sentence: %s\n", reversed_sentence);
    return 0;

}