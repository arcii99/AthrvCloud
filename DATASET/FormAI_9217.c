//FormAI DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include <stdio.h>

int main() {
  
  int rows = 7;
  
  for(int i=0;i<rows;i++){          //rows
    for(int j=0;j<=i;j++){         //columns
      if (j == 0 || j == i){        //check for corner values
          printf("1 ");             //print 1
      }
      else if (i%2 == 0){           //check for even row position
          int num = (2*i-j)/2;      //calculate number
          printf("%d ",num);        //print number
      }
      else{                         //check for odd row position
          int num = (2*i-j+1)/2;    //calculate number
          printf("%d ",num);        //print number
      }
    }
    printf("\n");                   //new line
  }
  return 0;                         //end program
}