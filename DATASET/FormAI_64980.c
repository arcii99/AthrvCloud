//FormAI DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>

int main() {
   float miles, km, pounds, kg;
   int choice;

   printf("Welcome to my conversion program!\n");

   do {
      printf("\nWhat would you like to convert?\n");
      printf("1. Miles to Kilometers\n");
      printf("2. Kilograms to Pounds\n");
      printf("3. Quit\n");

      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("\nEnter the number of miles: ");
            scanf("%f", &miles);

            km = miles * 1.609344;
            printf("%f miles is equal to %f kilometers\n", miles, km);
            break;

         case 2:
            printf("\nEnter the number of kilograms: ");
            scanf("%f", &kg);

            pounds = kg * 2.20462;
            printf("%f kilograms is equal to %f pounds\n", kg, pounds);
            break;

         case 3:
            printf("\nThank you for using my conversion program!\n");
            break;

         default:
            printf("\nInvalid choice! Please try again.\n");
      }

   } while(choice != 3);

   return 0;
}