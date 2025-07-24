//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    printf("Enter a C Cat language sentence:\n");
    fgets(sentence, sizeof(sentence), stdin); // Reading user input
    
    char translatedSentence[1000];
    int i;
    for(i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == 'M' || sentence[i] == 'm') {
            strcat(translatedSentence, "Meow");
        }
        else if(sentence[i] == 'P' || sentence[i] == 'p') {
            strcat(translatedSentence, "Purr");
        }
        else if(sentence[i] == 'F' || sentence[i] == 'f') {
            strcat(translatedSentence, "Fish");
        }
        else if(sentence[i] == 'C' || sentence[i] == 'c') {
            strcat(translatedSentence, "Catnip");
        }
        else if(sentence[i] == 'T' || sentence[i] == 't') {
            strcat(translatedSentence, "Tuna");
        }
        else if(sentence[i] == 'L' || sentence[i] == 'l') {
            strcat(translatedSentence, "Laser Pointer");
        }
        else if(sentence[i] == 'S' || sentence[i] == 's') {
            strcat(translatedSentence, "Scratch");
        }
        else if(sentence[i] == 'N' || sentence[i] == 'n') {
            strcat(translatedSentence, "Nap");
        }
        else if(sentence[i] == 'O' || sentence[i] == 'o') {
            strcat(translatedSentence, "Mouse");
        }
        else if(sentence[i] == 'H' || sentence[i] == 'h') {
            strcat(translatedSentence, "Hairball");
        }
        else if(sentence[i] == 'R' || sentence[i] == 'r') {
            strcat(translatedSentence, "Rat");
        }
        else if(sentence[i] == 'D' || sentence[i] == 'd') {
            strcat(translatedSentence, "Dog");
        }
        else if(sentence[i] == 'B' || sentence[i] == 'b') {
            strcat(translatedSentence, "Bird");
        }
        else if(sentence[i] == 'V' || sentence[i] == 'v') {
            strcat(translatedSentence, "Vet");
        }
        else {
            strcat(translatedSentence, " ");
        }
    }
    
    printf("Translated sentence: %s", translatedSentence);
    
    return 0;
}