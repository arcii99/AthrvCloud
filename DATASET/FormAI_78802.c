//FormAI DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>

// Function to display instructions on the exam
void displayInstructions() {
   printf("Welcome to the Online Examination System! \n\n");
   printf("You will be given 60 minutes to complete the exam. \n");
   printf("There are a total of 20 multiple choice questions. \n");
   printf("Each correct answer is worth 5 points and each wrong answer is worth -1 point. \n");
   printf("You cannot go back to previous questions once you have answered them. \n");
   printf("Good luck! \n\n");
}

// Function to display the questions and collect answers from the user
void takeExam() {
   int numQuestions = 20;
   int score = 0;
   int answer;
   
   for (int i = 1; i <= numQuestions; i++) {
      printf("Question %d: What is the capital of France? \n", i);
      printf("1. Berlin\n");
      printf("2. London\n");
      printf("3. Paris\n");
      printf("4. Madrid\n");
      
      printf("Enter your answer: ");
      scanf("%d", &answer);
      
      // Validate the user's answer
      if (answer == 3) {
         score += 5;
      } else {
         score -= 1;
      }
   }
   
   printf("Exam complete! \n");
   printf("Your score is: %d \n", score);
}

// Main function to run the program
int main() {
   displayInstructions(); // Display the exam instructions
   takeExam(); // Take the exam
   
   return 0;
}