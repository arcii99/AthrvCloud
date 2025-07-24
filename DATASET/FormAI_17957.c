//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include<stdio.h>
int main(){
  int n=5;
  for(int i=0;i<n;i++){   //iterate through rows
    for(int j=0;j<n;j++){   //iterate through columns
      if(j==0 || i==(n/2) || i==n-1){   //print '*' in the first column or middle row or last row
        printf("* ");
      }
      else if(i< n/2){   //print spaces for the upper half of the array
        if(j<=i && ((i+j)%2==0))   //check if it is a diagonal and even numbered coordinate
          printf("* ");
          else
          printf("  ");  //print space for the other coordinates
      }
      else{   //print spaces for the lower half of the array
        if(j<n-i-1 && ((i+j)%2==0))   //check if it is a diagonal and even numbered coordinate
          printf("* ");  
          else
          printf("  ");  //print space for the other coordinates 
      }
    }
    printf("\n");   //new line at the end of each row
  }
  return 0;
}