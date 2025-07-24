//FormAI DATASET v1.0 Category: Arithmetic ; Style: imaginative
#include <stdio.h>

int main() {
  	int a = 10, b = 20, c;
  	printf("Welcome to my math program!\n");
  	
  	// Addition
  	c = a + b;
  	printf("Adding %d and %d results in %d\n", a, b, c);
  	
  	// Subtraction
  	c = b - a;
  	printf("Subtracting %d from %d results in %d\n", a, b, c);
  	
  	// Multiplication
  	c = a * b;
  	printf("Multiplying %d and %d results in %d\n", a, b, c);
  	
  	/* Division */
  	c = b / a;
  	printf("Dividing %d by %d results in %d\n", b, a, c);
  	
  	// Modulus
  	c = b % a;
  	printf("%d modulus %d is %d\n", b, a, c);
  	
  	// Relational
  	if(a == b) {
      		printf("%d is equal to %d\n", a, b);
  	}
  	else {
    		printf("%d is not equal to %d\n", a, b);
  	}
  	
  	if(a > b) {
    		printf("%d is greater than %d\n", a, b);
  	}
  	else {
    		printf("%d is not greater than %d\n", a, b);
  	}
  	
  	if(a >= b) {
    		printf("%d is greater than or equal to %d\n", a, b);
  	}
  	else {
    		printf("%d is not greater than or equal to %d\n", a, b);
  	}
  	
  	if(a < b) {
    		printf("%d is less than %d\n", a, b);
  	}
  	else {
    		printf("%d is not less than %d\n", a, b);
  	}
  	
  	if(a <= b) {
    		printf("%d is less than or equal to %d\n", a, b);
  	}
  	else {
    		printf("%d is not less than or equal to %d\n", a, b);
  	}
  	
  	// Logical
  	if(a && b) {
      		printf("Both %d and %d are true\n", a, b);
  	}
  
  	if(a || b) {
       		printf("At least one of %d and %d are true\n", a, b);
  	}
  
  	if(!a) {
    		printf("%d is false\n", a);
  	}
  	else {
    		printf("%d is true\n", a);
  	}
  
  	// Bitwise
  	c = a & b;
  	printf("%d AND %d results in %d\n", a, b, c);
  	
	c = a | b;
  	printf("%d OR %d results in %d\n", a, b, c);
  	
  	c = a ^ b;
  	printf("%d XOR %d results in %d\n", a, b, c);
  	
  	c = ~a;
  	printf("Complement of %d is %d\n", a, c);
  	
  	c = a << 2;
  	printf("%d shifted left by 2 bits is %d\n", a, c);
  	
  	c = a >> 2;
  	printf("%d shifted right by 2 bits is %d\n", a, c);

  return 0;
}