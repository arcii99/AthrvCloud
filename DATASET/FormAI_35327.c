//FormAI DATASET v1.0 Category: Data validation ; Style: imaginative
#include <stdio.h>

int main() {
   int age;

   printf("What is your age?\n");
   scanf("%d", &age);

   if(age < 18) {
     printf("Sorry, you are too young to vote\n");
     return 0;
   } 

   printf("Please enter your social security number:\n");
   char ssn[10];
   scanf("%s",ssn);

   for(int i=0; i<9; i++) {
      if(ssn[i]<'0' || ssn[i]>'9'){
         printf("Invalid entry, please make sure you only entered digits\n");
         return 0;
      }
   }

   printf("Thank you for submitting your information\n");
   return 0;
}