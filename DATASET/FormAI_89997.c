//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <string.h>

int main() {
    char alien_lang[26] = {'t', 'h', 'e', 'q', 'u', 'i', 'c', 'k', 'b', 'r', 'o', 'w', 'n', 'f', 'o', 'x', 'j', 'u', 'm', 'p', 's', 'o', 'v', 'e', 'r', 't'};
    char user_input[100];

    printf("Enter an alien message: \n");
    fgets(user_input, 100, stdin);

    int i;
    for(i = 0; i < strlen(user_input); i++) {
        int index = user_input[i] - 'a';
        if(index >= 0 && index < 26) {
            printf("%c", alien_lang[index]);
        } else {
            printf("%c", user_input[i]);
        }
    }

    return 0;
}