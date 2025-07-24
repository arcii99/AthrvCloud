//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   time_t t;
   srand((unsigned) time(&t)); /* Initializing random number generator */

   char *questions[10] = {"Do you think someone is watching you?", "Are you paranoid about your safety?", 
   "Do you trust people easily?", "Do you think you are being followed?", 
   "Do you feel like you are being listened to?", "Do you think you are in danger?",
   "Do you feel like you are being spied on?", "Do you look over your shoulder frequently?",
   "Do you feel like someone is out to get you?", "Do you have a hard time sleeping at night?"};
   
   char *fortunes[10] = {"The future is uncertain. It is best to be prepared.", "Paranoia may save your life one day.",
   "Trust your instincts, but don't let fear guide you.", "Stay alert, but don't let fear control your life.",
   "Your fears may be unfounded, but it is always better to be safe than sorry.", "Keep your guard up, but don't let paranoia consume you.",
   "You are right to be cautious, but don't forget to enjoy life.", "Fear can be a powerful motivator, but don't let it dominate your thoughts.",
   "Your instincts are sharp, but take some time to relax and recharge.", "There is no harm in being cautious, but don't let it consume your life."};

   char answer;
   do {
      printf("Welcome to the Paranoid Fortune Teller! Ask me a yes or no question: ");
      char question[100];
      fgets(question, 100, stdin); /* Taking input from user */
      printf("\nThinking...\n\n");
      
      int random_num = rand() % 10; /* Generating a random number between 0 and 9 */
      printf("Question: %s\n", questions[random_num]);
      printf("Answer: %s\n", fortunes[random_num]);
      
      printf("\nWould you like to ask another question? (Y/N): ");
      scanf(" %c", &answer);  /* Taking input from user */
      getchar();
   } while (answer == 'Y' || answer == 'y');

   printf("\nThank you for visiting the Paranoid Fortune Teller!\n");
   
   return 0;
}