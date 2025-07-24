//FormAI DATASET v1.0 Category: Pattern printing ; Style: introspective
#include <stdio.h>

int main() {
  printf("Hello! I am a program that prints a unique C pattern.\n");
  printf("Please enter the height of the pattern (odd number): ");
  int height;
  scanf("%d", &height);
  if(height % 2 != 1) {
    printf("Invalid input. Height must be an odd number.\n");
    return 0;
  }
  printf("\n");
  int midpoint = (height / 2) + 1;
  int num_spaces = midpoint - 1;
  int num_stars = 1;
  
  for(int i = 1; i <= height; i++) {
    for(int j = 1; j <= num_spaces; j++) {  //prints spaces before the stars
      printf(" ");
    }
    for(int k = 1; k <= num_stars; k++) {  //prints the stars
      printf("*");
      if(k == num_stars) {  //checks for midpoint and starts reducing number of stars
        if(i < midpoint) {
          num_spaces -= 1;
          num_stars += 2;
        } else {
          num_spaces += 1;
          num_stars -= 2;
        }
      }
    }
    printf("\n");  //moves to next line for next row
  }
  return 0;
}