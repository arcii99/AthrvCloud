//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>

int main() {

   printf("Welcome to the Color Code Converter! Let's make some colors happen!\n");
   printf("Enter your color code in HEX format (e.g. #FF4500): ");

   char hex[7];
   scanf("%s", hex);

   if(hex[0] != '#') {
      printf("Whoops, that's not a proper hex code! I can't work with that. Try again!\n");
      return -1;
   }

   int r, g, b;
   sscanf(hex+1, "%2x%2x%2x", &r, &g, &b);

   printf("Got it! Your HEX code translates into this color:\n");
   printf("Red: %d\n", r);
   printf("Green: %d\n", g);
   printf("Blue: %d\n", b);

   printf("Would you like to know the RGB values in decimal format too? (y/n): ");
   char choice;
   scanf(" %c", &choice);

   if(choice == 'y' || choice == 'Y') {
      printf("You know what they say, the more the merrier!\n");
      printf("Red: %d\n", r);
      printf("Green: %d\n", g);
      printf("Blue: %d\n", b);
   } else {
      printf("Suit yourself! Have a good day!\n");
   }

   return 0;
}