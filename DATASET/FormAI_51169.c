//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: happy
#include <stdio.h>
#include <math.h>

int main(){
  char operator;
  double first, second;

  printf("Welcome to the happiest scientific calculator!\n");
  printf("Enter a math operation (+, -, *, /, ^, or s for sin): ");
  scanf("%c", &operator);

  if(operator == 's'){
    printf("Enter an angle (in degrees): ");
    scanf("%lf", &first);
    first = first * M_PI/180.0;
    printf("The sine of %lf degrees is %lf\n", first*180.0/M_PI, sin(first));
  } else {
    printf("Enter the first number: ");
    scanf("%lf", &first);
    printf("Enter the second number: ");
    scanf("%lf", &second);

    switch(operator){
      case '+':
        printf("%lf + %lf = %lf\n", first, second, first + second);
        break;
      case '-':
        printf("%lf - %lf = %lf\n", first, second, first - second);
        break;
      case '*':
        printf("%lf * %lf = %lf\n", first, second, first * second);
        break;
      case '/':
        if(second == 0){
          printf("Error: division by zero\n");
        } else {
          printf("%lf / %lf = %lf\n", first, second, first / second);
        }
        break;
      case '^':
        printf("%lf ^ %lf = %lf\n", first, second, pow(first, second));
        break;
      default:
        printf("Invalid operator!\n");
    }
  }

  printf("Thank you for using the happiest scientific calculator!\n");
  return 0;
}