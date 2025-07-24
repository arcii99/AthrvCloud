//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Claude Shannon
#include <stdio.h>

int main() {
   float longitude, latitude;
   
   printf("Enter current longitude and latitude: ");
   scanf("%f %f", &longitude, &latitude);
   
   printf("You are currently at longitude %f and latitude %f.\n", longitude, latitude);
   
   // simulate movement
   int choice;
   
   do {
      printf("\nChoose an option:\n1. Move north\n2. Move south\n3. Move east\n4. Move west\n5. Exit\n");
      scanf("%d", &choice);
      
      switch(choice) {
         case 1: // move north
            latitude += 0.001;
            printf("Moved north. Current position is longitude %f and latitude %f.\n", longitude, latitude);
            break;
         case 2: // move south
            latitude -= 0.001;
            printf("Moved south. Current position is longitude %f and latitude %f.\n", longitude, latitude);
            break;
         case 3: // move east
            longitude += 0.001;
            printf("Moved east. Current position is longitude %f and latitude %f.\n", longitude, latitude);
            break;
         case 4: // move west
            longitude -= 0.001;
            printf("Moved west. Current position is longitude %f and latitude %f.\n", longitude, latitude);
            break;
         case 5: // exit
            printf("Goodbye!\n");
            break;
         default: // invalid option
            printf("Invalid option. Please choose again.\n");
            break;
      }
   } while(choice != 5);
   
   return 0;
}