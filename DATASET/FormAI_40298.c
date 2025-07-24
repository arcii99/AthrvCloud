//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void printWelcomeMessage();
int askQuestion();
void generateRandomAnswer(int);

int main() {
  printWelcomeMessage();
  int questionNo = askQuestion();
  generateRandomAnswer(questionNo);
  return 0; // All done
}

void printWelcomeMessage() {
  printf("Hi! I am a fortune teller program. Ask me a question and I will tell your fortune!\n");
}

int askQuestion() {
  int questionNo;
  
  printf("Please ask your question by typing any number between 1 and 10:\n");
  scanf("%d", &questionNo);
  
  if (questionNo > 10 || questionNo < 1) {
    printf("Sorry, that's an invalid question number. Please enter a number between 1 and 10.\n");
    askQuestion(); // Recursive call until valid input is provided
  }
  
  return questionNo;
}

void generateRandomAnswer(int questionNo) {
  char* answers[] = {"Yes, definitely.", "Most likely.", "Outlook good.", "Signs point to yes.", "Reply hazy, try again.", 
                     "Ask again later.", "Don't count on it.", "Outlook not so good.", "Very doubtful.", "Cannot predict now."};
  
  srand(time(NULL)); // Initialize random seed
  
  printf("Your fortune is: %s\n", answers[rand() % 10]); // Generate random answer
}