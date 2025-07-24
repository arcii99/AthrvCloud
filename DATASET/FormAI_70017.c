//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand((unsigned int)time(NULL)); // Seed the random number generator

    printf("\nWelcome to the Typing Speed Test Program!\n\n");
    printf("You will be given 10 random words to type as fast as possible.\n");
    printf("Your typing speed will be calculated based on the time taken to complete the test.\n\n");
    printf("When you're ready, press ENTER to begin the test!\n\n");
    getchar(); // Wait for user to press 'Enter'

    printf("Test Begins Now!\n\n");

    char words[10][20] = {"apple", "banana", "cherry", "dolphin", "elephant", "football", "giraffe", "hamburger", "internet", "javascript"}; // Array of words to be typed
    char userInput[20]; // User's input buffer
    int inputCount = 0; // Number of inputs
    time_t startTime, endTime; // Variables to store start and end time

    for(int i = 0; i < 10; i++){
        printf("Word %d: %s\n", i+1, words[i]); // Print the word to be typed
        startTime = time(NULL); // Get the start time
        scanf("%s", userInput); // Wait for the user to input
        endTime = time(NULL); // Get the end time
        inputCount += strlen(userInput); // Add the number of characters input to inputCount
        printf("Time taken: %.2lf seconds\n\n", difftime(endTime, startTime)); // Print the time taken to input
    }

    printf("Test Complete!\n\n");
    printf("Your typing speed is: %.2lf characters per minute.", inputCount/((difftime(endTime, startTime)/60)*10)); // Calculate and print the typing speed

    return 0;
}