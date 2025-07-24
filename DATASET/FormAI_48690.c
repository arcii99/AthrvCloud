//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: curious
#include<stdio.h>
#include<string.h>

/* This program translates English sentences to C Cat Language */
int main() {

    char sentence[1000];
    printf("Enter an English sentence: ");
    fgets(sentence, 1000, stdin);

    /* Translation logic */
    for(int i=0; i<strlen(sentence); i++) {
        if(sentence[i] == 'c' || sentence[i] == 'C') {
            printf("meow ");
        } else if(sentence[i] == 'a' || sentence[i] == 'A') {
            printf("purr ");
        } else if(sentence[i] == 't' || sentence[i] == 'T') {
            printf("hiss ");
        } else if(sentence[i] == 'e' || sentence[i] == 'E') {
            printf("growl ");
        } else {
            printf("%c", sentence[i]); // Prints all other characters as is
        }
    }

    printf("\n");

    return 0;
}