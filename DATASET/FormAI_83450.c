//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
    int scores[] = {0, 0, 0, 0};
    int question_num = 1;
    printf("Welcome to the C Periodic Table Quiz!\n\n");

    printf("Question %d: What is the symbol for oxygen?\n", question_num);
    printf("A) O  B) Ox  C) Oxon  D) Oxide\n");
    char ans = getchar();
    getchar(); // to flush the input buffer
    if (ans == 'A' || ans == 'a') {
        printf("Correct!\n");
        scores[0]++;
    } else {
        printf("Incorrect!\n");
    }
    question_num++;

    printf("\nQuestion %d: How many valence electrons does carbon have?\n", question_num);
    printf("A) 2  B) 4  C) 6  D) 8\n");
    ans = getchar();
    getchar();
    if (ans == 'B' || ans == 'b') {
        printf("Correct!\n");
        scores[1]++;
    } else {
        printf("Incorrect!\n");
    }
    question_num++;

    printf("\nQuestion %d: Which element has the symbol 'K'?\n", question_num);
    printf("A) Potassium  B) Phosphorus  C) Platinum  D) Polonium\n");
    ans = getchar();
    getchar();
    if (ans == 'A' || ans == 'a') {
        printf("Correct!\n");
        scores[2]++;
    } else {
        printf("Incorrect!\n");
    }
    question_num++;

    printf("\nQuestion %d: How many electrons does an atom of helium have in its outermost shell?\n", question_num);
    printf("A) 1  B) 2  C) 3  D) 4\n");
    ans = getchar();
    getchar();
    if (ans == 'B' || ans == 'b') {
        printf("Correct!\n");
        scores[3]++;
    } else {
        printf("Incorrect!\n");
    }
    question_num++;

    printf("\nThank you for taking the quiz!\n");
    printf("Your scores:\n");
    printf("Question 1: %d out of 1\n", scores[0]);
    printf("Question 2: %d out of 1\n", scores[1]);
    printf("Question 3: %d out of 1\n", scores[2]);
    printf("Question 4: %d out of 1\n", scores[3]);

    return 0;
}