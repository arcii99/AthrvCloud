//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get user input for typing speed test
char* get_user_input() {
    char* input = malloc(sizeof(char) * 100);
    scanf("%[^\n]s", input);
    getchar();
    return input;
}

int main() {
    // initialize variables
    int num_words = 10;
    int num_chars = 50;
    int i,j, correct = 0;
    char words[num_words][num_chars];
    char* user_input;
    double time_taken;

    // create sample words to type
    strcpy(words[0], "The quick brown fox jumps over the lazy dog.");
    strcpy(words[1], "Pack my box with five dozen liquor jugs.");
    strcpy(words[2], "How vexingly quick daft zebras jump!");
    strcpy(words[3], "Waltz, bad nymph, for quick jigs vex.");
    strcpy(words[4], "Quick zephyrs blow, vexing daft Jim.");

    // generate random words to add to list
    srand(time(NULL));
    for(i = 5; i < num_words; i++) {
        for(j = 0; j < num_chars - 1; j++) {
            int rand_char = rand() % 26;
            words[i][j] = 'a' + rand_char;
        }
        words[i][num_chars - 1] = '\0'; // null-terminate string
    }

    // print out instructions to user
    printf("Welcome to the typing speed test!\n");
    printf("You will be given a list of %d randomly generated words to type,\n", num_words);
    printf("followed by a prompt to start typing. Once you are finished,\n");
    printf("we will tell you how long it took you to type and how many mistakes you made.\n");
    printf("Press any key to start typing when you are ready.\n\n");
    getchar();

    // present user with words to type
    for(i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    printf("\nType the words exactly as they appear, then press enter.\n");

    // get user input
    clock_t start_time = clock();
    for(i = 0; i < num_words; i++) {
        user_input = get_user_input();

        // compare user input to sample word
        if(strcmp(user_input, words[i]) == 0) {
            correct++;
        }

        free(user_input);
    }
    clock_t end_time = clock();

    // calculate and display results
    time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    printf("\nYou typed %d words correctly in %.2f seconds.\n", correct, time_taken);

    return 0;
}