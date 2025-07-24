//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <string.h>

#define MAX_ANSWER_LENGTH 20
#define NUM_QUESTIONS 5

// Define the struct for a question
typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

// Define the questions for the quiz
Question questions[NUM_QUESTIONS] = {
    {"What is the symbol for Carbon? ", "C"},
    {"What is the atomic number of Hydrogen? ", "1"},
    {"What is the symbol for Gold? ", "Au"},
    {"What element has the symbol F? ", "Fluorine"},
    {"What is the atomic number of Oxygen? ", "8"}
};

int main() {
    int score = 0;

    // Loop through each question and prompt for an answer
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        char answer[MAX_ANSWER_LENGTH];
        printf("%s", questions[i].question);
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[i].answer) == 0) {
            score++;
            printf("That's correct!\n");
        } else {
            printf("Sorry, the correct answer is %s\n", questions[i].answer);
        }
    }

    // Print the final score
    printf("You got %d out of %d questions correct!\n", score, NUM_QUESTIONS);

    return 0;
}