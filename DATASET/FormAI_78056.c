//FormAI DATASET v1.0 Category: Image compression ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Welcome to my Image Compression Program!\n");
  printf("Please enter the file name of the image you wish to compress: ");

  char file_name[50];
  scanf("%s", file_name);

  printf("Compressing %s...\n", file_name);
  
  // Here's the funny part! We'll compress the image by randomly deleting pixels!
  int original_size = rand() % 10000000 + 1000000; // Choose a random file size between 1MB and 10MB
  int compressed_size = rand() % original_size; // Choose a random compressed size that will always be smaller

  printf("Original file size: %d bytes\n", original_size);
  printf("Compressed file size: %d bytes\n", compressed_size);
  printf("Wow, we just magically made your image smaller! Isn't technology amazing?\n");

  printf("Thank you for using my Image Compression Program. Goodbye!\n");

  return 0;
}