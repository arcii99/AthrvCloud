//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    char sentence[1000];
    int count = 0, i = 0, wordFlag = 0;
    
    printf("Welcome to the Surrealist C Word Count Tool!\n\n");
    printf("Enter a sentence:\n");
    fgets(sentence, 1000, stdin);
    
    while (sentence[i] != '\0') {
        if (isspace(sentence[i]) || ispunct(sentence[i]) || i == strlen(sentence)-1) {
            wordFlag = 0;
        }
        else if (wordFlag == 0) {
            wordFlag = 1;
            count++;
        }
        i++;
    }
    
    printf("\nThe number of words in the sentence: %d\n\n", count);
    printf("And now for something completely different:\n");
    printf("Call me Ishmael. Some years ago--never mind how long precisely--having little or no money in my purse, and nothing particular to interest me on shore, I thought I would sail about a little and see the watery part of the world. It is a way I have of driving off the spleen and regulating the circulation. Whenever I find myself growing grim about the mouth; whenever it is a damp, drizzly November in my soul; whenever I find myself involuntarily pausing before coffin warehouses, and bringing up the rear of every funeral I meet; and especially whenever my hypos get such an upper hand of me, that it requires a strong moral principle to prevent me from deliberately stepping into the street, and methodically knocking people's hats off--then, I account it high time to get to sea as soon as I can. This is my substitute for pistol and ball. With a philosophical flourish Cato throws himself upon his sword; I quietly take to the ship. There is nothing surprising in this. If they but knew it, almost all men in their degree, some time or other, cherish very nearly the same feelings towards the ocean with me.\n\n");

    return 0;
}