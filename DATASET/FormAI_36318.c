//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int score = 0; // initialize score to zero
  
  // initialize the multi-dimensional array containing the questions and answers
  char periodicTable[5][5][50] = {
    {{"What is the symbol for Oxygen?"}, {"O"}}, 
    {{"What is the atomic number of Carbon?"}, {"6"}}, 
    {{"What is the symbol for Iron?"}, {"Fe"}}, 
    {{"What is the heaviest element on the periodic table?"}, {"Oganesson"}}, 
    {{"What is the symbol for Mercury?"}, {"Hg"}}
  };
  
  printf("Welcome to the Periodic Table Quiz!\n\n");
  
  srand(time(NULL)); // initialize random seed based on current time
  for (int i = 0; i < 5; i++) {
    int random = rand() % 5; // get a random integer between 0 and 4
    char question[50];
    char answer[50];
    strcpy(question, periodicTable[random][0]); // copy the question from the array
    strcpy(answer, periodicTable[random][1]); // copy the answer from the array
    
    printf("Question %d: %s\n", i+1, question); // print the question
    
    char userAnswer[50];
    printf("Enter your answer: ");
    scanf("%s", userAnswer); // get the user's answer
    
    if (strcmp(userAnswer, answer) == 0) { // compare the user's answer to the correct answer
      printf("Correct!\n");
      score++; // increment score if correct
    } else {
      printf("Incorrect. The correct answer is %s\n", answer);
    }
    
    printf("\n");
  }
  
  printf("Quiz complete! You scored %d out of 5.\n", score);
  
  return 0;
}