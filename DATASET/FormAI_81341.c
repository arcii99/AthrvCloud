//FormAI DATASET v1.0 Category: Spell checking ; Style: excited
//Hey there! I am a spell checking program, created just for you!
//My developer has spent countless hours on me, so I am bursting with excitement!
//Let's begin this adventure and make sure all your words are spelled correctly!

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void check_spelling(char *word);

int main() {
    char input[100];
    printf("Welcome to my spell checker! Please enter any text:\n");
    fgets(input, sizeof(input), stdin);
   
    char *word = strtok(input, " ");
    while (word != NULL) {
        check_spelling(word);
        word = strtok(NULL, " ");
    }
    return 0;
}

void check_spelling(char *word) {
    int i, len;
    len = strlen(word);
    if (!isalnum(word[len-2])) {
        word[len-2] = '\0';
        len--;
    }
    if (len > 1) {
        for (i = 0; i < len; i++) {
            word[i] = tolower(word[i]);
        }
        
        //here we can add a dictionary or some checks of our own
        if (strcmp(word, "amazing") == 0) {
            printf("%s is spelled correctly! You have an amazing vocabulary!\n", word);
        } else if (strcmp(word, "emporium") == 0) {
            printf("%s is spelled correctly! You must be a fan of fancy words!\n", word);
        } else {
            printf("Oops! %s is spelled incorrectly. Please double check the spelling.\n", word);
        }
    }
}