//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   char name[20];
   printf("Welcome to the surreal fortune teller program!\n");
   printf("What's your name?\n");
   scanf("%s", name);

   time_t t;
   srand((unsigned)time(&t));
   int fortune = rand() % 10;
   
   printf("\n%s, your fortune for today is:\n\n", name);
   
   switch(fortune)
   {
      case 0:
         printf("The cat will lead you to the cheese.\n");
         break;
      case 1:
         printf("Your dreams will be haunted by talking trees.\n");
         break;
      case 2:
         printf("The moon will turn green and carry you to a magical land.\n");
         break;
      case 3:
         printf("You will find yourself shrinking in size until you are the size of an ant.\n");
         break;
      case 4:
         printf("Your reflection will come to life and steal your identity.\n");
         break;
      case 5:
         printf("You will become a bird and fly away to a beautiful island.\n");
         break;
      case 6:
         printf("A giant rabbit will appear before you and give you a special gift.\n");
         break;
      case 7:
         printf("You will discover a hidden door in your room that leads to a secret chamber.\n");
         break;
      case 8:
         printf("You will meet a group of enchanted creatures who will help you on your journey.\n");
         break;
      case 9:
         printf("You will find yourself lost in a maze that only you can escape.\n");
         break;
      default:
         printf("Oops! Something went wrong.\n");
         break;
   }
   
   return 0;
}