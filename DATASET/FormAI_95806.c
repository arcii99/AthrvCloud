//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Retro-style Performance-Critical Component Example Program
// Generate Random Alphabets and Check if they match with the target word

int main(){
    char target[] = "RETRO"; // Target Word
    char random_char; // Randomly Generated Character
    int i, count = 0, flag = 0; // Counters and Flags
    srand(time(NULL)); // Seed Random Number Generator

    printf("Welcome to the Retro Performance-Critical Component Example Program!\n");

    // Keep Generating Random Characters until Target Word is found
    while(flag != 1){
        // Generate Random Character
        random_char = (rand() % 26) + 65; // Random Alphabets starting from A

        // Check if Generated Character Matches with the Target Word Character
        if(random_char == target[count]){
            printf("%c ", random_char); // Print Matched Character
            count++; // Increment Counter

            // Check if Target Word is Completely Matched
            if(count == 5){
                printf("\nCongratulations! You Found the Target Word!\n");
                flag = 1; // Set Flag to Exit Loop
            }
        }
        else{
            printf(". "); // Print Dot to Represent Non-Matched Character
        }
    }

    return 0; // Exit Program
}