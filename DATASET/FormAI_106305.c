//FormAI DATASET v1.0 Category: Memory management ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

int main() {
  char *p;
  int i, n;
  
  printf("Enter size of array:");
  scanf("%d", &n);
  
  p = (char *) malloc(n * sizeof(char));
  if(p == NULL) {
    printf("Memory allocation failed\n");
    exit(1);
  }
  
  printf("Enter character array: ");
  for(i = 0; i < n; i++) {
    scanf(" %c", &p[i]);
  }
  
  printf("Character array is: ");
  for(i = 0; i < n; i++) {
    printf("%c ", p[i]);
  }
  
  free(p);

  return 0;
}