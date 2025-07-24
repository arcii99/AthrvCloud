//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10 // maximum number of words in the test
#define MAX_WORD_LENGTH 10 // maximum length of each word

// function to generate a random word
void generate_word(char* word) {
    int length = rand() % MAX_WORD_LENGTH + 1; // random length between 1 and MAX_WORD_LENGTH
    for (int i = 0; i < length; i++) {
        char c = rand() % 26 + 'a'; // random lowercase alphabet
        word[i] = c;
    }
    word[length] = '\0'; // null-terminate the string
}

// function to print the instructions
void print_instructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the words as fast as you can, and press enter after each word.\n");
    printf("Your score will be the number of correct words you typed in 30 seconds.\n");
    printf("Press any key to start the test.\n");
    getchar();
    system("clear"); // clear the screen
}

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    
    print_instructions();
    
    char words[MAX_WORDS][MAX_WORD_LENGTH + 1]; // array to store the words
    int num_words = rand() % MAX_WORDS + 1; // random number of words between 1 and MAX_WORDS
    for (int i = 0; i < num_words; i++) {
        generate_word(words[i]); // generate random words
    }
    
    time_t start = time(NULL); // current time in seconds
    int score = 0;
    int index = 0; // current word index
    char input[MAX_WORD_LENGTH + 1]; // buffer to store user input
    
    printf("Your time starts now!\n");
    while (difftime(time(NULL), start) <= 30) { // run the loop for 30 seconds
        printf("%s ", words[index]); // print the current word
        fflush(stdout); // flush the output to ensure immediate printing
        fgets(input, sizeof(input), stdin); // read user input
        input[strcspn(input, "\n")] = '\0'; // remove the newline char at the end
        
        // compare the input with the current word
        if (strcmp(input, words[index]) == 0) {
            score++;
        }
        
        index++;
        if (index == num_words) { // wrap around to the first word
            index = 0;
        }
    }
    
    printf("Time's up! You typed %d words correctly in 30 seconds.\n", score);
    return 0;
}