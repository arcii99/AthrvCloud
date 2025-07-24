//FormAI DATASET v1.0 Category: Arithmetic ; Style: calm
#include <stdio.h>

int main() {
  	int first_num, second_num, sum, difference, product;
    float quotient;
  
  	printf("Please enter the first number: ");
  	scanf("%d", &first_num);
  	printf("Please enter the second number: ");
  	scanf("%d", &second_num);
    
    sum = first_num + second_num;
    difference = first_num - second_num;
    product = first_num * second_num;
    quotient = (float)first_num / second_num;
    
    printf("The sum of %d and %d is: %d\n", first_num, second_num, sum);
    printf("The difference between %d and %d is: %d\n", first_num, second_num, difference);
    printf("The product of %d and %d is: %d\n", first_num, second_num, product);
  	printf("The quotient of %d and %d is: %.2f\n", first_num, second_num, quotient);

    return 0;
}