//FormAI DATASET v1.0 Category: Calculator ; Style: excited
#include<stdio.h>

int main(){
  printf("Welcome to the Exciting Calculator!\n");
  printf("This amazing calculator can perform basic mathematical operations with two numbers!\n");
  
  float num1, num2;
  char op;
  float result;
  
  printf("Enter the operator (+, -, *, /): ");
  scanf("%c", &op);
  
  printf("Enter two numbers: ");
  scanf("%f %f", &num1, &num2);
  
  if(op == '+'){
    result = num1 + num2;
    printf("Wow! The result of %.2f + %.2f is %.2f!\n", num1, num2, result);
  }
  else if(op == '-'){
    result = num1 - num2;
    printf("Awesome! The result of %.2f - %.2f is %.2f!\n", num1, num2, result);
  }
  else if(op == '*'){
    result = num1 * num2;
    printf("Incredible! The result of %.2f * %.2f is %.2f!\n", num1, num2, result);
  }
  else if(op == '/'){
    if(num2 == 0){
      printf("Error: Cannot divide by zero. Please try again!\n");
    }
    else{
      result = num1 / num2;
      printf("Amazing! The result of %.2f / %.2f is %.2f!\n", num1, num2, result);
    }
  }
  else{
    printf("Invalid operator. Please try again!\n");
  }
  
  printf("Thank you for using the Exciting Calculator! Have a great day!\n");
  
  return 0;
}