//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// function to convert degree to radians
double deg2rad(double deg) {
  return deg * (M_PI/180);
}

// function to calculate the distance between two points of longitude and latitude
double distance(double lat1, double lon1, double lat2, double lon2, char unit) {
  double theta, dist;
  theta = lon1 - lon2;
  dist = sin(deg2rad(lat1)) * sin(deg2rad(lat2)) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * cos(deg2rad(theta));
  dist = acos(dist);
  dist = dist * 180/M_PI;
  dist = dist * 60 * 1.1515;
  if (unit == 'K') {
    dist = dist * 1.609344;
  } else if (unit == 'N') {
    dist = dist * 0.8684;
  }
  return dist;
}

int main() {
  double lat1, lat2, lon1, lon2, distanceInKM;
  char unit = 'K';

  printf("Enter the latitude of starting point: ");
  scanf("%lf", &lat1);
  printf("Enter the longitude of starting point: ");
  scanf("%lf", &lon1);
  printf("Enter the latitude of destination point: ");
  scanf("%lf", &lat2);
  printf("Enter the longitude of destination point: ");
  scanf("%lf", &lon2);

  distanceInKM = distance(lat1, lon1, lat2, lon2, unit);

  printf("Distance between the two points is: %.2lf km", distanceInKM);
  return 0;
}