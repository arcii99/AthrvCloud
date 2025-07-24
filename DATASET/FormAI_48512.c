//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include<stdio.h>

int main(){

  printf("Welcome to the immersive arithmetic example program! \n\n");

  int a,b;
  printf("Enter two integers: ");
  scanf("%d %d",&a,&b);

  printf("\n          *********** Arithmetic Operations ***********\n\n");

  // Addition
  printf("\n%d + %d = %d\n",a,b,a+b);

  // Subtraction
  printf("\n%d - %d = %d\n",a,b,a-b);

  // Multiplication
  printf("\n%d * %d = %d\n",a,b,a*b);

  // Division
  if(b != 0){
    printf("\n%d / %d = %d\n",a,b,a/b);
  }
  else{
    printf("\nDivision by zero is undefined\n");
  }

  // Modulo
  if(b != 0){
    printf("\n%d %% %d = %d\n",a,b,a%b);
  }
  else{
    printf("\nModulo operation by zero is undefined\n");
  }

  printf("\n************** Thank you for using the program **************\n");

  return 0;
}