//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int i, j, k, p;

    printf("Enter a sentence in C Cat language: ");
    fgets(sentence, 100, stdin);

    for(i = 0; i < strlen(sentence); i++) {
        if(sentence[i] == 'm' && sentence[i+1] == 'e') {
            printf("I");
            i++;
        }
        else if(sentence[i] == 'y') {
            printf("you");
        }
        else if(sentence[i] == 'l' && sentence[i+1] == 'i' && sentence[i+2] == 'k' && sentence[i+3] == 'e' && sentence[i+4] == 's') {
            printf("hates");
            i += 4;
        }
        else if(sentence[i] == 'a' && sentence[i+1] == 't') {
            printf("in");
            i++;
        }
        else if(sentence[i] == 'o') {
            printf("a");
        }
        else if(sentence[i] == 'h' && sentence[i+1] == 'i' && sentence[i+2] == 's') {
            printf("her");
            i += 2;
        } 
        else if(sentence[i] == 'f' && sentence[i+1] == 'o' && sentence[i+2] == 'r' && sentence[i+3] == 'k' && sentence[i+4] == 's') {
            printf("spoons");
            i += 4;
        } 
        else if(sentence[i] == 'a' && sentence[i+1] == 'r' && sentence[i+2] == 'e') {
            printf("am");
            i += 2;
        } 
        else if(sentence[i] == 't' && sentence[i+1] == 'h' && sentence[i+2] == 'e' && sentence[i+3] == 'r' && sentence[i+4] == 'e') {
            printf("here");
            i += 4;
        } 
        else if(sentence[i] == 'm' && sentence[i+1] == 'y' && sentence[i+2] == 's' && sentence[i+3] == 'e' && sentence[i+4] == 'l' && sentence[i+5] == 'f') {
            printf("yourself");
            i += 5;
        } 
        else if(sentence[i] == 'i' && sentence[i+1] == 't' && sentence[i+2] == 's') {
            printf("their");
            i += 2;
        }
        else if(sentence[i] == 'f' && sentence[i+1] == 'o' && sentence[i+2] == 'b' && sentence[i+3] == 'a' && sentence[i+4] == 'r') {
            printf("food");
            i += 4;
        }
        else {
            printf("%c", sentence[i]);
        }
    }

    printf("\n");

    return 0;
}