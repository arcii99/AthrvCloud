//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 15

char words[MAX_WORDS][MAX_WORD_LENGTH] = {"apple", "banana", "cherry", "durian", "elderberry", "fig", "grapefruit", "honeydew", "kiwi", "lemon"};

void print_words(int num_words) {
    for(int i=0; i<num_words; i++) {
        printf("%s\n", words[i]);
    }
}

int main() {
    srand(time(NULL)); //initialize random number generator with current time

    //initialize variables
    int num_words = 5;
    char word[MAX_WORD_LENGTH];
    int count = 0;
    clock_t start, end;
    double time_used;

    //print words for user to type
    printf("Type the following words and press enter:\n");
    for(int i=0; i<num_words; i++) {
        int index = rand() % MAX_WORDS; //choose random word from array
        strcpy(word, words[index]); //copy word to variable

        //print word with extra whitespace to clear previous input
        printf("%-15s", word);
    }
    printf("\n");

    //get user input and check for errors
    printf("Press enter to start typing...\n");
    getchar(); //wait for user to press enter
    start = clock(); //start timing

    for(int i=0; i<num_words; i++) {
        int index = rand() % MAX_WORDS;
        strcpy(word, words[index]);

        printf("%-15s", ""); //print whitespace for previous input to be cleared

        //get user input and compare with expected word
        char input[MAX_WORD_LENGTH];
        scanf("%s", input);
        if(strcmp(input, word) == 0) {
            count++; //increase correct count
        } else {
            printf("Incorrect! Expected: %s\n", word);
        }
    }

    //calculate and print results
    end = clock(); //stop timing
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time used: %.2fs\n", time_used);
    printf("Words per minute: %.0f\n", (count/time_used)*60);

    return 0;
}