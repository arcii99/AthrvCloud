//FormAI DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_ANSWERS 4

struct question {
    char statement[100];
    char options[MAX_ANSWERS][100];
    int correct_answer;
};

struct test {
    char title[50];
    struct question questions[MAX_QUESTIONS];
    int num_questions;
};

void load_test(struct test *t)
{
    printf("Enter the title of the test: ");
    fgets(t->title, sizeof(t->title), stdin);
    t->title[strcspn(t->title, "\n")] = 0;

    printf("Enter the number of questions: ");
    scanf("%d", &t->num_questions);
    getchar();

    for (int i = 0; i < t->num_questions; i++) {
        printf("Enter statement of question %d: ", i + 1);
        fgets(t->questions[i].statement, sizeof(t->questions[i].statement), stdin);
        t->questions[i].statement[strcspn(t->questions[i].statement, "\n")] = 0;

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("Enter option %d of question %d: ", j + 1, i + 1);
            fgets(t->questions[i].options[j], sizeof(t->questions[i].options[j]), stdin);
            t->questions[i].options[j][strcspn(t->questions[i].options[j], "\n")] = 0;
        }

        printf("Enter the correct answer of question %d: ", i + 1);
        scanf("%d", &t->questions[i].correct_answer);
        getchar();
    }
}

void take_test(struct test t)
{
    int score = 0;
    printf("Starting test: %s\n\n", t.title);

    for (int i = 0; i < t.num_questions; i++) {
        printf("Question %d: %s\n", i + 1, t.questions[i].statement);

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d. %s\n", j + 1, t.questions[i].options[j]);
        }

        int answer;
        printf("Your answer: ");
        scanf("%d", &answer);
        getchar();

        if (answer == t.questions[i].correct_answer) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %d.\n\n", t.questions[i].correct_answer);
        }
    }

    printf("You scored %d out of %d.\n", score, t.num_questions);
}

int main()
{
    struct test t;
    load_test(&t);

    printf("\n\n");

    take_test(t);

    return 0;
}