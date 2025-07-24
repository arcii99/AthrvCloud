//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int generate_random(int max_num) {
  srand(time(0));
  int num = rand() % max_num;
  return num;
}

int main() {
  char questions[5][100] = {"What is my future career?", "Will I win the lottery?", 
    "Will I find true love?", "Will I have children?", "Will I achieve my dreams?"};
  char fortunes[5][100] = {"Most definitely!", "Don't count on it...", "The answer is unclear", 
    "Signs point to yes!", "Outlook not so good."};
  
  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Ask a question and receive your fortune.\n");
  printf("-----------------------------------------\n");
  
  while(1) {
    char response[10];
    printf("Enter your question (or enter 'quit' to exit): ");
    fgets(response, 10, stdin);
    response[strcspn(response, "\n")] = 0;
    
    if(strcmp(response, "quit") == 0) {
      printf("\nThank you for using the Automated Fortune Teller.\n");
      break;
    }
    
    printf("Thinking...\n");
    int random_num = generate_random(5);
    printf("%s %s\n\n", questions[random_num], fortunes[random_num]);
  }

  return 0;
}