//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: grateful
#include <stdio.h>

int main() {
    char cat_words[10][20] = {"meow", "purr", "hiss", "yowl", "chirp", "growl", "snarl", "pounce", "lick", "scratch"};
    char english_words[10][20] = {"hello", "happy", "angry", "hungry", "excited", "warning", "danger", "attack", "love", "itchy"};

    char input[20];
    printf("Enter a word in Cat Language: ");
    scanf("%s", input);

    int i;
    int index = -1;
    for(i=0; i<10; i++) {
        if(strcmp(input, cat_words[i]) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Sorry, I don't understand that word.\n");
    } else {
        printf("In English, that word means: %s\n", english_words[index]);
    }

    return 0;
}