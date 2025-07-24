//FormAI DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
  int id;
  char description[100];
  char options[4][50];
  char answer;
};

int main() {
  int i,j,k;
  int num_questions = 5;
  
  struct question questions[num_questions];

  // Add questions
  questions[0].id = 1;
  strcpy(questions[0].description, "What is the capital of France?");
  strcpy(questions[0].options[0], "A: London");
  strcpy(questions[0].options[1], "B: Paris");
  strcpy(questions[0].options[2], "C: Berlin");
  strcpy(questions[0].options[3], "D: Madrid");
  questions[0].answer = 'B';

  questions[1].id = 2;
  strcpy(questions[1].description, "Who is the author of Harry Potter?");
  strcpy(questions[1].options[0], "A: J.K. Rowling");
  strcpy(questions[1].options[1], "B: Stephen King");
  strcpy(questions[1].options[2], "C: Dan Brown");
  strcpy(questions[1].options[3], "D: Agatha Christie");
  questions[1].answer = 'A';

  questions[2].id = 3;
  strcpy(questions[2].description, "What is the national animal of India?");
  strcpy(questions[2].options[0], "A: Tiger");
  strcpy(questions[2].options[1], "B: Lion");
  strcpy(questions[2].options[2], "C: Elephant");
  strcpy(questions[2].options[3], "D: Rhinoceros");
  questions[2].answer = 'A';

  questions[3].id = 4;
  strcpy(questions[3].description, "What is the currency of Thailand?");
  strcpy(questions[3].options[0], "A: Dollar");
  strcpy(questions[3].options[1], "B: Euro");
  strcpy(questions[3].options[2], "C: Baht");
  strcpy(questions[3].options[3], "D: Yen");
  questions[3].answer = 'C';

  questions[4].id = 5;
  strcpy(questions[4].description, "What is the highest mountain in the world?");
  strcpy(questions[4].options[0], "A: Mount Kilimanjaro");
  strcpy(questions[4].options[1], "B: Mount Everest");
  strcpy(questions[4].options[2], "C: Mount Fuji");
  strcpy(questions[4].options[3], "D: Mount Denali");
  questions[4].answer = 'B';


  // Admin login
  char admin_username[20];
  char admin_password[20];
  printf("Welcome! Please enter your admin username: ");
  scanf("%s", admin_username);
  printf("Please enter your admin password: ");
  scanf("%s", admin_password);
  if (strcmp(admin_username, "admin") == 0 && strcmp(admin_password, "password123") == 0) {
    printf("Welcome, admin!\n\n");

    // Display questions
    for (i = 0; i < num_questions; i++) {
      printf("Question %d:\n", questions[i].id);
      printf("%s\n", questions[i].description);
      for (j = 0; j < 4; j++) {
        printf("%s\n", questions[i].options[j]);
      }
      printf("\n");
    }

    // Add a question
    struct question new_question;
    new_question.id = num_questions + 1;
    printf("Enter the new question: ");
    getchar();
    fgets(new_question.description, 100, stdin);
    printf("Enter option A: ");
    fgets(new_question.options[0], 50, stdin);
    printf("Enter option B: ");
    fgets(new_question.options[1], 50, stdin);
    printf("Enter option C: ");
    fgets(new_question.options[2], 50, stdin);
    printf("Enter option D: ");
    fgets(new_question.options[3], 50, stdin);
    getchar();
    printf("Enter the answer (A, B, C, or D): ");
    scanf("%c", &new_question.answer);
    questions[num_questions] = new_question;
    num_questions++;

    // Display questions again
    printf("\nUpdated questions:\n");
    for (i = 0; i < num_questions; i++) {
      printf("Question %d:\n", questions[i].id);
      printf("%s\n", questions[i].description);
      for (j = 0; j < 4; j++) {
        printf("%s\n", questions[i].options[j]);
      }
      printf("\n");
    }

  } else {
    printf("Login failed. Goodbye!");
  }

  return 0;
}