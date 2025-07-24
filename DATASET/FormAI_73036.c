//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: happy
#include <stdio.h>
#include <math.h>

int main() {
  int radius, height;
  float volume, surface_area;

  printf("Let's create a happy geometric shape!\n");
  
  printf("Enter the radius of your shape: ");
  scanf("%d", &radius);
  
  printf("Enter the height of your shape: ");
  scanf("%d", &height);
  
  // Calculate the volume and surface area
  volume = M_PI * pow(radius, 2) * height;
  surface_area = 2 * M_PI * radius * (radius + height);
  
  printf("\nYour happy shape's volume is: %.2f", volume);
  printf("\nYour happy shape's surface area is: %.2f\n", surface_area);

  printf("\nNow let's make your shape even happier!\n");
  
  // Add 5 to the radius and height
  radius += 5;
  height += 5;
  
  // Recalculate the volume and surface area
  volume = M_PI * pow(radius, 2) * height;
  surface_area = 2 * M_PI * radius * (radius + height);

  printf("\nYour happier shape's volume is: %.2f", volume);
  printf("\nYour happier shape's surface area is: %.2f\n", surface_area);

  printf("\nCongrats on creating your happy geometric shape! Have a great day!\n");

  return 0;
}