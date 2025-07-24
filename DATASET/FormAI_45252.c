//FormAI DATASET v1.0 Category: Online Examination System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
  char question[200];
  char options[4][50];
  int answer;
};

struct User {
  char name[50];
  int score;
};

int num_questions = 5; // Total number of questions
struct Question exam_question[5]; // Array of questions for exam
struct User user; // User taking the exam

void print_menu() {
  printf("Welcome to the Online Examination System\n");
  printf("1. Start Exam\n");
  printf("2. View Instructions\n");
  printf("3. Exit\n");
}

void start_exam() {
  printf("Starting Exam...\n");
  for(int i=0; i<num_questions; i++) {
    printf("Question %d: %s\n", i+1, exam_question[i].question);
    printf("Options:\n");
    for(int j=0; j<4; j++) {
      printf("%d. %s\n", j+1, exam_question[i].options[j]);
    }
    printf("Enter your answer (1-4): ");
    int user_answer;
    scanf("%d", &user_answer);
    if(user_answer == exam_question[i].answer) {
      user.score += 1;
    }
  }
  printf("\nExam Over!\n");
}

void display_instructions() {
  printf("Instructions:\n");
  printf("1. This is a multiple choice exam with %d questions.\n", num_questions);
  printf("2. Each question has 4 options. Select the correct answer from the available options by entering the corresponding option number.\n", num_questions);
  printf("3. Total marks for the exam is %d.\n", num_questions);
  printf("4. Once you start the exam, you cannot pause or undo your answers.\n\n");
}

int main() {
  // Set up questions and answers
  strcpy(exam_question[0].question, "What is the capital of India?");
  strcpy(exam_question[0].options[0], "Mumbai");
  strcpy(exam_question[0].options[1], "Delhi");
  strcpy(exam_question[0].options[2], "Kolkata");
  strcpy(exam_question[0].options[3], "Chennai");
  exam_question[0].answer = 2;

  strcpy(exam_question[1].question, "Who developed C programming language?");
  strcpy(exam_question[1].options[0], "Dennis Ritchie");
  strcpy(exam_question[1].options[1], "Linus Torvalds");
  strcpy(exam_question[1].options[2], "Guido van Rossum");
  strcpy(exam_question[1].options[3], "James Gosling");
  exam_question[1].answer = 1;

  strcpy(exam_question[2].question, "What is the size of int data type in C?");
  strcpy(exam_question[2].options[0], "1 byte");
  strcpy(exam_question[2].options[1], "2 bytes");
  strcpy(exam_question[2].options[2], "4 bytes");
  strcpy(exam_question[2].options[3], "8 bytes");
  exam_question[2].answer = 3;

  strcpy(exam_question[3].question, "Which of the following is not a loop statement in C?");
  strcpy(exam_question[3].options[0], "while");
  strcpy(exam_question[3].options[1], "for");
  strcpy(exam_question[3].options[2], "do-while");
  strcpy(exam_question[3].options[3], "switch");
  exam_question[3].answer = 4;

  strcpy(exam_question[4].question, "What is the result of 2+2*4/2-3?");
  strcpy(exam_question[4].options[0], "0");
  strcpy(exam_question[4].options[1], "1");
  strcpy(exam_question[4].options[2], "2");
  strcpy(exam_question[4].options[3], "3");
  exam_question[4].answer = 2;

  // Display menu and get user input
  int menu_choice;
  do {
    print_menu();
    printf("Enter your choice: ");
    scanf("%d", &menu_choice);

    switch(menu_choice) {
      case 1:
        // Start exam
        printf("Enter your name: ");
        scanf("%s", user.name);
        printf("\n%s, let's start the exam:\n", user.name);
        start_exam();
        printf("Your score: %d/%d", user.score, num_questions);
        getchar();
        break;
        
      case 2:
        // View instructions
        display_instructions();
        getchar();
        break;

      case 3:
        // Exit
        printf("Goodbye!\n");
        exit(0);
        break;

      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while(menu_choice != 3);

  return 0;
}