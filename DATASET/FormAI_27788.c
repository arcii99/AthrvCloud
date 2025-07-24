//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: shocked
#include <stdio.h>
#include <string.h>

void translate(char word[]) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int len = strlen(word);

    for(int i=0; i<len; i++) {

        if(word[i] >= 97 && word[i] <= 122) { //checking if it's an alphabet
            if(word[i+1] == 'h' && word[i+2] == 'r') { //checking for 'hr' combination
                printf("Zorg ");
                i += 2;
            }
            else if(strchr(vowels, word[i]) != NULL) { //checking for vowels
                printf("%c", word[i]);
            }
            else {
                printf("%ch", word[i]);
            }
        }
        else {
            printf("%c", word[i]);
        }
    }
}


int main() {
    char word[100];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a word to translate: ");
    scanf("%s", word);

    printf("The translation of %s is: ", word);
    translate(word);

    printf("\nThank you for using our translator!");

    return 0;
}