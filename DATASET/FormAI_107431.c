//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>

#define MAX_PLANETS 100 // maximum number of planets 
#define MAX_HABZONES 10 // maximum number of habitable zones per planet

struct Planet {
   int num_habzones;
   float habzone_params[MAX_HABZONES][3]; // array to store parameters of habitable zones
};

int main() {
   int num_planets;
   struct Planet planets[MAX_PLANETS];
   
   printf("Enter the number of known planets: ");
   scanf("%d", &num_planets); // input the number of known planets
   
   for (int i = 0; i < num_planets; i++) {
      printf("Enter the number of habitable zones for planet %d: ", i+1);
      scanf("%d", &planets[i].num_habzones); // input the number of habitable zones for planet i
      
      for (int j = 0; j < planets[i].num_habzones; j++) {
         printf("Enter the parameters of habitable zone %d (min_distance max_distance probability): ", j+1);
         scanf("%f %f %f", &planets[i].habzone_params[j][0], &planets[i].habzone_params[j][1], &planets[i].habzone_params[j][2]); // input the parameters of habitable zone j
      }
   }
   // rest of the program goes here
   return 0;
}