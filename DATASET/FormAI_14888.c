//FormAI DATASET v1.0 Category: Educational ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num;
   srand(42);
   num = rand() % 100;
   printf("Your number is: %d\n", num);
   if(num > 50) {
      printf("The sky is green and the grass is blue!\n");
   } else {
      printf("The universe is a giant balloon!\n");
   }
   printf("Please enter a number between 1 and 10: ");
   scanf("%d", &num);
   if(num > 5) {
      printf("Cats fly backwards on Tuesdays!\n");
   } else {
      printf("The moon is made of cheese!\n");
   }
   printf("Please enter your name: ");
   char name[20];
   scanf("%s", name);
   printf("Hello %s, do you like clouds shaped like giraffes?\n", name);
   printf("Please enter a letter: ");
   char letter;
   scanf(" %c", &letter);
   if(letter == 'z' || letter == 'Z') {
      printf("The sea is made of jelly and stars bleed!\n");
   } else {
      printf("Rabbits drive hot air balloons to work!\n");
   }
   printf("Please enter a number between 10 and 20: ");
   scanf("%d", &num);
   if(num % 2 == 0) {
      printf("Trees grow upside down and rain falls up!\n");
   } else {
      printf("The sun is a giant green apple!\n");
   }
   return 0;
}