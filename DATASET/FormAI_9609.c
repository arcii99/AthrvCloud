//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

int main () {
  
  printf("\nWelcome to the Periodic Table Quiz!\n");
  printf("This quiz will test your knowledge on the elements of the periodic table.\n");
  
  int questions_asked = 0;
  int correct_answers = 0;
  
  char elements[MAX_QUESTIONS][2][25] = { 
    {"What is the symbol for Helium? ", "He"},
    {"What is the symbol for Sodium? ", "Na"},
    {"What is the symbol for Carbon? ", "C"},
    {"What is the symbol for Oxygen? ", "O"},
    {"What is the symbol for Gold? ", "Au"},
    {"What is the symbol for Calcium? ", "Ca"},
    {"What is the symbol for Nitrogen? ", "N"},
    {"What is the symbol for Silver? ", "Ag"},
    {"What is the symbol for Iron? ", "Fe"},
    {"What is the symbol for Chlorine? ", "Cl"}
  };
  
  while (questions_asked < MAX_QUESTIONS) {
    
    int random_num = rand() % MAX_QUESTIONS;
    
    int already_asked = 0;
    for (int i = 0; i < questions_asked; i++) {
      if (strcmp(elements[random_num][0], elements[i][0]) == 0) {
        already_asked = 1;
        break;
      }
    }
    
    if (!already_asked) {
      printf("%s", elements[random_num][0]);
      
      char answer[25];
      fgets(answer, 25, stdin);
      answer[strcspn(answer, "\n")] = 0;
      
      if (strcmp(answer, elements[random_num][1]) == 0) {
        printf("Correct!\n");
        correct_answers++;
      } else {
        printf("Incorrect. The correct answer is %s\n", elements[random_num][1]);
      }
      
      questions_asked++;
    }
    
  }
  
  printf("\nQuiz Complete! You scored %d out of %d.\n", correct_answers, MAX_QUESTIONS);
  
  return 0;
}