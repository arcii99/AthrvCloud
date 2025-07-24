//FormAI DATASET v1.0 Category: Image compression ; Style: curious
#include<stdio.h>
#include<stdlib.h>

typedef struct pixel{
  int r, g, b;
}Pixel;

int main(){

  //declare variables
  Pixel* image;
  int width, height;
  FILE* infile = fopen("input.txt", "r");
  FILE* outfile = fopen("output.txt", "w");

  //read in image dimensions
  fscanf(infile, "%d %d", &width, &height);

  //allocate memory for image
  image = (Pixel*)malloc(width * height * sizeof(Pixel));

  //read in image pixel values
  int i;
  for(i = 0; i < width * height; i++){
    fscanf(infile, "%d %d %d", &image[i].r, &image[i].g, &image[i].b);
  }

  //compress image by averaging RGB values
  for(i = 0; i < width * height; i++){
    image[i].r = (image[i].r + image[i].g + image[i].b) / 3;
    image[i].g = image[i].r;
    image[i].b = image[i].r;
  }

  //write compressed image to output file
  fprintf(outfile, "%d %d\n", width, height);
  for(i = 0; i < width * height; i++){
    fprintf(outfile, "%d %d %d\n", image[i].r, image[i].g, image[i].b);
  }

  //free memory and close files
  free(image);
  fclose(infile);
  fclose(outfile);

  return 0;
}