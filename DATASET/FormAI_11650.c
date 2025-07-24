//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: retro
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
   int count = 0, index = 0;
   char userInput[50];

   printf("Welcome to Retro IDS!\n");

   while(count < 5) {
      printf("\nEnter a string: ");
      scanf("%s", userInput);
      
      for(index = 0; index < strlen(userInput); index++) {
         if(userInput[index] == '(') {
            printf("\nINTRUSION ALERT! '(' detected!\n");
            count++;
            break;
         }
      }
   }

   printf("\nINTRUSION LEVEL: HIGH\n");
   printf("SYSTEM LOCKOUT!\n");
   
   return 0;
}