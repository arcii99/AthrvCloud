//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *asciiArray[] = {"@", "#", "S", "%", "?", "*", "+", ";", ":", ",", "."};

int main(){
  char image[100][100];
  int numCols, numRows, i, j, averageIntensity, index;

  //Read image from file
  FILE *fp = fopen("image.ppm", "r");
  fscanf(fp, "P3\n");
  fscanf(fp, "%d %d\n", &numCols, &numRows);
  fscanf(fp, "255\n");

  //Read image pixel matrix
  for(i=0; i<numRows; i++){
    for(j=0; j<numCols; j++){
      fscanf(fp, "%d", &image[i][j]);
    }
  }
  fclose(fp);

  //Convert image to ASCII art
  for(i=0; i<numRows; i++){
    for(j=0; j<numCols; j++){
      averageIntensity = (image[i][j]+image[i][j+1]+image[i+1][j]+image[i+1][j+1])/4;
      index = (int)(averageIntensity/25);
      printf("%s", asciiArray[index]);
    }
    printf("\n");
  }

  return 0;
}