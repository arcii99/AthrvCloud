//FormAI DATASET v1.0 Category: Online Examination System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[100];
    char options[4][50];
    int ans;
} Question;

int main() {
    Question questions[5];

    strcpy(questions[0].question, "What is the capital of India?\n");
    strcpy(questions[0].options[0], "A. Mumbai\n");
    strcpy(questions[0].options[1], "B. Delhi\n");
    strcpy(questions[0].options[2], "C. Chennai\n");
    strcpy(questions[0].options[3], "D. Kolkata\n");
    questions[0].ans = 1;

    strcpy(questions[1].question, "Who wrote the Harry Potter series?\n");
    strcpy(questions[1].options[0], "A. J.K. Rowling\n");
    strcpy(questions[1].options[1], "B. Stephen King\n");
    strcpy(questions[1].options[2], "C. George R.R. Martin\n");
    strcpy(questions[1].options[3], "D. Dan Brown\n");
    questions[1].ans = 0;

    strcpy(questions[2].question, "Which element has the chemical symbol 'Fe'?\n");
    strcpy(questions[2].options[0], "A. Iron\n");
    strcpy(questions[2].options[1], "B. Gold\n");
    strcpy(questions[2].options[2], "C. Silver\n");
    strcpy(questions[2].options[3], "D. Zinc\n");
    questions[2].ans = 0;

    strcpy(questions[3].question, "What is the smallest planet in our solar system?\n");
    strcpy(questions[3].options[0], "A. Earth\n");
    strcpy(questions[3].options[1], "B. Jupiter\n");
    strcpy(questions[3].options[2], "C. Saturn\n");
    strcpy(questions[3].options[3], "D. Mercury\n");
    questions[3].ans = 3;

    strcpy(questions[4].question, "Who directed the movie 'The Dark Knight'?\n");
    strcpy(questions[4].options[0], "A. Steven Spielberg\n");
    strcpy(questions[4].options[1], "B. Christopher Nolan\n");
    strcpy(questions[4].options[2], "C. Quentin Tarantino\n");
    strcpy(questions[4].options[3], "D. Martin Scorsese\n");
    questions[4].ans = 1;

    int score = 0;
    for (int i = 0; i < 5; i++) {
        printf("%s", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%s", questions[i].options[j]);
        }
        int ans;
        printf("Enter your answer (1, 2, 3 or 4): ");
        scanf("%d", &ans);
        printf("\n");

        if (ans == questions[i].ans) {
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Wrong answer! The correct answer is %s", questions[i].options[questions[i].ans]);
        }

        printf("\n\n");
    }

    printf("Your final score is %d out of 5!", score);
    return 0;
}