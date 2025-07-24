//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // initializes random number generator
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";  // array of alphabet characters
    int i, j, score = 0, total_time = 0;

    printf("Welcome to the Typing Speed test!\n");
    printf("Type the letter shown on the screen. Ready?\n");

    for (i = 3; i >= 1; i--) {  // countdown to start the game
        printf("%d...\n", i);
        sleep(1);
    }

    for (i = 1; i <= 10; i++) {  // loop through 10 letters
        printf("Letter #%d: ", i);
        char random_letter = alphabet[rand() % 26];  // select random letter from array
        printf("%c\n", random_letter);

        clock_t start_time = clock();  // start timer
        char input_letter = getchar();  // get user input
        clock_t end_time = clock();  // end timer

        total_time += (end_time - start_time) / CLOCKS_PER_SEC;  // calculate total time

        if (input_letter == random_letter) {  // if input matches the random letter
            score++;
            printf("Correct! Your score: %d\n\n", score);
        } else {
            printf("Incorrect! Your score: %d\n\n", score);
        }
    }

    printf("Game Over! Your final score is: %d\n", score);
    printf("Total time taken: %d seconds\n", total_time);

    if (score > 7 && total_time <= 10) {  // if player gets high score and finishes fast
        printf("Wow, you're lightning fast! Are you secretly The Flash?\n");
    } else if (score > 5) {  // if player gets decent score
        printf("Nice job, you have pretty good typing skills!\n");
    } else {  // if player gets low score
        printf("Hmm... looks like you might need some practice.\n");
    }

    return 0;
}