//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <string.h>

#define ART_WIDTH 80
#define ART_HEIGHT 20

int main() {
  char userInput[101]; // Maximum input size of 100 characters
  char art[ART_HEIGHT][ART_WIDTH + 1]; // +1 for null terminator
  
  printf("Enter some text: ");
  scanf("%[^\n]", userInput);
  
  // Clear art buffer with spaces
  memset(art, ' ', sizeof(art));
  
  // Draw text in the center of the art buffer
  int textLength = strlen(userInput);
  int textX = (ART_WIDTH - textLength) / 2;
  int textY = ART_HEIGHT / 2;
  for(int i = 0; i < textLength; i++) {
    art[textY][textX + i] = userInput[i];
  }
  
  // Draw ASCII art frame around text
  for(int y = 0; y < ART_HEIGHT; y++) {
    for(int x = 0; x < ART_WIDTH; x++) {
      if(y == 0 || y == ART_HEIGHT - 1 || x == 0 || x == ART_WIDTH - 1) {
        art[y][x] = '*'; // Draw border
      }
    }
  }
  
  // Print ASCII art to console
  for(int y = 0; y < ART_HEIGHT; y++) {
    printf("%s\n", art[y]);
  }
  
  return 0;
}