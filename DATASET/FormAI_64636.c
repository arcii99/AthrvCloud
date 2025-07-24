//FormAI DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>

int main() {
  int numbers[] = {23, 12, 47, 5, 89, 37};
  int smallest = numbers[0];
  int largest = numbers[0];
  float sum = 0;
  int count = sizeof(numbers) / sizeof(numbers[0]);
  
  for (int i = 0; i < count; i++) {
    if (numbers[i] < smallest) {
      smallest = numbers[i];
    }
    if (numbers[i] > largest)  {
      largest = numbers[i];
    }
    sum += numbers[i];
  }
  
  float average = sum / count;
  
  printf("The smallest number in the array is: %d\n", smallest);
  printf("The largest number in the array is: %d\n", largest);
  printf("The sum of the numbers in the array is: %.1f\n", sum);
  printf("The average of the numbers in the array is: %.1f\n", average);

  return 0;
}