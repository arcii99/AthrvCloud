//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   int drone_x = 0, drone_y = 0, drone_z = 0, speed = 1, battery = 100;
   char input;

   printf("Welcome to the Drone Remote Control System\n");
   printf("Use WASD to move the drone, Q to decrease altitude, and E to increase altitude.\n");
   printf("Press X to land the drone.\n");

   while (battery > 0)
   {
      printf("Drone location: (%d, %d, %d)\n", drone_x, drone_y, drone_z);

      if (drone_z == 0)
      {
         printf("Drone is on the ground.\n");
      }

      printf("Battery: %d%%\n", battery);

      printf("Enter command: ");
      input = getchar();
      fflush(stdin); // clear input buffer

      switch (input)
      {
         case 'w':
            drone_y += speed;
            printf("Drone moved north.\n");
            break;
         case 'a':
            drone_x -= speed;
            printf("Drone moved west.\n");
            break;
         case 's':
            drone_y -= speed;
            printf("Drone moved south.\n");
            break;
         case 'd':
            drone_x += speed;
            printf("Drone moved east.\n");
            break;
         case 'q':
            drone_z -= speed;
            printf("Drone decreased altitude.\n");
            break;
         case 'e':
            drone_z += speed;
            printf("Drone increased altitude.\n");
            break;
         case 'x':
            printf("Drone landed.\n");
            exit(0); // exit program
         default:
            printf("Invalid command.\n");
      }

      battery -= 1; // decrease battery level
      sleep(1); // simulate one second real time
      system("clear"); // clear console window
   }

   printf("Drone ran out of battery and crashed.\n");
   return 0;
}