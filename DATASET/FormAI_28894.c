//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: curious
#include <stdio.h>

int main() {
  int rows, cols, pixelSize;
  
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  
  printf("Enter the number of columns: ");
  scanf("%d", &cols);

  printf("Enter the pixel size (1-5): ");
  scanf("%d", &pixelSize);

  char pixelChar = '0';

  for(int i = 0; i < rows; i++) {
    for(int j = 0; j < cols; j++) {
      int randNum = rand() % 10;
      
      if(randNum < 5) {
        pixelChar = '#';
      } else {
        pixelChar = '0';
      }

      for(int k = 0; k < pixelSize; k++) {
        for(int l = 0; l < pixelSize; l++) {
          printf("%c ", pixelChar);
        }
      }
    }
    printf("\n");
  }
  
  return 0;
}