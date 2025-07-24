//FormAI DATASET v1.0 Category: Arithmetic ; Style: brave
#include <stdio.h>

int main() {

printf("It's time to do some arithmetic and show some bravery!"); 

int num1, num2, add, sub, mult, rem;

printf("Enter two numbers:");
scanf("%d %d", &num1, &num2);

add = num1 + num2;
sub = num1 - num2;
mult = num1 * num2;
rem = num1 % num2;

printf("\n");
printf("The sum of %d and %d is %d.\n", num1, num2, add);
printf("The difference of %d and %d is %d.\n", num1, num2, sub);
printf("The product of %d and %d is %d.\n", num1, num2, mult);
printf("The remainder when %d is divided by %d is %d.\n", num1, num2, rem);
printf("\n");

printf("But wait, there's more! Let's use some bravery and push beyond traditional arithmetic!\n");

int num3 = 5;

printf("If we add %d, we get %d.\n", num3, add + num3);
printf("If we subtract %d, we get %d.\n", num3, sub - num3);
printf("If we multiply by %d, we get %d.\n", num3, mult * num3);
printf("\n");

printf("And now for the bravest part...let's divide by %d!\n", num3);
float div = (float) sub / num3;

if(div < 1) {
   printf("I'm not afraid of fractions! %d divided by %d is %f.\n", sub, num3, div);
} else {
   printf("%d divided by %d is %f. I am a fearless arithmetic machine!\n", sub, num3, div);
}

printf("Thanks for joining me on this brave arithmetic journey! Until next time...\n");

return 0;
}