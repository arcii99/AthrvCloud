//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: paranoid
#include<stdio.h>

void main(){
  char input[100];

  printf("Enter the hexadecimal number you want to convert: ");
  scanf("%s", input);

  for(int i=0;i<strlen(input);i++){
    if(input[i]<'0' || (input[i]>'9' && (input[i]<'A' || input[i]>'F'))){
      printf("Error: Invalid hexadecimal input!");
      return;
    }
  }

  long int decimal = 0;
  int power = 0;
  int length = strlen(input);

  for(int i=length-1;i>=0;i--){
    int digit = 0;
    if(input[i]>='0' && input[i]<='9'){
      digit = input[i] - '0';
    } else{
      digit = input[i] - 'A' + 10;
    }
    decimal += digit * pow(16, power++);
  }

  printf("The decimal equivalent of %s is %ld\n", input, decimal);
}