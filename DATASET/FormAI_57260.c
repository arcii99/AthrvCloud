//FormAI DATASET v1.0 Category: System boot optimizer ; Style: puzzling
#include <stdio.h>

int main() {
  // Declare variables
  int num_1, num_2, num_3;
  
  // Prompt user for input
  printf("Enter three numbers: ");
  scanf("%d%d%d", &num_1, &num_2, &num_3);
  
  // Compare numbers and rearrange them in descending order
  if (num_1 < num_2) {
    int temp = num_1;
    num_1 = num_2;
    num_2 = temp;
  }
  
  if (num_2 < num_3) {
    int temp = num_2;
    num_2 = num_3;
    num_3 = temp;
    
    if (num_1 < num_2) {
      int temp = num_1;
      num_1 = num_2;
      num_2 = temp;
    }
  }
  
  // Print numbers in descending order
  printf("The optimized order of the numbers is: %d, %d, %d\n", num_1, num_2, num_3);
  
  return 0;
}