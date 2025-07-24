//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_WORDS 10
#define MAX_LENGTH 20

char* words[MAX_WORDS] = {"programming", "challenge", "asynchronous", "keyboard", "speed", "test", "typing", "language", "coding", "developer"};

// function to generate random word for typing test
char* generateWord() {
    srand(time(NULL));
    int index = rand() % MAX_WORDS;
    return words[index];
}

// function to print typing test instructions
void printInstructions() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the given word as fast and accurately as possible.\n");
    printf("Press Enter to start the test.\n");
    printf("You will have 10 seconds to complete as many words as possible.\n");
    printf("Press Ctrl+C to exit at any time.\n\n");
}

int main() {
    printInstructions();
    getchar();  // wait for user to press Enter
    
    int wordCount = 0;  // count of words typed correctly
    time_t startTime = time(NULL); // start time of test
    
    bool isComplete = false; // flag indicating if test is complete
    while(!isComplete) {
        char* word = generateWord(); // get random word
        printf("Type this word: %s\n", word);
        
        char userInput[MAX_LENGTH]; // buffer to read user input
        fgets(userInput, MAX_LENGTH, stdin); // read user input
        
        if(strncmp(word, userInput, strlen(word)-1) == 0) { // compare user input with generated word
            wordCount++; // increment count of words typed correctly
        }
        
        time_t currentTime = time(NULL); // get current time
        
        if(difftime(currentTime, startTime) > 10) { // check if 10 seconds have elapsed
            isComplete = true; // mark test as complete
        }
    }
    
    printf("Test complete!\n");
    printf("You typed %d words correctly in 10 seconds.\n", wordCount);
    
    return 0;
}