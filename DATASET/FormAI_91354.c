//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\t\t***Welcome to the Typing Speed Test***\n\n");
    printf("Rules of the game:\n");
    printf("1. You will be given a set of words to type as fast as possible.\n");
    printf("2. Press enter to start and end the timer.\n");
    printf("3. Your typing speed will be displayed in words per minute (WPM).\n\n");

    char* words[10] = {"apple", "banana", "cherry", "dragonfruit", "elderberry", "fig", "grape", "honeydew", "indian gooseberry", "jackfruit"};
    int randint;
    int seconds_elapsed = 0;
    int num_of_words_typed = 0;
    char input[50];
    time_t start, end;

    printf("Press enter to start the test.\n");
    while(getchar() != '\n'){}
    printf("\n");

    while(num_of_words_typed < 10) {
        randint = rand() % 10;
        printf("%d. ", num_of_words_typed+1);
        printf("%s\n", words[randint]);
        time(&start);

        fgets(input, sizeof(input), stdin);

        time(&end);
        double elapsed_seconds = difftime(end, start);
        seconds_elapsed += (int)elapsed_seconds;

        if(strcmp(input, words[randint]) == 0) {
            num_of_words_typed++;
        }
    }

    printf("You typed 10 words in %d seconds.\n", seconds_elapsed);
    printf("Your typing speed is %d WPM.\n", (int)((num_of_words_typed / seconds_elapsed) * 60));
    return 0;
}