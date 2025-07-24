//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cryptic
/* 
  Code Name: Br4q's Secret Geometric Calculator
  Version: 2.0
  Author: Br4q
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void secret_calculator(int number){
  float secret_formula = (3.14 * number * number) + (2 * number);
  printf("\nResult of secret geometric calculator: %.2f",secret_formula);
}

int main(){
  int input_data;
  char secret_key[10];

  printf("Enter secret key to access the Geometric Calculator: ");
  fgets(secret_key, 10, stdin);

  if(strcmp(secret_key, "br4q_secret") == 0){
    printf("\nAccess Granted! You are now entering the SECRET GEOMETRIC CALCULATOR\n");
    printf("Enter the radius of the Circle to calculate the Area and Perimeter: ");
    scanf("%d",&input_data);
    secret_calculator(input_data);
  }
  else{
    printf("\nAccess Denied! Please enter the correct secret key to access the calculator\n");
    exit(0);
  }
  return 0;
}