//FormAI DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include<stdio.h>
int main(){
  int i,j,k;
  for(i=1;i<=5;i++){
    for(j=1;j<=5;j++){
      if(i==j || i+j==6){
        printf("C");
      }
      else if((i==2 && j==1) || (i==3 && j==1)){
        printf("C");
      }
      else if((i==1 && j==2) || (i==1 && j==3)){
        printf("C");
      }
      else if((i==4 && j==5) || (i==5 && j==5)){
        printf("C");
      }
      else if((i==5 && j==4) || (i==5 && j==3)){
        printf("C");
      }
      else if(i==3 && j==5){
        printf("C");
      }
      else if(i==2 && j==5){
        printf("C");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}