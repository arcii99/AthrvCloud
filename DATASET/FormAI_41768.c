//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL));  // seed the random number generator with the current time
   int num = rand() % 10;  // generate a random number between 0-9
   
   // fortune array with surrealistic messages
   char *fortunes[] = {"The moon is made of cheese and so are you.\n", 
                       "Your ancestors were unicorns and mermaids.\n", 
                       "Your future is a kaleidoscope of pastel colors.\n", 
                       "The stars predict that you will become a time traveler.\n", 
                       "You will learn to communicate with dolphins.\n", 
                       "Your dreams will be filled with dancing robots.\n", 
                       "You are destined to become a superhero with an invisible cape.\n", 
                       "Your spirit animal is a rainbow-colored penguin.\n", 
                       "You will discover a secret underground lair filled with treasure.\n", 
                       "You will become a master of the art of teleportation.\n"};

   printf("Welcome to the Automated Fortune Teller!\n");
   printf("Please think of a question and type the letter 'q' to receive your fortune.\n");
   char question[50];
   scanf("%s", question);
   
   if (question[0] == 'q') {
      printf("Your fortune is: %s", fortunes[num]);
   } else {
      printf("Invalid input. Please try again.\n");
   }
   
   return 0;
}