//FormAI DATASET v1.0 Category: Sorting ; Style: lively
#include <stdio.h>

int main(){
  printf("Welcome to the sorting program!\n");

  /* Let's create an array to store some numbers */
  int numbers[] = { 5, 1, 13, 7, 21, 8, 6, 2 };
  int array_size = sizeof(numbers)/sizeof(numbers[0]);

  /* Let's print the array before sorting*/
  printf("Before sorting:\n");
  for (int i=0; i < array_size; i++){
    printf("%d ", numbers[i]);
  }

  /* Let's sort the array using Bubble Sort*/
  for (int i=0; i < array_size-1; i++){
    for (int j=0; j < array_size-i-1; j++){
      if (numbers[j] > numbers[j+1]){
        /* Swap the numbers */
        int temp = numbers[j];
        numbers[j] = numbers[j+1];
        numbers[j+1] = temp;
      }
    }
  }

  /* Let's print the array after sorting*/
  printf("\nAfter sorting using Bubble Sort:\n");
  for (int i=0; i < array_size; i++){
    printf("%d ", numbers[i]);
  }

  /* Let's sort the array using Selection Sort*/
  int smallest_index;
  for (int i=0; i < array_size-1; i++){
    smallest_index = i;
    for (int j=i+1; j < array_size; j++){
      if (numbers[j] < numbers[smallest_index]){
        smallest_index = j;
      }
    }
    /* Swap the numbers */
    int temp = numbers[i];
    numbers[i] = numbers[smallest_index];
    numbers[smallest_index] = temp;
  }

  /* Let's print the array after sorting*/
  printf("\nAfter sorting using Selection Sort:\n");
  for (int i=0; i < array_size; i++){
    printf("%d ", numbers[i]);
  }

  /* Let's sort the array using Insertion Sort*/
  int j, key;
  for (int i=1; i < array_size; i++){
    key = numbers[i];
    j = i - 1;

    /* Move the elements of the array one position ahead if they are greater than key*/
    while (j >= 0 && numbers[j] > key){
      numbers[j+1] = numbers[j];
      j = j - 1;
    }
    numbers[j+1] = key;
  }

  /* Let's print the array after sorting*/
  printf("\nAfter sorting using Insertion Sort:\n");
  for (int i=0; i < array_size; i++){
    printf("%d ", numbers[i]);
  }

  return 0;
}