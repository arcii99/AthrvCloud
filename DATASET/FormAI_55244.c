//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>

int main() {

int num1, num2, num3, result;

printf("Welcome to the immersive Arithmetic Program!\n");
printf("Enter the first number:");
scanf("%d", &num1);
printf("Enter the second number:");
scanf("%d", &num2);
printf("Enter the third number:");
scanf("%d", &num3);

result = num1 + num2 + num3;

printf("The sum of %d, %d, and %d is %d.\n", num1, num2, num3, result);

if (result % 2 == 0){
    printf("The sum of the three numbers is even.\n");
} else {
    printf("The sum of the three numbers is odd.\n");
}
if (result > 100) {
    printf("The sum of the three numbers is greater than 100.\n");
}
printf("Thanks for using the immersive Arithmetic Program!\n");
return 0;
}