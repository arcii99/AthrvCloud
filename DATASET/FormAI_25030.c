//FormAI DATASET v1.0 Category: Math exercise ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, random_num, answer, user_answer, num_correct = 0;
    srand(time(0)); // seed random number generator using current time
    
    for (i = 0; i < 10; i++) { // loop for 10 questions
        j = i + 1;
        random_num = rand() % 100 + 1; // generate random number between 1 and 100
        answer = random_num * random_num; // calculate answer
        printf("Question %d: What is %d squared?\n", j, random_num);
        scanf("%d", &user_answer); // take user input
        
        if (user_answer == answer) { // check if answer is correct
            printf("Correct!\n");
            num_correct++; // increment number of correct answers
        } 
        else {
            printf("Incorrect! The correct answer is %d.\n", answer);
        }
    }
    
    printf("\nYou got %d out of 10 correct.\n", num_correct);
    
    return 0;
}