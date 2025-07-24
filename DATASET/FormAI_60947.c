//FormAI DATASET v1.0 Category: Bitwise operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to the Bitwise Adventure!\n\n");
    printf("In this program, we will be using magical powers to manipulate bits.\n");
    printf("We will be converting numbers into their binary form and performing operations on them.\n\n");

    int a, b, c = 0, option;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("\n");
    printf("Choose an operation: \n");
    printf("1 -> Bitwise AND\n");
    printf("2 -> Bitwise OR\n");
    printf("3 -> Bitwise XOR\n");
    printf("4 -> Bitwise NOT\n");

    scanf("%d", &option);

    switch(option)
    {
        case 1:
            c = a & b;
            printf("The result of %d & %d is: %d\n", a, b, c);
            break;
        case 2:
            c = a | b;
            printf("The result of %d | %d is: %d\n", a, b, c);
            break;
        case 3:
            c = a ^ b;
            printf("The result of %d ^ %d is: %d\n", a, b, c);
            break;
        case 4:
            c = ~a;
            printf("The NOT of %d is: %d\n", a, c);
            break;
        default:
            printf("Invalid option selected\n");
            return -1;
    }

    printf("\n");
    printf("Now, let's have some fun with binary!\n");
    printf("Let's see the binary representation of %d and %d\n", a, b);

    printf("\n");
    printf("The binary representation of %d is: ", a);
    convertToBinary(a);
    printf("\n");
    printf("The binary representation of %d is: ", b);
    convertToBinary(b);
    printf("\n");

    printf("\n");
    printf("Magical things are happening!\n");
    printf("Let's perform the same operation on the binary representation of %d and %d\n", a, b);

    switch(option)
    {
        case 1:
            printf("The result of ");
            convertToBinary(a);
            printf(" & ");
            convertToBinary(b);
            printf(" is: ");
            convertToBinary(c);
            printf("\n");
            break;
        case 2:
            printf("The result of ");
            convertToBinary(a);
            printf(" | ");
            convertToBinary(b);
            printf(" is: ");
            convertToBinary(c);
            printf("\n");
            break;
        case 3:
            printf("The result of ");
            convertToBinary(a);
            printf(" ^ ");
            convertToBinary(b);
            printf(" is: ");
            convertToBinary(c);
            printf("\n");
            break;
        case 4:
            printf("The NOT of ");
            convertToBinary(a);
            printf(" is: ");
            convertToBinary(c);
            printf("\n");
            break;
    }

    printf("\n");
    printf("Thank you for joining me on this Bitwise Adventure!\n\n");
    return 0;
}

void convertToBinary(int num)
{
    if(num / 2 != 0)
        convertToBinary(num / 2);

    printf("%d", num % 2);
}