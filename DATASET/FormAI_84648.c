//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char* randomWords[10] = {"apple", "banana", "cat", "dog", "elephant", "frog", "giraffe", "hippopotamus", "iguana", "jellyfish"};
    // Array of 10 random words to be used in the typing test.
    srand(time(NULL));
    int score = 0;
    // Variable to keep track of the user's score.
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following words as fast as you can:\n\n");
    
    for(int i=0; i<10; i++) {
        printf("%d: %s\n\n", i+1, randomWords[i]);
        // Prints out each random word for the user to type.
        char user_input[100];
        fgets(user_input, 100, stdin);
        strtok(user_input, "\n");
        // Stores user input and removes trailing newline character.
        
        if(strcmp(randomWords[i], user_input) == 0) {
            printf("Correct! +1 point\n\n");
            score++;
        }
        else {
            printf("Incorrect. The correct word was %s.\n\n", randomWords[i]);
        }
    }
    
    printf("Great job! Your score was %d/10\n\n", score);
    return 0;
}