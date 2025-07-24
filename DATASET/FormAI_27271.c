//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>

int main() {
  float currentLat, currentLong, destinationLat, destinationLong, distance;
  char choice;
  
  printf("GPS Navigation Simulation\n");
  printf("Enter your current latitude: ");
  scanf("%f", &currentLat);
  printf("Enter your current longitude: ");
  scanf("%f", &currentLong);
  printf("Enter your destination latitude: ");
  scanf("%f", &destinationLat);
  printf("Enter your destination longitude: ");
  scanf("%f", &destinationLong);
  
  distance = sqrt(pow(destinationLat-currentLat,2) + pow(destinationLong-currentLong,2));
  printf("Your destination is %.2f miles away.\n", distance);
  
  while (distance > 0.1) { // Keep prompting until within 0.1 miles of destination
    printf("Choose your next move:\n");
    printf("N - Move North\n");
    printf("S - Move South\n");
    printf("E - Move East\n");
    printf("W - Move West\n");
    printf("Q - Quit\n");
    scanf(" %c", &choice);
    switch(choice) {
      case 'N':
        currentLat += 0.01;
        break;
      case 'S':
        currentLat -= 0.01;
        break;
      case 'E':
        currentLong += 0.01;
        break;
      case 'W':
        currentLong -= 0.01;
        break;
      case 'Q':
        printf("Exiting...\n");
        return 0;
      default:
        printf("Invalid choice\n");
        break;
    }
    distance = sqrt(pow(destinationLat-currentLat,2) + pow(destinationLong-currentLong,2));
    printf("Your destination is now %.2f miles away.\n", distance);
  }
  
  printf("You have reached your destination!");
  return 0;
}