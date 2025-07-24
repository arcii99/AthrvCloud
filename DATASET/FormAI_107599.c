//FormAI DATASET v1.0 Category: Online Examination System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// function to create an exam
void createExam() {
  printf("Welcome to the Online Exam System!\n");
  printf("Please enter the number of questions for this exam: ");
  int num_questions;
  scanf("%d", &num_questions);

  // dynamically allocate memory for questions
  char** questions = (char**) malloc(num_questions * sizeof(char*));
  for (int i = 0; i < num_questions; i++) {
    questions[i] = (char*) malloc(100 * sizeof(char));
    printf("Enter question %d: ", i+1);
    scanf(" %[^\n]s", questions[i]);
  }

  // dynamically allocate memory for answers
  char** answers = (char**) malloc(num_questions * sizeof(char*));
  for (int i = 0; i < num_questions; i++) {
    answers[i] = (char*) malloc(50 * sizeof(char));
    printf("Enter answer for question %d: ", i+1);
    scanf(" %[^\n]s", answers[i]);
  }

  // display the exam questions and answers
  printf("\nExam created with the following questions and answers:\n");
  for (int i = 0; i < num_questions; i++) {
    printf("\n%d. %s\n", i+1, questions[i]);
    printf("Answer: %s\n", answers[i]);
  }

  // free dynamically allocated memory
  for (int i = 0; i < num_questions; i++) {
    free(questions[i]);
    free(answers[i]);
  }
  free(questions);
  free(answers);
}

int main() {
  createExam();
  return 0;
}