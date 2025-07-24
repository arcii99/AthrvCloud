//FormAI DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 10
#define MAX_QUESTION_LENGTH 100
#define MAX_ANSWER_LENGTH 20

/*
 * In this program, we will create an Online Examination System
 * for a Computer Science course. This system will allow students
 * to take an exam consisting of multiple choice questions with
 * randomized answers. At the end of the exam, the program will
 * automatically grade the exam and provide the student with
 * their score.
 */

int main() {
  char questions[MAX_QUESTIONS][MAX_QUESTION_LENGTH];
  char answers[MAX_QUESTIONS][4][MAX_ANSWER_LENGTH];
  char user_answers[MAX_QUESTIONS][MAX_ANSWER_LENGTH];
  int correct_answers = 0, total_questions = 0;

  // Get the number of questions from the user
  printf("Welcome to the Computer Science Online Examination System!\n");
  printf("Please enter the number of questions in the exam: ");
  scanf("%d", &total_questions);

  // Make sure the number of questions is valid
  if (total_questions < 1 || total_questions > MAX_QUESTIONS) {
    printf("Invalid number of questions.\n");
    return 1;
  }

  // Get the questions and answers from the user
  printf("Please enter the questions and answers for the exam:\n");
  for (int i = 0; i < total_questions; i++) {
    // Get the question
    printf("Question %d: ", i+1);
    scanf(" %[^\n]", questions[i]);

    // Get the answers
    for (int j = 0; j < 4; j++) {
      printf("Answer %c: ", 'A'+j);
      scanf(" %[^\n]", answers[i][j]);
    }

    // Shuffle the answers
    for (int j = 0; j < 4; j++) {
      int k = rand() % 4;
      char temp[MAX_ANSWER_LENGTH];
      strcpy(temp, answers[i][j]);
      strcpy(answers[i][j], answers[i][k]);
      strcpy(answers[i][k], temp);
    }
  }

  // Admin panel
  int admin_choice;
  printf("Enter 1 to view the list of questions and answers and 0 to skip the admin panel: ");
  scanf("%d", &admin_choice);

  if (admin_choice == 1) {
    printf("List of questions and answers:\n");
    for (int i = 0; i < total_questions; i++) {
      printf("Question %d: %s\n", i+1, questions[i]);
      printf("Answers:\n");
      for (int j = 0; j < 4; j++) {
        printf("  %c. %s\n", 'A'+j, answers[i][j]);
      }
    }
  }

  // Take the exam
  printf("You are now taking the exam. Good luck!\n");
  for (int i = 0; i < total_questions; i++) {
    printf("\nQuestion %d: %s\n", i+1, questions[i]);
    printf("Select your answer (A/B/C/D): ");
    scanf(" %[^\n]", user_answers[i]);

    // Make sure the answer is valid
    if (user_answers[i][0] < 'A' || user_answers[i][0] > 'D') {
      printf("Invalid answer. Please enter A, B, C, or D.\n");
      i--;
      continue;
    }

    // Grade the question
    int answer_index = user_answers[i][0] - 'A';
    if (strcmp(answers[i][answer_index], answers[i][0]) == 0) {
      correct_answers++;
    }
  }

  // Display the score
  double percentage = (double)correct_answers / total_questions * 100;
  printf("\nYour score is %.2lf%% (%d out of %d).\n", percentage, correct_answers, total_questions);

  return 0;
}