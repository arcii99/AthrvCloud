//FormAI DATASET v1.0 Category: Smart home light control ; Style: romantic
#include <stdio.h>

//Declare variables for Smart Home Light Control
int time;
int light_int;

int main() {
   printf("Welcome to Smart Home Light Control!\n");

   printf("Enter the current time (in 24 hour format without colon):\n");
   scanf("%d", &time);

   //Control the light intensity based on time of day
   if (time >= 600 && time <= 800) {
      light_int = 80; //80% brightness for morning hours
   } else if (time >= 1800 && time <= 2200) {
      light_int = 70; //70% brightness for evening hours
   } else {
      light_int = 20; //20% brightness for night hours
   }

   //Display the light intensity
   printf("The Smart Home Light Control has set the light intensity to %d percent.", light_int);

   return 0;
}