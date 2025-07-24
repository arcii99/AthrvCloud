//FormAI DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int marks, total_marks = 0;
    int i, num_of_questions;

    printf("Enter the number of questions: ");
    scanf("%d", &num_of_questions);

    int correct[num_of_questions];
    char answer;

    printf("Enter the correct answers (A,B,C,D): ");
    for (i = 0; i < num_of_questions; i++) {
        scanf(" %c", &answer);
        correct[i] = answer;
    }

    printf("Enter the student's answers: ");
    for (i = 0; i < num_of_questions; i++) {
        scanf(" %c", &answer);
        if (answer == correct[i]) {
            marks = 1;
            total_marks += marks;
        }
    }

    printf("Total marks obtained: %d\n", total_marks);

    if (total_marks >= num_of_questions/2) {
        printf("Result: Passed\n");
    } else {
        printf("Result: Failed\n");
    }

    return 0;
}