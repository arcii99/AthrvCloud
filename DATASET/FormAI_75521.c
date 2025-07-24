//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: intelligent
#include <stdio.h>

int main() {
   char ch;
   printf("Enter 1 for up, 2 for down, 3 for left and 4 for right: ");
   scanf("%c",&ch);

   switch(ch) {
      case '1' :
         printf("Drone moves up\n" );
         break;
      case '2' :
         printf("Drone moves down\n" );
         break;
      case '3' :
         printf("Drone moves left\n" );
         break;
      case '4' :
         printf("Drone moves right\n" );
         break;
      default :
         printf("Invalid command\n" );
   }   
   return 0;
}