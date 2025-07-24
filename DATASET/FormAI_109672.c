//FormAI DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include <stdio.h>

int main() {
  int n, search, array[1000];
  printf("Enter the size of array: ");
  scanf("%d", &n);
  
  printf("Enter %d integers: ", n);
  for(int i=0; i<n; i++)
    scanf("%d", &array[i]);
  
  printf("Enter the number to search: ");
  scanf("%d", &search);
  
  int found = 0;
  int left = 0;
  int right = n - 1;
  int mid;
  
  while(left <= right) {
    mid = (left + right) / 2;
    if(array[mid] < search)
      left = mid + 1;
    else if(array[mid] > search)
      right = mid - 1;
    else {
      found = 1;
      break;
    }
  }
  
  if(found == 1)
    printf("%d is present at location %d.\n", search, mid+1);
  else
    printf("%d is not present in the array.\n", search);
  
  return 0;
}