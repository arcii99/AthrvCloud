//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 1000 // maximum number of words in our dictionary
#define MAX_WORD_LENGTH 20 // maximum length of a word

// dictionary of words for our typing test
char dictionary[MAX_WORDS][MAX_WORD_LENGTH] = {"apple", "banana", "cherry", "orange", "kiwi", "mango", "pear", "pineapple", "strawberry", "watermelon", "peach", "grape", "lemon", "lime", "blueberry", "raspberry"};

// function to shuffle our dictionary of words
void shuffle_dictionary() {
    srand(time(NULL));
    for (int i = MAX_WORDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, dictionary[i]);
        strcpy(dictionary[i], dictionary[j]);
        strcpy(dictionary[j], temp);
    }
}

int main() {
    int num_words = 10; // number of words in the typing test
    int num_correct = 0; // number of correctly typed words
    int num_errors = 0; // number of typing errors
    float accuracy = 0.0; // typing accuracy
    int elapsed_time; // time taken to complete the typing test
    char input[MAX_WORD_LENGTH]; // user input buffer
    clock_t start_time, end_time; // variables to measure time
    
    printf("Welcome to our Typing Speed Test program!\n");
    printf("Your task is to type a sequence of words as fast and accurately as possible.\n\n");
    
    shuffle_dictionary(); // shuffle our dictionary of words
    
    printf("Your test will begin shortly...\n\n");
    printf("Type these %d words:\n\n", num_words);
    
    // display the words in our test
    for (int i = 0; i < num_words; i++) {
        printf("%s ", dictionary[i]);
    }
    
    printf("\n\nPress ENTER to start the test...");
    getchar(); // wait for user input
    
    // start the timer
    start_time = clock();
    
    // prompt the user to type the words
    for (int i = 0; i < num_words; i++) {
        scanf("%s", input);
        if (strcmp(input, dictionary[i]) == 0) {
            num_correct++;
        } else {
            num_errors++;
        }
    }
    
    // end the timer
    end_time = clock();
    
    // calculate the elapsed time in seconds
    elapsed_time = (int) (end_time - start_time) / CLOCKS_PER_SEC;
    
    // calculate the typing accuracy
    accuracy = ((float) num_correct / num_words) * 100;
    
    // display the results of the typing test
    printf("\n\nCongratulations, you have completed the typing test!\n");
    printf("Time taken: %d seconds\n", elapsed_time);
    printf("Number of correct words: %d\n", num_correct);
    printf("Number of typing errors: %d\n", num_errors);
    printf("Typing accuracy: %.2f %%\n", accuracy);
    
    return 0;
}