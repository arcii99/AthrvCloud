//FormAI DATASET v1.0 Category: Online Examination System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    int correct_ans;
};

struct Student {
    char name[50];
    int marks;
};

void add_question(struct Question *q, int *num_questions) {
    printf("Enter the question: ");
    scanf(" %[^\n]s", q[*num_questions].question);
    printf("Enter option 1: ");
    scanf(" %[^\n]s", q[*num_questions].option1);
    printf("Enter option 2: ");
    scanf(" %[^\n]s", q[*num_questions].option2);
    printf("Enter option 3: ");
    scanf(" %[^\n]s", q[*num_questions].option3);
    printf("Enter option 4: ");
    scanf(" %[^\n]s", q[*num_questions].option4);
    printf("Enter the number of the correct option: ");
    scanf("%d", &q[*num_questions].correct_ans);
    (*num_questions)++;
}

void display_question(struct Question q) {
    printf("%s\n", q.question);
    printf("1. %s\n", q.option1);
    printf("2. %s\n", q.option2);
    printf("3. %s\n", q.option3);
    printf("4. %s\n", q.option4);
}

int take_test(struct Question *q, int num_questions) {
    int marks = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        display_question(q[i]);
        printf("Enter the answer: ");
        int ans;
        scanf("%d", &ans);
        if (ans == q[i].correct_ans) {
            marks++;
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer is %d.\n", q[i].correct_ans);
        }
    }
    return marks;
}

void display_results(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("Marks: %d\n", s.marks);
}

int main() {
    struct Question question_bank[100];
    int num_questions = 0;
    while (1) {
        printf("1. Add question to question bank\n");
        printf("2. Take test\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            add_question(question_bank, &num_questions);
        } else if (choice == 2) {
            struct Student s;
            printf("Enter your name: ");
            scanf(" %[^\n]s", s.name);
            s.marks = take_test(question_bank, num_questions);
            display_results(s);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}