//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>
int main(){
  printf("Hey there! Welcome to my C pattern printing program!\n");
  int n, i, j, k;
  printf("Enter a number of rows for the pattern (between 3 and 15): ");
  scanf("%d", &n);
  if(n>=3 && n<=15){
    for(i=1;i<=n;i++){
      for(j=1;j<=n-i;j++){
        printf(" ");
      }
      for(k=1;k<=(2*i-1);k++){
        if(k==1 || k==(2*i-1) || i==n){
          printf("*");
        }
        else{
          printf(" ");
        }
      }
      printf("\n");
    }
    for(i=1;i<=n-1;i++){
      for(j=1;j<=i;j++){
        printf(" ");
      }
      for(k=1;k<=(2*(n-i)-1);k++){
        if(k==1 || k==(2*(n-i)-1) || i==n-1){
          printf("*");
        }
        else{
          printf(" ");
        }
      }
      printf("\n");
    }
    printf("Voila! Pattern printed successfully!\n");
  }
  else{
    printf("Invalid input. Please enter a valid number of rows next time.\n");
  }
  return 0;
}