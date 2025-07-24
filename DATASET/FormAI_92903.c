//FormAI DATASET v1.0 Category: Online Examination System ; Style: Cryptic
#include<stdio.h>

int main() {
  int questions[10] = {24, 36, 48, 67, 55, 29, 83, 42, 19, 76}; // Array containing the correct answers to the questions
  int ans, score = 0;
  
  printf("Welcome to the Cryptic online examination system!\n");
  printf("Please answer the following 10 questions:\n");
  
  for(int i=0;i<10;i++) {
    printf("Question #%d - What is the square of %d? ", i+1, i+1); // Asking the questions
    scanf("%d", &ans); // Reading the answer from the user
    if(ans == questions[i]) { // Checking if the answer is correct
      printf("Correct answer!\n");
      score++;
    } else {
      printf("Wrong answer, the correct answer is %d.\n", questions[i]);
    }
  }
  
  printf("\nYou scored %d out of 10.\n", score); // Showing the final score
  
  return 0;
}