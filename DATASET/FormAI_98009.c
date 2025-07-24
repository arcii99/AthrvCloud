//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Function to calculate distance between two points using latitude and longitude
double distance(double lat1, double lon1, double lat2, double lon2) {
  double radlat1 = PI * lat1 / 180;
  double radlat2 = PI * lat2 / 180;
  double theta = lon1 - lon2;
  double radtheta = PI * theta / 180;
  double dist = sin(radlat1) * sin(radlat2) + cos(radlat1) * cos(radlat2) * cos(radtheta);
  dist = acos(dist);
  dist = dist * 180 / PI;
  dist = dist * 60 * 1.1515;
  return dist;
}

int main() {
  // Coordinates of destination
  double dest_lat = 34.0522;
  double dest_lon = -118.2437;

  // Coordinates of user's current location
  double curr_lat = 33.6846;
  double curr_lon = -117.8265;

  // Calculate distance to destination
  double dist_to_dest = distance(curr_lat, curr_lon, dest_lat, dest_lon);

  // Print distance to destination
  printf("You are currently %.2f miles away from your destination.\n", dist_to_dest);

  // Generate directions to destination
  if (dist_to_dest < 1) {
    printf("You have reached your destination.\n");
  } else {
    double bearing = atan2(sin(dest_lon - curr_lon) * cos(dest_lat), cos(curr_lat) * sin(dest_lat) - sin(curr_lat) * cos(dest_lat) * cos(dest_lon - curr_lon));
    bearing = bearing * 180 / PI;

    // Adjust bearing to be in the range of 0-360
    if (bearing < 0) {
      bearing = bearing + 360;
    }

    printf("The bearing to your destination is %.2f degrees.\n", bearing);

    // Determine direction to turn
    if (bearing >= 337.5 || bearing < 22.5) {
      printf("Turn right.\n");
    } else if (bearing >= 22.5 && bearing < 67.5) {
      printf("Turn right and slightly north.\n");
    } else if (bearing >= 67.5 && bearing < 112.5) {
      printf("Go north.\n");
    } else if (bearing >= 112.5 && bearing < 157.5) {
      printf("Turn left and slightly north.\n");
    } else if (bearing >= 157.5 && bearing < 202.5) {
      printf("Turn left.\n");
    } else if (bearing >= 202.5 && bearing < 247.5) {
      printf("Turn left and slightly south.\n");
    } else if (bearing >= 247.5 && bearing < 292.5) {
      printf("Go south.\n");
    } else if (bearing >= 292.5 && bearing < 337.5) {
      printf("Turn right and slightly south.\n");
    }
  }

  return 0;
}