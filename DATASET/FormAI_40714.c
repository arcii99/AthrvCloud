//FormAI DATASET v1.0 Category: Pattern printing ; Style: shape shifting
#include<stdio.h>

int main(){
  int rows,i,j,k,count=1,input;
  printf("Enter the number of rows: ");
  scanf("%d",&rows);
  input=rows;

  for(i=1;i<=rows;i++){
    for(j=1;j<=i;j++){
      putchar('*');
    }
    for(j=input-1;j>=1;j--){
      putchar(' ');
    }
    for(k=input-1;k>=1;k--){
      putchar(' ');
    }
    for(k=1;k<=i;k++){
      putchar('*');
    }
    input--;
    putchar('\n');
  }
  input=1;
  for(i=rows;i>=1;i--){
    for(j=1;j<=i;j++){
      putchar('*');
    }
    for(j=input;j>=1;j--){
      putchar(' '); 
    }
    for(k=input;k>=1;k--){
      putchar(' '); 
    }
    for(k=1;k<=i;k++){
      putchar('*');
    }
    input++;
    putchar('\n');
  }
  return 0;
}