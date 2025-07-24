//FormAI DATASET v1.0 Category: Math exercise ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num1, num2, answer, user_ans;
    int num_right = 0, num_wrong = 0;
    char response[10];
    srand(time(0)); // Initialize random number generator
    printf("Let's test your math skills!\n");
    while(1) {
        num1 = rand() % 100; // Generate random number between 0 and 99
        num2 = rand() % 100;
        answer = num1 + num2; // Calculate the answer
        printf("What is %d + %d?\n", num1, num2);
        scanf("%d", &user_ans); // Read user input
        if(user_ans == answer) {
            printf("Correct! Great job!\n");
            num_right++;
        }
        else {
            printf("Sorry, the correct answer is %d\n", answer);
            num_wrong++;
        }
        printf("Do you want to continue? (yes or no)\n");
        scanf("%s", response);
        if(strcmp(response, "yes") != 0) {
            break; // Exit the loop
        }
    }
    printf("You got %d correct and %d wrong answers!\n", num_right, num_wrong);
    printf("Thanks for testing your math skills! Goodbye!\n");
    return 0;
}