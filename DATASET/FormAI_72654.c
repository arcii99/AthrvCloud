//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed random number generator

  // Create array of GPS coordinates
  float coords[10][2] = {{33.9872, -118.4144},
                         {34.0522, -118.2437},
                         {34.1083, -117.2898},
                         {34.1425, -118.2551},
                         {34.4358, -119.8276},
                         {33.6839, -117.7947},
                         {33.8121, -117.9190},
                         {33.8919, -118.3024},
                         {34.0550, -117.7499},
                         {34.4208, -119.6982}};

  // Generate random starting and ending points within array
  int start = rand() % 10;
  int end = rand() % 10;
  while (end == start) { // Ensure end point is different from start point
    end = rand() % 10;
  }

  // Print starting and ending coordinates
  printf("Starting location: (%.4f, %.4f)\n", coords[start][0], coords[start][1]);
  printf("Ending location: (%.4f, %.4f)\n", coords[end][0], coords[end][1]);
  
  // Calculate distance between start and end points
  float lat1 = coords[start][0];
  float lon1 = coords[start][1];
  float lat2 = coords[end][0];
  float lon2 = coords[end][1];
  float R = 6371; // Earth's radius in km
  float dLat = (lat2 - lat1) * 3.14159 / 180;
  float dLon = (lon2 - lon1) * 3.14159 / 180;
  float a = sin(dLat/2) * sin(dLat/2) + cos(lat1 * 3.14159 / 180) * cos(lat2 * 3.14159 / 180) * sin(dLon/2) * sin(dLon/2);
  float c = 2 * atan2(sqrt(a), sqrt(1-a));
  float dist = R * c;
  
  // Print distance between start and end points
  printf("Distance between starting and ending points: %.2f km\n", dist);

  return 0;
}