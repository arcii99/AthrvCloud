//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random number */
int generate_lucky_number() {
   srand(time(0));
   return rand() % 100 + 1; //generating a lucky number between 1-100
}

/* Function to predict the fortune */
void predict_fortune(int lucky_num) {
   switch(lucky_num) { //using the lucky number to predict fortune
      case 1:
         printf("You will soon meet your true love.\n");
         break;
      case 2:
         printf("You will receive a promotion at work.\n");
         break;
      case 3:
         printf("You will win the lottery jackpot.\n");
         break;
      case 4:
         printf("You will travel to a far-off land.\n");
         break;
      case 5:
         printf("You will solve a long-standing problem.\n");
         break;
      case 6:
         printf("You will become very wealthy.\n");
         break;
      case 7:
         printf("You will find inner peace.\n");
         break;
      case 8:
         printf("Your dreams will come true.\n");
         break;
      case 9:
         printf("You will make a new friend.\n");
         break;
      case 10:
         printf("You will overcome a great challenge.\n");
         break;
      default:
         printf("Your fortune is unclear, try again later.\n");
   }
}

int main() {
   int lucky_num = generate_lucky_number(); //generating a lucky number
   
   printf("Welcome to the Automated Fortune Teller!\n");
   printf("Please think of a question and press enter to reveal your fortune...\n");
   getchar(); //waiting for user to press enter
   printf("\n");
   
   predict_fortune(lucky_num); //predicting the fortune based on the lucky number
   
   return 0;
}