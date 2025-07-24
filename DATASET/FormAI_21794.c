//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: thoughtful
#include<stdio.h>
#include<string.h>

int main() {
    char cat_words[7][10] = {"meow", "purr", "hiss", "scratch", "claw", "play", "sleep"};
    char human_words[7][15] = {"Hello human, how are you?", "I am pleased to see you", "Do not touch me there, human!", "I do not like when you do that", "Please stop bothering me", "Let's have some fun!", "zzz...zzz..."};
    char input[10] = "";
    int i, index;

    printf("*** Welcome to the C Cat Language Translator ***\n\n");
    printf("Enter a word in Cat language:\n");
    scanf("%s", input);

    for(i = 0; i < 7; i++) {
        if(strcmp(input, cat_words[i]) == 0) {
            index = i;
            break;
        }
    }

    if(i == 7) {
        printf("Sorry human, I do not understand what you are saying.\n");
    }
    else {
        printf("In human language, I would say: \"%s\"\n", human_words[index]);
    }

    return 0;
}