//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct {
    char question[100];
    char choices[4][25];
    int correct_answer;
} Question;

void initialize_questions(Question *questions);

void play_game(Question *questions);

int main() {
    Question questions[MAX_QUESTIONS];
    initialize_questions(questions);
    play_game(questions);
    return 0;
}

void initialize_questions(Question *questions) {
    strcpy(questions[0].question, "What is the symbol for Hydrogen?");
    strcpy(questions[0].choices[0], "A. H");
    strcpy(questions[0].choices[1], "B. N");
    strcpy(questions[0].choices[2], "C. He");
    strcpy(questions[0].choices[3], "D. Na");
    questions[0].correct_answer = 0;

    strcpy(questions[1].question, "What is the symbol for Copper?");
    strcpy(questions[1].choices[0], "A. Ca");
    strcpy(questions[1].choices[1], "B. Au");
    strcpy(questions[1].choices[2], "C. Cu");
    strcpy(questions[1].choices[3], "D. Co");
    questions[1].correct_answer = 2;

    // Add more questions here
}

void play_game(Question *questions) {
    int score = 0;
    int i, choice;
    char answer[2];

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions.\n\n", MAX_QUESTIONS);

    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].question);
        printf("%s\n%s\n%s\n%s\n", questions[i].choices[0], questions[i].choices[1], questions[i].choices[2], questions[i].choices[3]);
        printf("Your answer (A,B,C,D): ");
        scanf("%s", answer);

        if (strcmp(answer, "A") == 0 || strcmp(answer, "a") == 0)
            choice = 0;
        else if (strcmp(answer, "B") == 0 || strcmp(answer, "b") == 0)
            choice = 1;
        else if (strcmp(answer, "C") == 0 || strcmp(answer, "c") == 0)
            choice = 2;
        else if (strcmp(answer, "D") == 0 || strcmp(answer, "d") == 0)
            choice = 3;
        else {
            printf("Invalid input. Please enter A,B,C, or D.\n");
            i--;
            continue;
        }

        if (choice == questions[i].correct_answer) {
            printf("Correct!\n\n");
            score++;
        }
        else {
            printf("Incorrect. The correct answer was %s.\n\n", questions[i].choices[questions[i].correct_answer]);
        }
    }

    printf("Quiz complete. You got %d out of %d questions correct.\n", score, MAX_QUESTIONS);
}