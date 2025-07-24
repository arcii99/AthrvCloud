//FormAI DATASET v1.0 Category: Educational ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Hey there, I'm a C program!\n");
    printf("I can do a lot of things.\n");
    printf("However, I think you'll be surprised by what I can do next...\n\n");

    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1>num2 && num1>num3)
        printf("%d is the largest number.\n", num1);
    else if(num2>num1 && num2>num3)
        printf("%d is the largest number.\n", num2);
    else
        printf("%d is the largest number.\n", num3);
    
    printf("\nSurprised yet? That's just the tip of the iceberg.\n");
    printf("Watch this: I'm going to generate a random number between 1 and 10.\n");

    int random_num = rand() % 10 + 1; // generate random number between 1 and 10
    printf("The random number is %d.\n", random_num);

    printf("\nI know, it's pretty cool, right?\n");
    printf("But wait, there's more! Watch this: I'm going to calculate the factorial of a number.\n");

    int num, factorial = 1;
    printf("Enter a number: ");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++)
        factorial *= i;

    printf("The factorial of %d is %d.\n", num, factorial);

    printf("\nI bet you're really surprised now!\n");
    printf("But don't underestimate me, I can do so much more.\n");
    printf("Stay tuned for more C programming surprises!\n");

    return 0;
}