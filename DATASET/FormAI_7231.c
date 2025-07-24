//FormAI DATASET v1.0 Category: Image Classification system ; Style: lively
#include <stdio.h>

int main() {
  printf("Welcome to the Image Classification System!\n");

  int image_num;
  printf("Enter the number of images you want to classify: ");
  scanf("%d", &image_num);

  int image_size;
  printf("Enter the size of each image: ");
  scanf("%d", &image_size);

  float image_data[image_num][image_size];
  printf("Enter the image data:\n");

  for (int i = 0; i < image_num; i++) {
    printf("Image %d:\n", i+1);
    for (int j = 0; j < image_size; j++) {
      scanf("%f", &image_data[i][j]);
    }
  }

  float weights[image_size];
  printf("Enter the weights:\n");
  for (int i = 0; i < image_size; i++) {
    scanf("%f", &weights[i]);
  }

  printf("Classifying the images...\n");
  for (int i = 0; i < image_num; i++) {
    float result = 0;
    for (int j = 0; j < image_size; j++) {
      result += image_data[i][j] * weights[j];
    }
    if (result > 0) {
      printf("Image %d is classified as Image A\n", i+1);
    } else {
      printf("Image %d is classified as Image B\n", i+1);
    }
  }

  printf("Thank you for using the Image Classification System!\n");

  return 0;
}