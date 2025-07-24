//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double num, res;
  char operator;

  printf("Enter an expression (e.g. 2 + 3): ");
  scanf("%lf %c %lf", &num, &operator, &res);

  switch(operator) {
    case '+':
      res = num + res;
      printf("%.2lf\n", res);
      break;
    case '-':
      res = num - res;
      printf("%.2lf\n", res);
      break;
    case '*':
      res = num * res;
      printf("%.2lf\n", res);
      break;
    case '/':
    	if(res == 0){
    		printf("Cannot Divide by Zero\n");
    		exit(1);
    	}
      res = num / res;
      printf("%.2lf\n", res);
      break;
    case '^':
      res = pow(num, res);
      printf("%.2lf\n", res);
      break;
    case 's':
      res = sin(num);
      printf("%.2lf\n", res);
      break;
    case 'c':
      res = cos(num);
      printf("%.2lf\n", res);
      break;
    case 't':
      res = tan(num);
      printf("%.2lf\n", res);
      break;
    case 'l':
      res = log10(num);
      printf("%.2lf\n", res);
      break;
    case 'e':
      res = exp(num);
      printf("%.2lf\n", res);
      break;
    default:
      printf("Invalid Operator\n");
      break;
  }

  return 0;
}