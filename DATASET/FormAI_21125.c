//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator with current time
    
    char elements[7][3] = {"H","He","Li","Be","B","C","N"}; // array of element symbols
    int element_counts[7] = {0}; // array to hold the number of times each element appears
    
    printf("Welcome to the Post-Apocalyptic Periodic Table Quiz!\n");
    printf("Answer the following questions to test your knowledge of chemistry in this apocalyptic world.\n\n");

    // 10 random questions
    for(int i = 0; i < 10; i++) {
        int element_index = rand() % 7; // pick random element from array
        printf("Question %d:\n", i+1);
        printf("What is the symbol for element %s?\n", elements[element_index]);
        
        char guess[3]; // array to hold user's guess
        scanf("%s", guess); // take user input
        
        // check if user's guess is correct
        if(strcmp(guess, elements[element_index]) == 0) {
            printf("Correct! You are one of the few survivors who remembers their chemistry.\n\n");
            element_counts[element_index]++; // increment count for this element
        } else {
            printf("Incorrect. You might want to brush up on your chemistry if you want to survive.\n\n");
        }
    }
    
    // display results
    printf("Results:\n");
    for(int i = 0; i < 7; i++) {
        printf("%s: %d\n", elements[i], element_counts[i]);
    }
    
    printf("\nThanks for playing! Your knowledge of chemistry may just help you survive in this post-apocalyptic world.\n");
    
    return 0;
}