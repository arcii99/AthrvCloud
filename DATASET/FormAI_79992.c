//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the question
struct question {
  char question_title[100];
  char answer_1[100];
  char answer_2[100];
  char answer_3[100];
  char answer_4[100];
  int correct_answer;
};

int main() {
  struct question questions[10];

  // Insert question data
  strcpy(questions[0].question_title, "What is the capital of France?");
  strcpy(questions[0].answer_1, "Paris");
  strcpy(questions[0].answer_2, "London");
  strcpy(questions[0].answer_3, "Madrid");
  strcpy(questions[0].answer_4, "Rome");
  questions[0].correct_answer = 1;

  strcpy(questions[1].question_title, "What is the highest mountain in the world?");
  strcpy(questions[1].answer_1, "Mount Everest");
  strcpy(questions[1].answer_2, "Mount Kilimanjaro");
  strcpy(questions[1].answer_3, "Mount Denali");
  strcpy(questions[1].answer_4, "Mount Fuji");
  questions[1].correct_answer = 1;

  // Display the questions and get the user's answers
  int user_answers[10];
  for (int i = 0; i < 2; i++) {
    printf("%d) %s\n", i + 1, questions[i].question_title);
    printf("   1. %s\n", questions[i].answer_1);
    printf("   2. %s\n", questions[i].answer_2);
    printf("   3. %s\n", questions[i].answer_3);
    printf("   4. %s\n", questions[i].answer_4);
    printf("   Enter answer (1-4): ");
    scanf("%d", &user_answers[i]);
  }

  // Calculate the user's score
  int score = 0;
  for (int i = 0; i < 2; i++) {
    if (user_answers[i] == questions[i].correct_answer) {
      score++;
    }
  }

  // Display the user's score
  printf("You scored %d out of 2.\n", score);

  return 0;
}