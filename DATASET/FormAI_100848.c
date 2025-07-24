//FormAI DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>

int main() {
	
	int num1 = 12, num2 = 6, num3 = 5, result;
	
	printf("Let's do some arithmetic calculations!\n");
	
	//addition
	result = num1 + num2;
	printf("%d + %d = %d\n", num1, num2, result);
	
	//subtraction
	result = num1 - num3;
	printf("%d - %d = %d\n", num1, num3, result);
	
	//multiplication
	result = num2 * num3;
	printf("%d * %d = %d\n", num2, num3, result);
	
	//division
	result = num1 / num2;
	printf("%d / %d = %d\n", num1, num2, result);
	
	//modulus
	result = num1 % num3;
	printf("%d %% %d = %d\n", num1, num3, result);
	
	//increment and decrement
	printf("%d++ = %d\n", num1, num1++);
	printf("%d-- = %d\n", num2, num2--);
	
	printf("Now let's use some shorthand arithmetic to change the values:\n");
	
	//shorthand arithmetic
	num1 += 5;
	printf("num1 += 5 is %d\n", num1);
	num2 -= 3;
	printf("num2 -= 3 is %d\n", num2);
	num3 *= 2;
	printf("num3 *= 2 is %d\n", num3);
	
	return 0;
}