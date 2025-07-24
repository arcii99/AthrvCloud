//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* An asynchronous C math exercise program that generates random multiplication questions
 * and allows the user to answer them in their own time. The program also keeps track of the 
 * number of correct and incorrect answers and prints them at the end.
 */

int correct_answers = 0;
int incorrect_answers = 0;

void ask_question(int num1, int num2) {
    int answer;
    printf("%d x %d = ", num1, num2);
    scanf("%d", &answer);
    
    if (answer == num1 * num2) {
        printf("Correct!\n");
        correct_answers++;
    } else {
        printf("Incorrect. %d x %d = %d\n", num1, num2, num1 * num2);
        incorrect_answers++;
    }
}

void generate_questions(int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        int num1 = rand() % 10 + 1;
        int num2 = rand() % 10 + 1;
        ask_question(num1, num2);
        sleep(1); // add some delay between questions for effect
    }
}

int main() {
    srand(time(0)); // seed the RNG with current time for more randomness
    int num_questions;
    
    printf("How many multiplication questions would you like to answer? ");
    scanf("%d", &num_questions);
    
    generate_questions(num_questions);
    
    printf("\nYou answered %d questions correctly and %d questions incorrectly. Good job!\n", correct_answers, incorrect_answers);
    
    return 0;
}