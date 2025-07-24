//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    int length, i, space = 0;

    printf("Enter your sentence in cat language: ");
    fgets(sentence, 1000, stdin);

    length = strlen(sentence);

    for(i = 0; i < length; i++) {
        if(sentence[i] == ' ') {
            space++;
        }
    }

    if(space == 0) {
        printf("This is not cat language.\n");
    } else {
        for(i = 0; i < length; i++) {
            if(sentence[i] == 'm') {
                if(sentence[i+1] == 'e' && sentence[i+2] == 'o' && sentence[i+3] == 'w') {
                    printf("Cat: ");
                    i = i + 3;
                } else {
                    printf("%c", sentence[i]);
                }
            } else if(sentence[i] == 'p') {
                if(sentence[i+1] == 'u' && sentence[i+2] == 'r' && sentence[i+3] == 'r' && sentence[i+4] == 'r') {
                    printf("Purr: ");
                    i = i + 4;
                } else {
                    printf("%c", sentence[i]);
                }
            } else if(sentence[i] == 'h') {
                if(sentence[i+1] == 'i' && sentence[i+2] == 's' && sentence[i+3] == 's') {
                    printf("Hiss: ");
                    i = i + 3;
                } else {
                    printf("%c", sentence[i]);
                }
            } else if(sentence[i] == 'y') {
                if(sentence[i+1] == 'o' && sentence[i+2] == 'w' && sentence[i+3] == 'l') {
                    printf("Yowl: ");
                    i = i + 3;
                } else {
                    printf("%c", sentence[i]);
                }
            } else if(sentence[i] == 'c') {
                if(sentence[i+1] == 'h' && sentence[i+2] == 'i' && sentence[i+3] == 'r' && sentence[i+4] == 'p') {
                    printf("Chirp: ");
                    i = i + 4;
                } else {
                    printf("%c", sentence[i]);
                }
            } else if(sentence[i] == 't') {
                if(sentence[i+1] == 'r' && sentence[i+2] == 'i' && sentence[i+3] == 'l' && sentence[i+4] == 'l') {
                    printf("Trill: ");
                    i = i + 4;
                } else {
                    printf("%c", sentence[i]);
                }
            } else if(sentence[i] == 'c') {
                if(sentence[i+1] == 'h' && sentence[i+2] == 'a' && sentence[i+3] == 't') {
                    printf("Chat: ");
                    i = i + 3;
                } else {
                    printf("%c", sentence[i]);
                }
            } else {
                printf("%c", sentence[i]);
            }
        }
    }

    return 0;
}