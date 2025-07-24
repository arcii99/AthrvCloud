//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_WORDS 20 // Maximum number of words in the test
#define MAX_LENGTH 10 // Maximum length of each word

int main(){
    char words[MAX_WORDS][MAX_LENGTH]; // Array to store words for the test
    char input[MAX_LENGTH]; // User input for each word
    clock_t start_time, end_time; // Variables to keep track of time
    int mistakes = 0; // Variable to count number of mistakes
    int word_count = 0; // Variable to keep track of number of words entered correctly
    int i, j; // Variables for loop iterations

    // Populate the words array with random words
    char *word_list[] = {"apple", "banana", "cat", "dog", "elephant", "flower", "gorilla", "house", "igloo", "jacket", "kangaroo", "lamp", "mountain", "notebook", "octopus", "pencil", "queen", "robot", "sun", "tree"};
    srand(time(NULL));
    for(i = 0; i < MAX_WORDS; i++){
        strcpy(words[i], word_list[rand() % 20]);
    }

    // Display the instructions
    printf("Type each word as it appears.\n");
    printf("Press Enter after each word.\n");
    printf("Press Ctrl+D to end the test.\n");

    // Wait for user to start the test
    printf("Press Enter to start the test.\n");
    getchar();

    // Start the test timer
    start_time = clock();

    // Prompt the user to enter each word in the test
    for(i = 0; i < MAX_WORDS; i++){
        printf("%d. %s\n", i+1, words[i]);
        scanf("%s", input);

        // Check if the input matches the correct word
        if(strcmp(input, words[i]) != 0){
            mistakes++;
        } else {
            word_count++;
        }

        // Check for end of test signal (Ctrl+D)
        if(feof(stdin)){
            break;
        }
    }

    // End the test timer
    end_time = clock();

    // Calculate the average typing speed
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    int typing_speed = word_count / elapsed_time * 60;

    // Display the test results
    printf("\nTest complete!\n");
    printf("Words typed correctly: %d\n", word_count);
    printf("Mistakes: %d\n", mistakes);
    printf("Time elapsed: %.2lf seconds\n", elapsed_time);
    printf("Typing speed: %d words per minute\n", typing_speed);

    return 0;
}