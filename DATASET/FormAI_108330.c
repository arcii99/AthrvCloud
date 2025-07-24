//FormAI DATASET v1.0 Category: Math exercise ; Style: imaginative
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
    int x, y, z, a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w;

    printf("\nWelcome to the Math Exercise program! Let us test your mathematical abilities.\n\n");
    printf("What is 8 x 13? ");
    scanf("%d", &x);
    if(x == 104)
    {
        printf("Correct! Onto the next question.\n\n");
    }
    else
    {
        printf("Incorrect. The answer is 104.\n\n");
    }

    printf("What is the square root of 169? ");
    scanf("%d", &y);
    if(y == 13)
    {
        printf("Great job! You are doing well.\n\n");
    }
    else
    {
        printf("Sorry, the correct answer is 13.\n\n");
    }

    printf("Find the value of x in 3x + 4 = 13: ");
    scanf("%d", &z);
    if(z == 3)
    {
        printf("Correct! You have a good grasp of algebra.\n\n");
    }
    else
    {
        printf("Incorrect. The answer is 3.\n\n");
    }

    printf("Next question: What is the derivative of x^2 + 2x? ");
    scanf("%d", &a);
    if(a == 4)
    {
        printf("Excellent! You know your calculus.\n\n");
    }
    else
    {
        printf("Sorry, the correct answer is 4.\n\n");
    }

    printf("Solve the following equations(Enter comma in between the coefficients):\n4x + 3y + 2z = 15\n3x - 5y + 6z = -13\n2x + 6y - 2z = 10\n");
    scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m);

    n = (g*d-b*j)/(a*d-b*e);
    o = (h*d-c*j)/(b*e-a*d);
    p = (i-g*c)/(a*d-b*e);
    q = (g*f-e*h)/(a*e-b*d);
    r = (e*i-a*h)/(b*d-a*e);
    s = (b*f-c*e)/(a*e-b*d);

    if(n == 1 && o == 2 && p == 3 && q == 4 && r == 5 && s == 6)
    {
        printf("Congratulations! You are a math genius.\n\n");
    }
    else
    {
        printf("Sorry, some of your answers are incorrect. Better luck next time.\n\n");
    }

    printf("Let's try something different. Enter 10 numbers and find out their average and standard deviation: ");
    scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",&t,&u,&v,&w,&x,&y,&z,&a,&b,&c);

    d = (t + u + v + w + x + y + z + a + b + c)/10;
    e = sqrt((pow((t-d),2) + pow((u-d),2) + pow((v-d),2) + pow((w-d),2) + pow((x-d),2) + pow((y-d),2) + pow((z-d),2) + pow((a-d),2) + pow((b-d),2) + pow((c-d),2))/10);

    printf("The average of the 10 numbers is: %d\n", d);
    printf("The standard deviation of the 10 numbers is: %d\n", e);

    printf("\nThanks for trying out this Math Exercise program. Hope you had fun!\n");

    return 0;
}