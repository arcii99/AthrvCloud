//FormAI DATASET v1.0 Category: Calculator ; Style: enthusiastic
//Welcome to the Super Calculator!
//This calculator is unlike any other, it can do it all!
//Addition, Subtraction, Multiplication, Division, even Exponents and Factorials!
//And the best part? It's all in one place! No more switching between apps or programs!
//Are you ready to experience the power of the Super Calculator? Let's get started!

#include<stdio.h>
#include<math.h>

int main(){
  int choice;
  float num1, num2, result;
  printf("Welcome to the Super Calculator!\n");
  printf("What operation would you like to perform?\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Exponents\n");
  printf("6. Factorials\n");
  printf("Enter your choice: ");
  scanf("%d",&choice);

  switch(choice){
    case 1:
      printf("\nYou want to perform addition!\n");
      printf("Enter your first number: ");
      scanf("%f",&num1);
      printf("Enter your second number: ");
      scanf("%f",&num2);
      result = num1 + num2;
      printf("%.2f + %.2f = %.2f\n",num1,num2,result);
      break;
      
    case 2:
      printf("\nYou want to perform subtraction!\n");
      printf("Enter your first number: ");
      scanf("%f",&num1);
      printf("Enter your second number: ");
      scanf("%f",&num2);
      result = num1 - num2;
      printf("%.2f - %.2f = %.2f\n",num1,num2,result);
      break;
      
    case 3:
      printf("\nYou want to perform multiplication!\n");
      printf("Enter your first number: ");
      scanf("%f",&num1);
      printf("Enter your second number: ");
      scanf("%f",&num2);
      result = num1 * num2;
      printf("%.2f * %.2f = %.2f\n",num1,num2,result);
      break;
      
    case 4:
      printf("\nYou want to perform division!\n");
      printf("Enter your first number: ");
      scanf("%f",&num1);
      printf("Enter your second number: ");
      scanf("%f",&num2);
      result = num1 / num2;
      printf("%.2f / %.2f = %.2f\n",num1,num2,result);
      break;
      
    case 5:
      printf("\nYou want to perform exponents!\n");
      printf("Enter your base: ");
      scanf("%f",&num1);
      printf("Enter your exponent: ");
      scanf("%f",&num2);
      result = pow(num1,num2);
      printf("%.2f^%.2f = %.2f\n",num1,num2,result);
      break;
      
    case 6:
      printf("\nYou want to perform factorials!\n");
      printf("Enter your number: ");
      scanf("%f",&num1);
      result = 1;
      for(int i=1;i<=num1;i++){
        result *= i;
      }
      printf("%.2f! = %.2f\n",num1,result);
      break;
      
    default:
      printf("\nInvalid choice!\n");
      break;
  }
  
  printf("Thank you for using the Super Calculator!\n");
  printf("Come back soon for all your calculation needs!\n");

  return 0;
}