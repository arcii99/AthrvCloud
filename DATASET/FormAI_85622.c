//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
/* A Tragic Fitness Tale - A Fitness Tracker Program in the Style of Romeo and Juliet */

#include<stdio.h>
int main(){
   int calories_in = 0, calories_out = 0, distance = 0; // our variables
   
   printf("Dear diary, today I met my true love, my fitness tracker. \n"); 

   printf("Alas, my love, why doth thou torment me so? Thy demands are high, but I shall comply.\n"); 

   while(1){ // infinite loop
      printf("Enter food calories taken in today:");
      scanf("%d", &calories_in); // user inputs calories consumed

      printf("Enter calories burned during activities:");
      scanf("%d", &calories_out); // user inputs calories burned

      printf("Enter distance covered (in meters):");
      scanf("%d", &distance); // user inputs distance covered

      if(calories_in < 0 || calories_out < 0 || distance < 0){ // user can't input negative numbers
         printf("I cannot input negative values, alas! \n");
         continue; // restart loop
      }

      printf("Oh my fitness tracker, why must you torture me so?");

      if(calories_in > calories_out){ // if user consumes more calories than they burn
         printf("My heart doth ache, my calories in exceed my calories out. \n");
      }
      else{ // if user burns more calories than they consume
         printf("My love, my calories out exceed my calories in. \n");
      }

      if(distance >= 5000){ // if user covers more than 5000 meters
         printf("My love, I have traversed the earth just to satisfy thy whims. \n"); 
      }
      
      printf("But alas, my love, I must say goodnight. Forgive me for my failures, and know that I shall try again tomorrow. \n"); 
      break; // break out of the loop
   }

   printf("Farewell, oh my fitness tracker. Let us meet again tomorrow. \n"); 

   return 0;
}