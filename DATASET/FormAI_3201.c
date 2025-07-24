//FormAI DATASET v1.0 Category: Math exercise ; Style: cheerful
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

  // Display a cheerful message for the user
  printf("Welcome to the Math Exercise program! Let's have some fun!\n");

  // Seed the random function for generating numbers
  srand(time(NULL));

  // Generate two random numbers between 1 and 100
  int num1 = rand() % 100 + 1;
  int num2 = rand() % 100 + 1;

  // Display the two numbers for the user and ask them to add them together
  printf("What is the sum of %d and %d?\n", num1, num2);

  // Read in the user's answer
  int answer;
  scanf("%d", &answer);

  // Calculate the correct answer
  int correct_answer = num1 + num2;

  // Check if the user's answer is correct
  if (answer == correct_answer) {

    // Display a message congratulating the user
    printf("Congratulations, you got the right answer! That was easy!\n");

  } else {
    
    // Display a message showing the correct answer and encouraging the user to keep trying
    printf("Sorry, that is not correct. The correct answer is %d.\n", correct_answer);
    printf("Keep trying, you'll get it next time!\n");
  }

  // Display a message thanking the user for using the program
  printf("Thank you for using the Math Exercise program! Come back soon!\n");

  return 0;
}