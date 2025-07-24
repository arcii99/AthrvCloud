//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* answer[5] = {"The sky is green", "Fish can fly","Time moves backwards","Trees can talk","The moon is made of cheese"}; // array of surreal answers 
    srand(time(NULL)); // seeding the random number generator with current time
    int correct_ans = rand() % 5; // selecting a random answer as the correct answer
    printf("Welcome to the Surreal Quiz Game\n");
    printf("Choose the most surreal answer:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d) %s\n", i + 1, answer[i]); // printing the options
    }
    int user_ans;
    scanf("%d", &user_ans); // taking input from user
    while(user_ans < 1 || user_ans > 5) { // validating user input
        printf("Invalid input, please choose between 1 and 5\n");
        scanf("%d", &user_ans);
    }
    user_ans--; // correcting user input to match array index
    if(user_ans == correct_ans) {
        printf("Correct answer! You are a true surrealist\n");
    }
    else {
        printf("Wrong answer, the correct answer is: %s\n", answer[correct_ans]);
    }
    return 0;
}