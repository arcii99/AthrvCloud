//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a, b, c, answer, user_answer;
  int score = 0;
  srand(time(NULL));
  printf("Welcome to the Math Exercise!\n");

  for(int i = 0; i < 10; i++) {
    // Generating random numbers
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    c = rand() % 10 + 1;
    answer = a + b * c;    // Calculating the answer
    
    printf("\nQuestion %d: What is %d + %d * %d ?\n", i+1, a, b, c);
    printf("Enter your answer: ");
    scanf("%d", &user_answer);

    if(user_answer == answer) {
      printf("Correct answer!\n");
      score++;
    }
    else {
      printf("Wrong answer. The correct answer is %d.\n", answer);
    }
  }
  
  printf("\n\nYour final score is %d out of 10.\n", score);
  if(score >= 8) {
    printf("Excellent! You are a Math genius.\n");
  }
  else if(score >= 5) {
    printf("Good job! You have a decent Math aptitude.\n");
  }
  else {
    printf("Seems like Math is not your thing. Keep practicing!\n");
  }

  return 0;
}