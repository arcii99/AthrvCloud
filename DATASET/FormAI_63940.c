//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Romeo and Juliet
// Setting the stage with a romantic feeling
#include <stdio.h>
#include <stdlib.h>

int main(){
   int numOfAliens;
   float invasionProb;
   char response;

   printf("Oh, fair citizens of earth,\n");
   printf("Doth thou crave certainty of thy fate\n");
   printf("In the face of a potential rogue alien race?\n");
   printf("(Aye, this be a program to calculate) Yea or nay?\n");
   scanf("%c", &response);

   if (response == 'Y' || response == 'y'){
      printf("Harken to the questions presented here\n");
      printf("Forsooth, we shall reveal the answer you seek so dear\n");

      printf("How many aliens are seen in the sky?\n");
      scanf("%d", &numOfAliens);

      if(numOfAliens <= 0){
         printf("When there be nothing seen, there be nothing to fear\n");
         printf("For when there are no aliens, there's naught to calculate here!\n");
      }
      else{
         invasionProb = (float)numOfAliens/1000000;
         printf("The probability of an invasion is %f percent\n", invasionProb);
         printf("Whether to surrender or fight, that be thine own consent\n");
         printf("May you find resolution, with this answer so recent!\n");
      }
   }
   else{
      printf("Stay calm and carry on, be cool and thee shall not starve\n");
      printf("For when there be no fear, there be no need for this program brave.\n");
   }
   return 0;
}