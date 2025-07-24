//FormAI DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>

int main() {
   int colorCode;
   printf("Enter your color code: ");
   scanf("%d", &colorCode);
   switch(colorCode) {
      case 1 :
         printf("You have entered Black color");
         break;
      case 2 :
         printf("You have entered Red color");
         break;
      case 3 :
         printf("You have entered Green color");
         break;
      case 4 :
         printf("You have entered Yellow color");
         break;
      case 5 :
         printf("You have entered Blue color");
         break;
      case 6 :
         printf("You have entered Magenta color");
         break;
      case 7 :
         printf("You have entered Cyan color");
         break;
      case 8 :
         printf("You have entered White color");
         break;
      default :
         printf("Invalid color code");
   }
   return 0;
}