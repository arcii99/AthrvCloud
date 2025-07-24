//FormAI DATASET v1.0 Category: Binary Converter ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binaryToInt(char *binary){
  int len = strlen(binary);
  int decimal = 0, i;
  for(i = 0; i < len; i++){
    if(binary[i] == '1'){
      decimal += 1 << (len-i-1);
    }
  }
  return decimal;
}

char *intToBinary(int n){
  char *binary = malloc(33);
  memset(binary,0, strlen(binary));
  int i;
  for(i = 31; i >= 0; i--){
    binary[31 - i] = ((1<<i) & n) ? '1': '0';
  }
  return binary;
}

int main(){
  int choice;
  printf("Welcome to Medieval Binary Converter.\n");
  printf("Select 1 to convert binary to decimal.\n");
  printf("Select 2 to convert decimal to binary.\n");
  scanf("%d",&choice);

  if(choice == 1){
    char binary[33];
    printf("Enter a binary number: ");
    scanf("%32s",binary);
    printf("Decimal: %d\n", binaryToInt(binary));
  }
  else{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d",&n);
    printf("Binary: %s\n", intToBinary(n));
  }
  return 0;
}