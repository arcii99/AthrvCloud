//FormAI DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>

int main(){
    int a, b, c, d, e, f;
    printf("Come Watson, the game is afoot. Let's solve this puzzle!\n");
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);
    printf("What operation would you like to perform?\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &c);
    switch(c){
        case 1:
            d = a + b;
            printf("%d + %d = %d\n", a, b, d);
            break;
        case 2:
            d = a - b;
            printf("%d - %d = %d\n", a, b, d);
            break;
        case 3:
            d = a * b;
            printf("%d * %d = %d\n", a, b, d);
            break;
        case 4:
            if(b == 0){
                printf("Elementary, my dear Watson. Division by zero is not allowed.\n");
            }else{
                d = a / b;
                e = a % b;
                printf("%d ÷ %d = %d with a remainder of %d\n", a, b, d, e);
            }
            break;
        default:
            printf("The game is up. Please enter a valid option.\n");
            break;
    }
    printf("Thank you for playing, Watson. To the codefile and onward!\n");
    return 0;
}