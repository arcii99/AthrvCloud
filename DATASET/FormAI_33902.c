//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <time.h>

#define PARANOID_TIME 3 // time allowed for typing each word in seconds
#define PARANOID_ATTEMPTS 3 // number of attempts allowed for each word
#define PARANOID_WORDS 5 // number of words to type in the test
#define PARANOID_WORD_LENGTH 10 // maximum length of each word

char* paranoid_words[PARANOID_WORDS] = { // array of paranoid words
    "snooper", 
    "intruder", 
    "spyware", 
    "hacker", 
    "trojan"
};

int main() {
    int score = PARANOID_WORDS * PARANOID_ATTEMPTS; // maximum score
    int total_time = 0; // total time taken to type all words
    srand(time(NULL)); // seed for random number generator
    printf("Welcome to the Paranoid Typing Speed Test!\n");
    printf("You will be given %d paranoid words to type in %d seconds.\n", PARANOID_WORDS, PARANOID_TIME);
    printf("You will have %d attempts per word.\n", PARANOID_ATTEMPTS);
    printf("Type each word exactly as shown and press Enter.\n");
    printf("Press Enter to start the test.");
    getchar(); // wait for user to press Enter
    for(int i = 0; i < PARANOID_WORDS; i++) {
        int word_score = PARANOID_ATTEMPTS; // score for the current word
        int word_time = 0; // time taken to type the current word
        char word[PARANOID_WORD_LENGTH+1]; // buffer to hold the current word
        strcpy(word, paranoid_words[i]);
        for(int j = 0; j < PARANOID_ATTEMPTS; j++) {
            printf("Word %d/%d, Attempt %d/%d: ", i+1, PARANOID_WORDS, j+1, PARANOID_ATTEMPTS);
            fflush(stdout); // flush stdout buffer
            time_t start = time(NULL); // start time for typing
            char input[PARANOID_WORD_LENGTH+1]; // buffer to hold user input
            fgets(input, sizeof(input), stdin); // read user input
            time_t end = time(NULL); // end time for typing
            int input_length = strlen(input);
            if(input_length > 0 && input[input_length-1] == '\n') { // remove trailing newline
                input[input_length-1] = '\0';
            }
            if(strcmp(input, word) != 0) { // incorrect input
                printf("Incorrect. Try again.\n");
                word_score--;
                j--; // decrement j since an attempt was used up
            }
            else { // correct input
                word_time += difftime(end, start); // add typing time
                total_time += difftime(end, start); // add typing time
                break; // move on to the next word
            }
        }
        if(word_score == 0) { // no attempts left
            printf("Sorry, you failed this word.\n");
        }
        else { // at least one attempt left
            printf("Correct! Time taken: %d seconds\n", word_time);
        }
        score -= word_score; // deduct score for this word
        printf("Current score: %d/%d\n", score, PARANOID_WORDS*PARANOID_ATTEMPTS);
        printf("Press Enter to continue.");
        getchar(); // wait for user to press Enter
    }
    printf("Test complete! Total time taken: %d seconds\n", total_time);
    printf("Final score: %d/%d\n", score, PARANOID_WORDS*PARANOID_ATTEMPTS);
    if(score == PARANOID_WORDS*PARANOID_ATTEMPTS) { // perfect score
        printf("Congratulations! You are a true paranoid.\n");
    }
    else if(score >= PARANOID_WORDS*PARANOID_ATTEMPTS/2) { // decent score
        printf("Not bad. You are somewhat paranoid.\n");
    }
    else { // poor score
        printf("You need to work on your paranoia skills.\n");
    }
    return 0;
}