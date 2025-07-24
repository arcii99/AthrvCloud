//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <math.h>

int main() {
    printf("Believe it or not, we're going to do some really cool math today!\n");
    
    printf("First, let's choose a number between 1 and 10: ");
    int num;
    scanf("%d", &num);
    printf("You chose %d! Excellent choice.\n\n", num);
    
    printf("Now, let's find the square root of %d.\n", num);
    double sqrt_num = sqrt(num);
    printf("The square root of %d is %lf.\n\n", num, sqrt_num);
    
    printf("Next, let's find the absolute value of %d.\n", num - 10);
    int abs_num = abs(num - 10);
    printf("The absolute value of %d minus 10 is %d.\n\n", num, abs_num);
    
    printf("Wow, we're really getting wild now. Let's do some trigonometry!\n");
    double radians = num * (M_PI/180);
    printf("If we convert %d degrees to radians, we get %lf.\n\n", num, radians);
    
    printf("Okay, hold onto your hats because we're about to do some exponential calculations.\n");
    printf("What number would you like to raise %d to? ", num);
    double exp_num;
    scanf("%lf", &exp_num);
    double power = pow(num, exp_num);
    printf("%d raised to the power of %lf is %lf.\n\n", num, exp_num, power);
    
    printf("I hope you're ready for some serious math now. We're going to find the hypotenuse of a right triangle.\n");
    printf("Choose one of the sides of the triangle: ");
    int side_1;
    scanf("%d", &side_1);
    printf("Choose the other side of the triangle: ");
    int side_2;
    scanf("%d", &side_2);
    double hypotenuse = sqrt(pow(side_1, 2) + pow(side_2, 2));
    printf("The hypotenuse of a right triangle with sides %d and %d is %lf.\n", side_1, side_2, hypotenuse);
    printf("I told you this was going to be cool math!\n");
    
    return 0;
}