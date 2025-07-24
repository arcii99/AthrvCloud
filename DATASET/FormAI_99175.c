//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>

#define MAX 100

int main() {
    int num_forms, max_score, total_score = 0, i;
    float fractional_score[MAX], fractional_score_sum = 0;

    printf("Enter the number of forms: ");
    scanf("%d", &num_forms);

    printf("Enter the maximum score per form: ");
    scanf("%d", &max_score);

    int scores[num_forms];
    for(i = 0; i < num_forms; i++) {
        printf("Enter the score for form %d: ", i+1);
        scanf("%d", &scores[i]);
        total_score += scores[i];
        fractional_score[i] = (float)scores[i] / max_score;
        fractional_score_sum += fractional_score[i];
    }

    float average_fractional_score = fractional_score_sum / num_forms;
    int required_score = (int)(average_fractional_score * max_score);

    printf("\nTotal score: %d\nAverage fractional score: %.2f\nRequired score for passing: %d\n", total_score, average_fractional_score, required_score);

    // Greedy algorithm to find the minimum number of forms required to pass
    int forms_needed = 0, score_achieved = 0;
    i = num_forms - 1;
    while(score_achieved < required_score) {
        forms_needed++;
        score_achieved += scores[i--];
    }

    printf("\nMinimum number of forms required to pass: %d\n", forms_needed);

    return 0;
}