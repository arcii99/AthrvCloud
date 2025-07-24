//FormAI DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>

// Define question struct
typedef struct {
    char question[1000];
    char options[4][1000];
    char correct_option;
} Question;

int main() {
    // Initialize question array
    Question questions[3];

    // Assign values to the questions
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "A. London");
    strcpy(questions[0].options[1], "B. Paris");
    strcpy(questions[0].options[2], "C. Berlin");
    questions[0].correct_option = 'B';

    strcpy(questions[1].question, "What is the largest planet in our solar system?");
    strcpy(questions[1].options[0], "A. Venus");
    strcpy(questions[1].options[1], "B. Jupiter");
    strcpy(questions[1].options[2], "C. Earth");
    questions[1].correct_option = 'B';

    strcpy(questions[2].question, "What is the formula for water?");
    strcpy(questions[2].options[0], "A. O2");
    strcpy(questions[2].options[1], "B. H2O");
    strcpy(questions[2].options[2], "C. CO2");
    questions[2].correct_option = 'B';

    // Display instructions to user
    printf("Welcome to the Online Examination System!\n\n");
    printf("You will be given 3 questions. Select the correct option from the given choices.\n\n");

    // Ask the user the questions
    char answer;
    int score = 0;

    for(int i = 0; i < 3; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        printf("%s\n%s\n%s\n", questions[i].options[0], questions[i].options[1], questions[i].options[2]);

        printf("Your answer: ");
        scanf(" %c", &answer);

        if(answer == questions[i].correct_option) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer was %c\n", questions[i].correct_option);
        }
    }

    // Display final score
    printf("Your final score is %d out of 3\n", score);

    return 0;
}