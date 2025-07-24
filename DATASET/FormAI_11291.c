//FormAI DATASET v1.0 Category: Online Examination System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct question {
    char ques[200];
    char options[4][50];
    int ans;
} question;

question exam[10];

int main() {
    int marks = 0;
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome to the Online Examination System, %s\n\n", name);

    // Question 1
    strcpy(exam[0].ques, "What is the capital of India?");
    strcpy(exam[0].options[0], "A. New Delhi");
    strcpy(exam[0].options[1], "B. Mumbai");
    strcpy(exam[0].options[2], "C. Bangalore");
    strcpy(exam[0].options[3], "D. Kolkata");
    exam[0].ans = 0;

    // Question 2
    strcpy(exam[1].ques, "Who is the current Prime Minister of India?");
    strcpy(exam[1].options[0], "A. Narendra Modi");
    strcpy(exam[1].options[1], "B. Rahul Gandhi");
    strcpy(exam[1].options[2], "C. Manmohan Singh");
    strcpy(exam[1].options[3], "D. Atal Bihari Vajpayee");
    exam[1].ans = 0;

    // Question 3
    strcpy(exam[2].ques, "Who invented the telephone?");
    strcpy(exam[2].options[0], "A. Thomas Edison");
    strcpy(exam[2].options[1], "B. Alexander Graham Bell");
    strcpy(exam[2].options[2], "C. Benjamin Franklin");
    strcpy(exam[2].options[3], "D. Isaac Newton");
    exam[2].ans = 1;

    // Question 4
    strcpy(exam[3].ques, "What is the largest planet in our solar system?");
    strcpy(exam[3].options[0], "A. Earth");
    strcpy(exam[3].options[1], "B. Jupiter");
    strcpy(exam[3].options[2], "C. Mars");
    strcpy(exam[3].options[3], "D. Venus");
    exam[3].ans = 1;

    // Question 5
    strcpy(exam[4].ques, "What is the currency of Japan?");
    strcpy(exam[4].options[0], "A. Yen");
    strcpy(exam[4].options[1], "B. Won");
    strcpy(exam[4].options[2], "C. Euro");
    strcpy(exam[4].options[3], "D. Dollar");
    exam[4].ans = 0;

    printf("Answer the following questions:\n\n");

    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i+1, exam[i].ques);

        for (int j = 0; j < 4; j++) {
            printf("%s\n", exam[i].options[j]);
        }

        int ans;
        printf("Enter your answer (1-4): ");
        scanf("%d", &ans);

        if (ans-1 == exam[i].ans) {
            marks += 2;
        }
    }

    printf("\nThank you for taking the exam, %s\n", name);
    printf("Your total marks are: %d\n", marks);

    return 0;
}