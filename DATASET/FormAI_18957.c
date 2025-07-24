//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: active
#include <stdio.h>
#include <string.h>

int main() {
    char alien_lang[5][10] = {
        {"xor"}, {"his"}, {"jir"}, {"muk"}, {"liz"}
    };
    char english[5][10] = {
        {"hello"}, {"world"}, {"how"}, {"are"}, {"you"}
    };
    char input[10];
    int i, j;

    printf("Enter an alien word: ");
    scanf("%s", input);

    // convert to lowercase
    for(i = 0; input[i]; i++){
        input[i] = tolower(input[i]);
    }

    for(i = 0; i < 5; i++) {
        if(strcmp(alien_lang[i], input) == 0) {
            printf("The equivalent English word is: %s\n", english[i]);
            break;
        }
    }

    if(i == 5) {
        printf("Sorry, I could not translate that word.\n");
    }

    return 0;
}