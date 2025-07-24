//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//function to display the menu
void display_menu(){
  printf("Welcome to Ken's Scientific Calculator\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Power\n");
  printf("6. Square Root\n");
  printf("7. Logarithm\n");
  printf("8. Sine\n");
  printf("9. Cosine\n");
  printf("10. Tangent\n");
  printf("Enter your choice: ");
}

//function to perform addition
float addition(float num1, float num2){
  return num1 + num2;
}

//function to perform subtraction
float subtraction(float num1, float num2){
  return num1 - num2;
}

//function to perform multiplication
float multiplication(float num1, float num2){
  return num1 * num2;
}

//function to perform division
float division(float num1, float num2){
  return num1 / num2;
}

//function to perform power
float power(float num1, float num2){
  return pow(num1, num2);
}

//function to perform square root
float square_root(float num){
  return sqrt(num);
}

//function to perform logarithm
float logarithm(float num){
  return log10(num);
}

//function to perform sine
float sine(float num){
  return sin(num);
}

//function to perform cosine
float cosine(float num){
  return cos(num);
}

//function to perform tangent
float tangent(float num){
  return tan(num);
}

//main function
int main(){
  int choice;
  float num1, num2;

  while(1){
    display_menu();
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", addition(num1, num2));
        break;

      case 2:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", subtraction(num1, num2));
        break;

      case 3:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", multiplication(num1, num2));
        break;

      case 4:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", division(num1, num2));
        break;

      case 5:
        printf("Enter two numbers: ");
        scanf("%f %f", &num1, &num2);
        printf("Result: %f\n", power(num1, num2));
        break;

      case 6:
        printf("Enter a number: ");
        scanf("%f", &num1);
        printf("Result: %f\n", square_root(num1));
        break;

      case 7:
        printf("Enter a number: ");
        scanf("%f", &num1);
        printf("Result: %f\n", logarithm(num1));
        break;

      case 8:
        printf("Enter a number: ");
        scanf("%f", &num1);
        printf("Result: %f\n", sine(num1));
        break;

      case 9:
        printf("Enter a number: ");
        scanf("%f", &num1);
        printf("Result: %f\n", cosine(num1));
        break;

      case 10:
        printf("Enter a number: ");
        scanf("%f", &num1);
        printf("Result: %f\n", tangent(num1));
        break;

      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}