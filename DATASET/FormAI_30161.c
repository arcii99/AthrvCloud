//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: complex
#include <stdio.h>
#include <string.h>

void translate(char*); // Function prototype

int main() {
    char phrase[100];
    printf("Enter a phrase to translate: ");
    fgets(phrase, 100, stdin);
    translate(phrase); // Call to translate function
    return 0;
}
void translate(char* phrase){
    int i;
    char temp[100];

    // Replace c with meow
    for(i = 0; i < strlen(phrase); i++) {
        if(phrase[i] == 'c' || phrase[i] == 'C') {
            temp[i] = 'm';
            temp[i+1] = 'e';
            temp[i+2] = 'o';
            temp[i+3] = 'w';
            i += 3;
        }
        else {
            temp[i] = phrase[i];
        }
    }
    temp[i] = '\0'; // Null terminate the string

    printf("Translated phrase: %s\n", temp);
}