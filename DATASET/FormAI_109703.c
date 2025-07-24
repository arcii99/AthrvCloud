//FormAI DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  int num1, num2, answer, user_answer;
  int score = 0, i;
  
  srand(time(0));
  
  printf("***** Maths Quiz *****\n\n");
  printf("Solve the following 10 mathematical equations: \n\n");
  
  for(i = 1; i <= 10; i++) {

    num1 = rand() % 50;
    num2 = rand() % 50;
    
    if(i % 2 == 0) {
      answer = num1 - num2;
      printf("%d) %d - %d = ", i, num1, num2);
    } else {
      answer = num1 + num2;
      printf("%d) %d + %d = ", i, num1, num2);
    }
    
    scanf("%d", &user_answer);
    
    if(user_answer == answer) {
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect! The answer is %d.\n", answer);
    }
    
    printf("\n");
    
  }
  
  printf("Your final score is: %d\n", score);
  
  return 0;
}