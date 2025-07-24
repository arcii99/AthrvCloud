//FormAI DATASET v1.0 Category: Data validation ; Style: introspective
#include <stdio.h>

int main() {
   int age;
   
   printf("Please enter your age: ");
   scanf("%d", &age);
   
   if (age <= 0) {
      printf("Invalid age. Please enter a positive number.\n");
   } else if (age > 130) {
      printf("Invalid age. Please enter a realistic age.\n");
   } else {
      printf("Valid age.\n");
   }

   return 0;
}