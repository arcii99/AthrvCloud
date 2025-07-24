//FormAI DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
  // welcome message
  printf("Welcome to the online exam system!\n");

  // create an array of questions
  char questions[5][100] = {"What is the capital of France?", "What is the largest planet in our solar system?", "What is the symbol for sodium on the periodic table?", "What is the process of a gas turning into a liquid called?", "What is the full form of HTML?"};

  // create an array of answers
  char answers[5][100] = {"Paris", "Jupiter", "Na", "Condensation", "Hyper Text Markup Language"};

  // initialize score and user's answer
  int score = 0;
  char userAnswer[100];

  // loop through each question
  for (int i = 0; i < 5; i++) {

    // display question
    printf("Question %d: %s\n", i+1, questions[i]);

    // get user's answer
    scanf("%s", userAnswer);

    // check if the answer is correct
    if (strcmp(userAnswer, answers[i]) == 0) {
      printf("Correct answer!\n");
      score++;
    } else {
      printf("Incorrect answer. The correct answer is %s.\n", answers[i]);
    }
  }

  // display final score
  printf("Your final score is %d out of 5.\n", score);

  return 0;
}