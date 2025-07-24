//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h> 

int main() 
{ 
  printf("Get ready to witness the most unique C pattern printing program!\n"); 
  printf("Enter the size of the pattern you want to print: \n"); 
  int size; 
  scanf("%d",&size); 
  int mid = size / 2; 
  for (int i = 0; i < size; i++) 
  { 
    for (int j = 0; j < size; j++) 
    { 
      if (i == mid || j == mid) 
      { 
        printf(" * "); 
      } 
      else if (i > mid && j > mid) 
      { 
        printf(" - "); 
      } 
      else if (i > mid && j < mid) 
      { 
        printf(" + "); 
      } 
      else if (i < mid && j > mid) 
      { 
        printf(" / "); 
      } 
      else if (i < mid && j < mid) 
      { 
        printf(" \\ "); 
      } 
      else 
      { 
        printf("   "); 
      } 
    } 
    printf("\n"); 
  } 
  printf("Wow! Wasn't that exciting?! You just created a masterpiece!\n"); 
  return 0; 
}