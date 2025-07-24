//FormAI DATASET v1.0 Category: Binary Converter ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

int main(){
  int num, binary_num, decimal_num=0, base=1, rem;
  
  printf("Enter a binary number: ");
  scanf("%d", &num);
  
  binary_num=num;
  
  while(num>0){
    rem = num%10;
    decimal_num = decimal_num + rem*base;
    num = num/10;
    base = base*2;
  }
  
  printf("The decimal equivalent of the binary number %d is %d.\n", binary_num, decimal_num);
  
  return 0;
}