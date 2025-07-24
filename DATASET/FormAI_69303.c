//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    int i, time_elapsed;
    clock_t start, end;
    char test_word[] = "The quick brown fox jumps over the lazy dog.";
    char user_input[200];

    printf("Welcome to the Typing Speed Test Program!\n\n");
    printf("You will be given a sentence that you have to type as fast and accurately as possible.\n");
    printf("Press enter when you're ready to start.\n");
    getchar(); // wait for user input

    printf("Type the following sentence as fast and accurately as possible:\n\n");
    printf("%s\n", test_word);

    start = clock(); // start timer

    fgets(user_input, 200, stdin); // get user input
    end = clock(); // stop timer

    // remove newline character from user input
    user_input[strcspn(user_input, "\n")] = 0;

    // calculate time elapsed
    time_elapsed = (int) ((end - start) / CLOCKS_PER_SEC);

    // check user input
    if(strcmp(test_word, user_input) == 0) {
        printf("\nCongratulations! You typed the sentence correctly.\n");
        printf("Time elapsed: %d seconds.\n", time_elapsed);
    } else {
        printf("\nOops! There were some errors in your sentence.\n");
        printf("Time elapsed: %d seconds.\n", time_elapsed);
    }

    return 0;
}