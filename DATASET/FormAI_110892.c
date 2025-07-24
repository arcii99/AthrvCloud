//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: visionary
#include<stdio.h>

int main(){
   int attack_prob, defense_prob;
   int prob;
   
   printf("Welcome to the Alien Invasion Probability Calculator!\n");
   printf("Please enter the probability of alien attack (0-100): ");
   scanf("%d", &attack_prob);
   
   printf("Please enter the probability of human defense (0-100): ");
   scanf("%d", &defense_prob);
   
   if(attack_prob > defense_prob){
       prob = attack_prob - defense_prob;
       printf("The probability of alien invasion is approximately %d%%.\n", prob);
       printf("Watch out for the aliens and stay safe!\n");
   }
   else if(attack_prob < defense_prob){
       prob = defense_prob - attack_prob;
       printf("The probability of alien invasion is approximately %d%%.\n", prob);
       printf("Congratulations! The humans are prepared for the aliens!\n");
   }
   else{
       printf("The probability of alien invasion is 0%%.\n");
       printf("The humans and aliens have reached a peaceful agreement.\n");
   }
   
   return 0;
}