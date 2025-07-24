//FormAI DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_CHOICES   4

typedef struct {
    char question[100];
    char choices[MAX_CHOICES][25];
    int answer;
} Question;

void create_question(Question *q, int index) {
    printf("Enter the question %d: ", index + 1);
    fgets(q->question, 100, stdin);
    q->question[strcspn(q->question, "\n")] = 0;

    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("Enter the choice %d: ", i + 1);
        fgets(q->choices[i], 25, stdin);
        q->choices[i][strcspn(q->choices[i], "\n")] = 0;
    }

    printf("Enter the answer (1-4): ");
    scanf("%d", &q->answer);
    getchar();
}

int main() {
    Question questions[MAX_QUESTIONS];

    // Create questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        create_question(&questions[i], i);
    }

    // Take exam
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i + 1, questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d) %s\n", j + 1, questions[i].choices[j]);
        }

        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        getchar();

        if (answer == questions[i].answer) {
            score++;
        }
    }

    printf("\n\nYour score: %d/%d", score, MAX_QUESTIONS);

    return 0;
}