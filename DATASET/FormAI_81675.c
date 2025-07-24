//FormAI DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num1, num2, num3, result;
    char puzzler[50];
    
    printf("Welcome to the arithmetic puzzler!\n");
    printf("Enter any three numbers you wish to puzzle: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("Great choice! Now, choose your puzzler: \n");
    printf("1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%s", &puzzler);
    
    switch(puzzler[0]){
        case '1' : result = num1+num2-num3;
                   printf("%d + %d - %d = %d", num1, num2, num3, result);
                   break;

        case '2' : result = num1-num2*num3;
                   printf("%d - %d * %d = %d", num1, num2, num3, result);
                   break;

        case '3' : result = num1*num2/num3;
                   printf("%d * %d / %d = %d", num1, num2, num3, result);
                   break;

        case '4' : result = num1/num2+num3;
                   printf("%d / %d + %d = %d", num1, num2, num3, result);
                   break;

        default  : printf("You entered an invalid choice!");
                   break;
    }
    return 0;
}