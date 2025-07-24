//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program is a time travel simulator that takes the user on a journey through different eras in history. The user will be transported to a random year in the past and will need to answer historical questions to make it back to the present day. */

int main(void){
    srand(time(0)); // Seed for random number generator
    
    // Array of years to travel to
    int years[] = {1000, 1500, 1800, 1920, 1950, 1970, 1990};
    
    // Randomly choose a year to travel to
    int random_index = rand() % 7; // There are 7 years in the array
    int target_year = years[random_index];
    printf("Welcome to the time travel simulator! You have been transported to the year %d.\n", target_year);
    
    // Historical questions for each year
    char *questions[] = {"What was the name of the king/queen in power?", "What major events occurred during this time period?", 
                         "What major technological advancements were made during this time period?", "Name a famous person from this era."};
    
    // Answer key for each question
    char *answers[] = {"", "", "", ""}; // Answer key will be filled as user progresses
    
    // Loop through each question and prompt user for an answer
    for(int i = 0; i < 4; i++){
        printf("Question %d: %s\n", i+1, questions[i]);
        char user_answer[50];
        fgets(user_answer, 50, stdin);
        user_answer[strcspn(user_answer, "\n")] = 0; // Remove newline character
        
        if(strcmp(user_answer, answers[i]) == 0){
            printf("Correct!\n");
        } else {
            printf("Incorrect. You have been sent back to the beginning of time.\n");
            i = -1;
        }
    }
    
    printf("Congratulations! You have successfully traveled through time and returned to the present day.\n");
    
    return 0;
}