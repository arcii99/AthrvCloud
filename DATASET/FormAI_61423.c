//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include<stdio.h>
#include<ctype.h>
#include<math.h>

void printAscii(char);

int main() {
  float R[3][3]={{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  float transformationMatrix[3][3]={{0.299, 0.587, 0.114}, {-0.169, -0.331, 0.5}, {0.5, -0.419, -0.081}};
  FILE *fp;
  char grayScale[70]={' ', '.', '\'', ':', '-', '*', '=', '@', '%', '#'};
  char pixelValue;
  int i, j;
  fp = fopen("image.txt", "r");
  if(fp == NULL) perror("Error: ");
  else {
    for (i = 0; i < 70; i++) {
      printf("%c", grayScale[i]);
      printf("%c", grayScale[i]);
    }
    printf("\n");
    while((pixelValue = getc(fp)) != EOF) {
      if(isdigit(pixelValue)) {
        ungetc(pixelValue, fp);
        double RGB[3];
        for(i=0; i<3; i++) {
          for(j=0; j<3; j++) {
            unsigned char p = getc(fp);
            RGB[i]+=transformationMatrix[j][i]*p;
          }
          RGB[i] = round(RGB[i]);
          char asciiChar = grayScale[(int)RGB[i]/25];
          printAscii(asciiChar);          
        }
      }
      else printf("\n");
    }
  fclose(fp);
  }
}

void printAscii(char character) { 
  printf("%c%c", character, character);
}