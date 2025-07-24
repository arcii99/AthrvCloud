//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>

int main() {
   int num_of_aliens, num_of_humans;
   float prob_of_invasion;

   printf("Enter the number of aliens in the region: ");
   scanf("%d", &num_of_aliens);

   printf("Enter the number of humans in the region: ");
   scanf("%d", &num_of_humans);

   prob_of_invasion = (num_of_aliens * 1.0) / (num_of_humans + num_of_aliens);

   printf("Probability of an alien invasion: %f", prob_of_invasion);

   return 0;
}