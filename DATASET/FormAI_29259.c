//FormAI DATASET v1.0 Category: Firewall ; Style: mind-bending
#include <stdio.h>

int main() {
   int input;
   printf("Enter the access level (1-10): ");
   scanf("%d", &input);

   switch(input) {
      case 10:
         printf("Access granted. Welcome, Admin.\n");
         break;
      case 9:
         printf("Access granted. Welcome, Supervisor.\n");
         break;
      case 8:
         printf("Access granted. Welcome, Manager.\n");
         break;
      case 7:
         printf("Access granted. Welcome, Employee.\n");
         break;
      case 6:
         printf("Access granted. Welcome, Guest.\n");
         break;
      case 5:
      case 4:
      case 3:
      case 2:
      case 1:
         printf("Access denied. Your access level is too low.\n");
         break;
      default:
         printf("Invalid input. Please enter a number between 1-10.\n");
         break;
   }

   return 0;
}