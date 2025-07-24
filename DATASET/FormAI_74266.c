//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 30
#define MAX_WORD_LENGTH 20

void shuffle_array(int *array, int n){
    srand(time(NULL));
    for(int i = n-1; i >= 1; i--){
        int j = rand() % (i+1);
        int temp = array[j];
        array[j] = array[i];
        array[i] = temp;
    }
}

double calculate_typing_speed(double elapsed_time, int num_chars){
    double wpm = num_chars / (elapsed_time/60);
    return wpm;
}

void prompt(){
    printf("Type the following text: \n");
}

int main(){
    char words[MAX_WORDS][MAX_WORD_LENGTH] = {
        "the", "quick", "brown", "fox", "jumps",
        "over", "the", "lazy", "dog", "now",
        "is", "the", "time", "for", "all",
        "good", "men", "to", "come", "to",
        "the", "aid", "of", "their", "country",
        "hello", "world", "how", "are", "you"
    };

    int order[MAX_WORDS];
    for(int i=0; i<MAX_WORDS; i++){
        order[i] = i;
    }
    shuffle_array(order, MAX_WORDS);

    char input[MAX_WORDS * MAX_WORD_LENGTH];
    memset(input, 0, sizeof(input));

    for(int i=0; i<MAX_WORDS; i++){
        prompt();
        printf("%s ", words[order[i]]);

        clock_t start_time = clock();
        fgets(input, sizeof(input), stdin);
        clock_t end_time = clock();

        double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        int num_chars = strlen(input) - 1;  // -1 to remove the newline character
        double wpm = calculate_typing_speed(elapsed_time, num_chars);
        printf("Elapsed time: %lf, WPM: %lf\n", elapsed_time, wpm);

        if(strcmp(input, words[order[i]]) != 0){
            printf("Incorrect! Please try again.\n");
            i--;
        }
    }

    printf("Congratulations! You have completed the typing speed test.\n");
    return 0;
}