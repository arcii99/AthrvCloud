//FormAI DATASET v1.0 Category: Funny ; Style: funny
#include <stdio.h>

int main() {
  // Initializing variables
  int beer = 99;
  char* suffix = "bottles";
  
  // The main loop
  while (beer > 0) {
    // Output the current count of bottles
    printf("%d %s of beer on the wall,\n", beer, suffix);
    printf("%d %s of beer!\n", beer, suffix);
    printf("You take one down, \nand pass it around,\n");
    
    // Decrement the beer counter
    beer--;
    
    // Determine the suffix for the next bottle count
    if (beer == 1) {
      suffix = "bottle";
    } else if (beer == 0) {
      suffix = "no more bottles";
    }
    
    // Output the next bottle count
    printf("%d %s of beer on the wall!\n\n", beer, suffix);
    
    // Add a little delay for dramatic effect
    // (Note: This is not a reliable way to create delays!)
    int i, j;
    for (i = 0; i < 10000000; i++) {
      j++;
    }
  }
  
  // Output the final lines of the song
  printf("No more bottles of beer on the wall,\n");
  printf("no more bottles of beer!\n");
  printf("Go to the store, and buy some more,\n");
  printf("99 bottles of beer on the wall!\n");
  
  return 0;
}