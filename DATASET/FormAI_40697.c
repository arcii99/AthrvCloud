//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: cheerful
#include <stdio.h>

int main() {
  // display welcome message
  printf("Welcome to the Happy Navigation System!\n");

  // ask the user for their current location
  printf("Please enter your current latitude: ");
  double currentLat;
  scanf("%lf", &currentLat);

  printf("Please enter your current longitude: ");
  double currentLong;
  scanf("%lf", &currentLong);

  // ask the user for their destination
  printf("Please enter your destination latitude: ");
  double destLat;
  scanf("%lf", &destLat);

  printf("Please enter your destination longitude: ");
  double destLong;
  scanf("%lf", &destLong);

  // calculate the distance between the two points
  double distance = sqrt(pow(currentLat-destLat, 2.0) + pow(currentLong-destLong, 2.0)) * 100;
  printf("You are %.2f meters away from your destination!\n", distance);

  // give the user directions to their destination
  int direction = rand() % 4;
  switch (direction) {
    case 0:
      printf("Go straight ahead for %.2f meters, then turn left!\n", distance * 0.7);
      break;
    case 1:
      printf("Go straight ahead for %.2f meters, then turn right!\n", distance * 0.6);
      break;
    case 2:
      printf("Go straight ahead for %.2f meters, then turn left and go straight for %.2f meters, then turn right!\n", distance * 0.4, distance * 0.2);
      break;
    case 3:
      printf("Go straight ahead for %.2f meters, then turn right and go straight for %.2f meters, then turn left!\n", distance * 0.5, distance * 0.3);
      break;
  }

  // congratulate the user on reaching their destination
  printf("Congratulations on reaching your destination! We hope you had a happy journey with the Happy Navigation System!\n");

  return 0;
}