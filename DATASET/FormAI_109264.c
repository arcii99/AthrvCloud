//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>

void gratitudeSort(int arr[], int n) {
  // Gratitude messages to show appreciation for each element
  char* gratitude[] = {"Thank you", "Bless you", "Appreciate you", "Grateful for you", "You're amazing", "You're the best", "Incredible!", "Awesome!", "Fantastic!", "Marvelous!", "Excellent!"};
  
  int i, j, temp;
  
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        // Swap elements and show gratitude
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        printf("%s %d\n", gratitude[i%11], arr[j]);
        printf("%s %d\n", gratitude[(i+1)%11], arr[j+1]);
      }
    }
  }
}

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  gratitudeSort(arr, n);
  
  printf("Sorted array: ");
  for (int i=0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  
  return 0;
}