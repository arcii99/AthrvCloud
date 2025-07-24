//FormAI DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {

  printf("Hello and thank you for choosing our data mining program!\n");
  printf("In this program, we will analyze a dataset of animal footprints to determine the most common animals in the area.\n");
  
  int num_footprints;
  printf("Please enter the number of footprints in the dataset: ");
  scanf("%d", &num_footprints);
  
  int *footprint_array = (int*)malloc(num_footprints * sizeof(int));
  
  printf("Please enter the footprints in the dataset, one at a time.\n");
  for (int i = 0; i < num_footprints; i++) {
    scanf("%d", &footprint_array[i]);
  }
  
  // Use counting sort algorithm to find most common animal
  int max_footprint = 0;
  int most_common_animal = 0;
  for (int i = 0; i < num_footprints; i++) {
    int count = 0;
    for (int j = 0; j < num_footprints; j++) {
      if (footprint_array[j] == footprint_array[i]) {
        count++;
      }
    }
    if (count > max_footprint) {
      max_footprint = count;
      most_common_animal = footprint_array[i];
    }
  }
  
  printf("The most common animal in the dataset is animal %d, with a total of %d footprints.\n", most_common_animal, max_footprint);
  
  free(footprint_array);
  
  printf("Thank you for using our program! We hope you found it useful.\n");
  
  return 0;
}