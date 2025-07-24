//FormAI DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numQuestions = 10; // number of questions
int numOptions = 4; // number of options for each question

char questions[10][100] = {
  "What is the capital of France?",
  "What is the largest country in the world?",
  "What is the tallest mammal in the world?",
  "What year was the first iPhone released?",
  "What is the name of the world's largest desert?",
  "What is the currency of Brazil?",
  "Who was the first president of the United States?",
  "What is the highest mountain peak in Africa?",
  "What is the formula for water?",
  "What is the chemical symbol for gold?"
};

char options[10][4][20] = {
  {"A. Paris", "B. London", "C. Rome", "D. Berlin"},
  {"A. Russia", "B. Canada", "C. United States", "D. China"},
  {"A. Giraffe", "B. Lion", "C. Elephant", "D. Whale"},
  {"A. 2005", "B. 2006", "C. 2007", "D. 2008"},
  {"A. Sahara", "B. Gobi", "C. Atacama", "D. Kalahari"},
  {"A. Yen", "B. Ruble", "C. Real", "D. Dollar"},
  {"A. George Washington", "B. Abraham Lincoln", "C. Thomas Jefferson", "D. John Adams"},
  {"A. Mount Kilimanjaro", "B. Mount Everest", "C. Mount McKinley", "D. Mount Vinson"},
  {"A. H2O", "B. CO2", "C. NaCl", "D. C6H12O6"},
  {"A. Au", "B. Ag", "C. Fe", "D. Cu"}
};

char answers[10] = {'A', 'A', 'A', 'B', 'A', 'C', 'A', 'A', 'A', 'A'};

void printQuestion(int questionNum){
  int i;
  printf("%d. %s\n", questionNum+1, questions[questionNum]);
  for (i=0; i<numOptions; i++){
    printf("  %s\n", options[questionNum][i]);
  }
}

char takeTest(){
  int i, score = 0;
  char answer, input;
  printf("Welcome to the Online Examination System!\n");
  printf("You will be asked 10 multiple choice questions.\n");
  printf("Enter the letter corresponding to your choice and press Enter.\n");
  printf("Good luck!\n");
  for (i=0; i<numQuestions; i++){
    printQuestion(i);
    while(1){
      input = getchar();
      if (input >= 'a' && input <= 'z'){
        answer = input - 'a' + 'A'; // convert lowercase to uppercase
      }
      else if (input >= 'A' && input <= 'Z'){
        answer = input;
      }
      else {
        continue;
      }
      if (answer < 'A' || answer >= 'A'+numOptions){
        continue;
      }
      break;
    }
    printf("\n");
    if (answer == answers[i]){
      score++;
      printf("Correct!\n\n");
    }
    else {
      printf("Incorrect. The correct answer is %c.\n\n", answers[i]);
    }
  }
  printf("You answered %d out of %d questions correctly.\n", score, numQuestions);
  return score >= 7 ? 'P' : 'F';
}

int main(){
  char grade;
  srand(time(NULL));
  grade = takeTest();
  printf("Your grade: %c\n", grade);
  return 0;
}