//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Romeo and Juliet
/* Romeo and Juliet Personal Finance Planner */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   float income, expenses, savings;
   char name[20], occupation[20], choice[20];
   
   printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
   printf("Enter thy name: ");
   scanf("%s", name);
   printf("Ah, %s, a name I know too well!\n", name);
   printf("What doth thou do for a living?\n");
   scanf("%s", occupation);
   printf("A %s by any other name would still smell as sweet.\n", occupation);
   printf("Dost thou have an income to report?\n");
   scanf("%f", &income);
   printf("And what of thy expenses? Pray tell, how much dost thou spend?\n");
   scanf("%f", &expenses);
   
   savings = income - expenses;
   
   printf("Oh, %s, thou art a true finance planner!\n", name);
   printf("With an income of %.2f and expenses of %.2f, thy savings are %.2f.\n", income, expenses, savings);
   
   printf("Wouldst thou like to calculate thy savings for another month? Yea or nay?\n");
   scanf("%s", choice);
   
   while (strcmp(choice, "Yea") == 0) {
      printf("What be thy income for this month?\n");
      scanf("%f", &income);
      printf("And what be thy expenses? Pray tell, how much dost thou spend?\n");
      scanf("%f", &expenses);
      
      savings += income - expenses;
      
      printf("Thou hast saved an additional %.2f this month!\n", income - expenses);
      printf("Dost thou wish to calculate thy savings for yet another month? Yea or nay?\n");
      scanf("%s", choice);
   }
   
   printf("Farewell, %s, may thy savings grow as true as thy love for me!\n", name);
   
   return 0;
}