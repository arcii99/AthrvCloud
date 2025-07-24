//FormAI DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include<stdio.h>
int main(){
  int rows, i, j, k;
  
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  
  // Outer loop to iterate number of rows
  for(i=1; i<=rows; i++){
    
    // Inner loop to print spaces
    for(j=i; j<=rows; j++){
      printf(" ");
    }
    
    // Inner loop to print asterisks
    for(k=i; k>=1; k--){
      printf("* ");
    }
    
    printf("\n");
  }
  return 0;
}