//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  float lat, lon, dest_lat, dest_lon, dist, bearing;
  printf("Enter your current latitude: ");
  scanf("%f", &lat);
  printf("Enter your current longitude: ");
  scanf("%f", &lon);
  printf("Enter your destination latitude: ");
  scanf("%f", &dest_lat);
  printf("Enter your destination longitude: ");
  scanf("%f", &dest_lon);

  // calculate distance to destination
  dist = 3963.0 * acos(sin(lat)*sin(dest_lat) + cos(lat)*cos(dest_lat)*cos(dest_lon-lon));
  printf("Distance to destination: %.2f miles\n", dist);

  // calculate bearing to destination
  bearing = atan2(sin(dest_lon-lon)*cos(dest_lat), cos(lat)*sin(dest_lat)-sin(lat)*cos(dest_lat)*cos(dest_lon-lon));
  bearing = bearing*180/3.14159265; // convert to degrees
  if (bearing < 0)
    bearing += 360;
  printf("Bearing to destination: %.2f degrees\n", bearing);

  // simulate navigation
  while (dist > 0) {
    printf("Current location: %.4f, %.4f\n", lat, lon);
    printf("Distance to destination: %.2f miles\n", dist);
    printf("Bearing to destination: %.2f degrees\n", bearing);
    printf("Press ENTER to move forward 1 mile\n");
    getchar();

    // move forward 1 mile
    lat = lat + (1/dist)*(dest_lat-lat);
    lon = lon + (1/dist)*(dest_lon-lon);
    dist = 3963.0 * acos(sin(lat)*sin(dest_lat) + cos(lat)*cos(dest_lat)*cos(dest_lon-lon));
    bearing = atan2(sin(dest_lon-lon)*cos(dest_lat), cos(lat)*sin(dest_lat)-sin(lat)*cos(dest_lat)*cos(dest_lon-lon));
    bearing = bearing*180/3.14159265; // convert to degrees
    if (bearing < 0)
      bearing += 360;
  }

  // arrived at destination
  printf("You have arrived at your destination!\n");
  printf("Final location: %.4f, %.4f\n", lat, lon);

  return 0;
}