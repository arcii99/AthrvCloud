//FormAI DATASET v1.0 Category: Data validation ; Style: expert-level
#include <stdio.h>
#include <ctype.h>

int main() {
   int age;
   char gender;
   float height;

   printf("Enter your age: ");
   scanf("%d", &age);
   
   if(age < 0 || age > 150) { // age should be a positive value within the logical limits
      printf("Invalid input: Enter a valid age \n");
   }
   else {
      printf("Enter your gender (M/F): ");
      scanf(" %c", &gender);
      gender = toupper(gender);
      
      if(gender != 'M' && gender != 'F') { // gender should be either M or F
         printf("Invalid input: Enter a valid gender \n");
      }
      else {
         printf("Enter your height in meters: ");
         scanf("%f", &height);
         
         if(height < 0.0 || height > 3.0) { // height should be a positive value within the logical limits
            printf("Invalid input: Enter a valid height \n");
         }
         else {
            printf("---Valid entry--- \n");
         }
      }
   }
   return 0;
}