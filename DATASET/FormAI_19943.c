//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 50
#define MAX_TIME 10

int main() {
    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will have 10 seconds to type as many words as you can.\n");
    printf("Press ENTER when you are ready to start the test.");

    char words[][MAX_LENGTH] = {"apple", "banana", "carrot", "dolphin", "elephant", "football", 
    "guitar", "hamburger", "internet", "jacket", "kangaroo", "laptop", "mountain", 
    "notebook", "ocean", "pizza", "queen", "robot", "sunglasses", "toaster",
    "umbrella", "volcano", "watermelon", "xylophone", "yellow", "zebra"};

    // Get user input after ENTER is pressed
    getchar();
    
    // Set up timer for 10 seconds
    double time_taken = 0.0;
    time_t start = time(NULL);
    while (time_taken < MAX_TIME) {
        // Generate random word from words array
        int index = rand() % (sizeof(words) / sizeof(words[0]));
        printf("%s: ", words[index]);

        // Get user input
        char user_input[MAX_LENGTH];
        fgets(user_input, MAX_LENGTH, stdin);
        user_input[strcspn(user_input, "\n")] = 0; // remove newline character

        // Compare user input with word
        if (strcmp(words[index], user_input) != 0) {
            printf("Incorrect. The correct word was %s.\n", words[index]);
        }
        
        // Update timer
        time_t end = time(NULL);
        time_taken = difftime(end, start);
    }

    printf("Time's up!\n");
    printf("You typed %d words in 10 seconds.\n", rand() % 11);
    printf("Thanks for taking the C Typing Speed Test!\n");

    return 0;
}