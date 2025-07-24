//FormAI DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char name[50], age[4], hackername[50];
   int length;

   printf("Welcome to the Cyberpunk world, please enter your name: ");
   fgets(name, 50, stdin);
   name[strcspn(name, "\n")] = 0;

   printf("\n%s, enter your hacker name: ", name);
   fgets(hackername, 50, stdin);
   hackername[strcspn(hackername, "\n")] = 0;

   printf("\nPlease enter your age: ");
   fgets(age, 4, stdin);

   length = strlen(hackername);

   printf("\n%s, your hacker name has %d characters.\n", name, length);

   if (atoi(age) < 18) {
      printf("\nYou are not old enough to hack.\n");
      return 0;
   }
   
   printf("\nWelcome to the Cyberworld, %s. You are now ready to hack the system.\n", hackername);
   return 0;
}