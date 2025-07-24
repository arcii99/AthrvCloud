//FormAI DATASET v1.0 Category: Math exercise ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Welcome to the Math Game!\n");

    int count = 0; // Counter for number of correct answers
    int num1, num2, ans, userAns; // Variables to store numbers and answers

    srand(time(NULL)); // Set seed for random number generator

    for (int i = 0; i < 10; i++) { // Loop for 10 questions

        // Generate two random numbers between 1-20
        num1 = rand() % 20 + 1;
        num2 = rand() % 20 + 1;

        // Generate the answer
        ans = num1 + num2;

        // Display the question
        printf("\nWhat is %d + %d?\n", num1, num2);

        // Get user's answer
        scanf("%d", &userAns);

        // Check if user's answer is correct
        if (userAns == ans) {
            printf("Correct!\n");
            count++;
        }
        else {
            printf("Incorrect. The answer is %d.\n", ans);
        }
    }

    if (count >= 7) { // If user gets at least 7 out of 10 questions correct
        printf("\nCongratulations, you passed the Math Game! You got %d out of 10.\n", count);
        printf("You are a math genius!");
    }
    else { // If user gets less than 7 questions correct
        printf("\nYou failed the Math Game. You got %d out of 10.\n", count);
        printf("Don't worry, keep practicing and you'll get better!");
    }

    return 0;
}