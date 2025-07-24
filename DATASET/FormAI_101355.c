//FormAI DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>

int main() {
  char image[10][10] = {
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
    {'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}
  };
  
  printf("Image Editor Program\n");
  printf("Original Image:\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", image[i][j]);
    }
    printf("\n");
  }
  
  // Task 1: Flip the image vertically
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 10; j++) {
      char temp = image[i][j];
      image[i][j] = image[9-i][j];
      image[9-i][j] = temp;
    }
  }
  printf("\nTask 1: Flipped Image Vertically:\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", image[i][j]);
    }
    printf("\n");
  }
  
  // Task 2: Flip the image horizontally
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 5; j++) {
      char temp = image[i][j];
      image[i][j] = image[i][9-j];
      image[i][9-j] = temp;
    }
  }
  printf("\nTask 2: Flipped Image Horizontally:\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", image[i][j]);
    }
    printf("\n");
  }
  
  // Task 3: Invert the colors of the image
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (image[i][j] == 'X') {
        image[i][j] = 'O';
      } else {
        image[i][j] = 'X';
      }
    }
  }
  printf("\nTask 3: Inverted Colors Image:\n");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", image[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}