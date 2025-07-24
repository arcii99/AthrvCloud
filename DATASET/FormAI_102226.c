//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define SENTENCE_LENGTH 100
#define MAX_INPUT_LENGTH 100

char sentences[][SENTENCE_LENGTH] = {
    "The quick brown fox jumps over the lazy dog.",
    "The five boxing wizards jump quickly.",
    "Pack my box with five dozen liquor jugs.",
    "How vexingly quick daft zebras jump!",
    "Jaded zombies acted quaintly but kept driving their oxen forward.",
    "The quick onyx goblin jumps over the lazy dwarf."
};

int main() {
    int num_of_sentences = sizeof(sentences)/sizeof(sentences[0]);
    int sentence_index, i, j, correct_chars=0, incorrect_chars=0;
    char input[MAX_INPUT_LENGTH];
    time_t start_time, end_time;
    
    srand(time(0)); // Seed for random sentence selection
    
    // Display instructions to the user
    printf("*** Welcome to the Typing Speed Test! ***\n");
    printf("Type the given sentences as fast as possible and press enter.\n");
    printf("Press Ctrl-C to exit at any time.\n\n");
    
    // Main loop
    while(1) {
        // Select a random sentence from the list
        sentence_index = rand()%num_of_sentences;
        
        // Display the sentence to the user and get input
        printf("Type this sentence: %s\n", sentences[sentence_index]);
        start_time = time(0); // Record start time
        fgets(input, MAX_INPUT_LENGTH, stdin); 
        
        // Process the input and calculate the typing speed
        end_time = time(0); // Record end time
        for(i=0, j=0; i<strlen(sentences[sentence_index]) && j<strlen(input); i++, j++) {
            if(sentences[sentence_index][i] == input[j]) {
                correct_chars++;
            } else {
                incorrect_chars++;
            }
        }
        printf("\n*** Typing Speed Report ***\n");
        printf("Time Elapsed: %ld seconds\n", end_time-start_time);
        printf("Accuracy: %d correct, %d incorrect\n", correct_chars, incorrect_chars);
        printf("Typing Speed: %.2f characters per second\n\n", (float)correct_chars/(end_time-start_time));
        correct_chars = 0;
        incorrect_chars = 0;
    }
    
    return 0;
}