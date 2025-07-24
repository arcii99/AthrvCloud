//FormAI DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for questions
struct Question {
    char question[255];
    char options[4][255];
    int answer;
};

// Define the questions array
struct Question questions[5] = {
    {"What is 1 + 1?", {"A. 2", "B. 3", "C. 4", "D. 5"}, 0},
    {"What is the capital of France?", {"A. Paris", "B. London", "C. Rome", "D. Madrid"}, 0},
    {"What is the largest country in the world?", {"A. China", "B. Russia", "C. India", "D. USA"}, 1},
    {"What is the currency of Japan?", {"A. Yen", "B. Euro", "C. Dollar", "D. Pound"}, 0},
    {"What is the boiling point of water?", {"A. 100°C", "B. 150°C", "C. 200°C", "D. 250°C"}, 0}
};

// Define a function to display the questions and ask for user input
int askQuestion(struct Question q) {
    int choice;
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", q.options[i]);
    }
    printf("Enter your choice (A=0, B=1, C=2, D=3): ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

int main() {
    int score = 0;
    for (int i = 0; i < 5; i++) {
        int choice = askQuestion(questions[i]);
        if (choice == questions[i].answer) {
            score++;
        }
    }

    printf("Quiz Complete! You scored %d out of 5.\n", score);
    return 0;
}