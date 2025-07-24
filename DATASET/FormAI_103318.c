//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check the spelling
void check_spelling(char *word) {
    char dictionary[100][100] = {"apple", "banana", "cherry", "dinosaur", "elephant", "fountain", "grape", "hamburger", "icecream", "jackpot", "kangaroo", "lemon", "mango", "nebula", "orange", "pineapple", "queer", "raccoon", "strawberry", "turtle", "umbrella", "vampire", "wizard", "xylophone", "yellow", "zebra"};

    int found = 0;

    for(int i = 0; i < 26; i++) {
        if(strcmp(dictionary[i], word) == 0) {
            found = 1;
            break;
        }
    }

    if(found == 1) {
        printf("The spelling of %s is correct\n", word);
    }
    else {
        printf("The spelling of %s is incorrect\n", word);
    }
}

int main() {
    char input[100];

    printf("Enter a word to check its spelling: ");
    scanf("%s", input);

    check_spelling(input);

    return 0;
}