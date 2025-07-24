//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: genious
#include<stdio.h>
#include<string.h>

//function to translate a sentence from English to C Cat language
void toCCat(char sentence[]) {
    char ccat[1000];
    int i=0,j=0;

    while(i<strlen(sentence)){
        if(sentence[i] == 'C' || sentence[i] == 'c') {
            ccat[j] = 'M';
            ccat[j+1] = 'e';
            j+=2;
        }
        else if(sentence[i] == 'A' || sentence[i] == 'a') {
            ccat[j] = 'P';
            ccat[j+1] = 'u';
            j+=2;
        }
        else if(sentence[i] == 'T' || sentence[i] == 't') {
            ccat[j] = 'K';
            ccat[j+1] = 'a';
            j+=2;
        }
        else if(sentence[i] == 'E' || sentence[i] == 'e') {
            ccat[j] = 'T';
            ccat[j+1] = 'o';
            j+=2;
        }
        else if(sentence[i] == 'R' || sentence[i] == 'r') {
            ccat[j] = 'Z';
            ccat[j+1] = 'e';
            j+=2;
        }
        else {
            ccat[j] = sentence[i];
            j++;
        }
        i++;
    }
    ccat[j] = '\0';
    printf("\nTranslated sentence in C Cat language: %s", ccat);
}

int main() {
    char sentence[1000];

    printf("Enter a sentence in English: ");
    fgets(sentence, 1000, stdin);

    printf("\nInput sentence: %s", sentence);

    toCCat(sentence);

    return 0;
}