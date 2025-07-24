//FormAI DATASET v1.0 Category: Image Classification system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to classify image as cat or dog
void image_classifier(char* image_path) {
  //some code to read image file and extract features
  //assuming we have extracted the following features
  
  int num_pixels = 1000;  //number of pixels in image
  float avg_pixel_val = 0.5;  //average pixel value in image
  int num_edges = 20;  //number of edges in image
  float circularity = 0.7; //circularity of image object
  
  //using some predefined thresholds for classification
  if(num_pixels > 500 && avg_pixel_val > 0.4 && num_edges < 30 && circularity > 0.6) {
    printf("Image is of a cat\n");
  } else {
    printf("Image is of a dog\n");
  }
}

int main() {
  //taking image path as input
  char image_path[100];
  printf("Enter image path: ");
  scanf("%s", image_path);
  
  //calling image classifier function
  image_classifier(image_path);
  
  return 0;
}