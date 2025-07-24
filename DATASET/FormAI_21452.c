//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 20
#define MAX_WORD_LENGTH 15
#define MAX_SECONDS 60

int main(){
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {"programming", "computer", "development", "algorithm", "debugging",
                                              "function", "language", "syntax", "iteration", "variable",
                                              "optimization", "testing", "memory", "integer", "float",
                                              "conditional", "loop", "stack", "queue", "recursion"};
    int word_count = 0, correct_count = 0, incorrect_count = 0, seconds_left = MAX_SECONDS;
    time_t start_time, end_time;
    srand(time(NULL));
    
    printf("Welcome to the Typing Speed Test!\nYou have %d seconds to type as many words as you can from the following list:\n", MAX_SECONDS);

    for(int i = 0; i < MAX_WORDS; i++){
        printf("%s ", words[i]);
    }
    printf("\n");

    printf("\nPress ENTER to start the timer");
    getchar();
    start_time = time(NULL);

    while(seconds_left > 0){
        int word_index = rand() % MAX_WORDS;
        char typed_word[MAX_WORD_LENGTH];
        printf("\n%s: ", words[word_index]);
        scanf("%s", typed_word);
        word_count++;

        if(strcmp(typed_word, words[word_index]) == 0){
            printf("Correct!\n");
            correct_count++;
        }
        else{
            printf("Incorrect. The correct word is '%s'\n", words[word_index]);
            incorrect_count++;
        }

        end_time = time(NULL);
        seconds_left = MAX_SECONDS - difftime(end_time, start_time);
        printf("%d seconds left\n", seconds_left);
    }

    double accuracy = (double) correct_count / word_count * 100;
    printf("\nTime's up! You typed %d words in %d seconds.\nYou typed %d correctly and %d incorrectly with an accuracy of %.2f%%\n",
           word_count, MAX_SECONDS, correct_count, incorrect_count, accuracy);
    return 0;
}