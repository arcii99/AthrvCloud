//FormAI DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include<stdio.h>

//Function to print binary representation of a decimal number
void printBinary(int n){

    for(int i=31;i>=0;i--){
        if(n & (1<<i))
            printf("1");
        else
            printf("0");
    }

}

int main(){

    //Declaring variables
    int a,b;

    //Taking input from user
    printf("Enter two numbers:\n");
    scanf("%d%d",&a,&b);

    //Printing binary representation of entered numbers
    printf("Binary representation of %d is: ",a);
    printBinary(a);
    printf("\nBinary representation of %d is: ",b);
    printBinary(b);

    //Performing bitwise operations
    int AND = a & b;
    int OR = a | b;
    int XOR = a ^ b;
    int NOT_a = ~a;
    int NOT_b = ~b;
    int a_shift_left = a << 1;
    int b_shift_right = b >> 1;

    //Printing results
    printf("\n%d AND %d = %d\n",a,b,AND);
    printf("%d OR %d = %d\n",a,b,OR);
    printf("%d XOR %d = %d\n",a,b,XOR);
    printf("NOT of %d = %d\n",a,NOT_a);
    printf("NOT of %d = %d\n",b,NOT_b);
    printf("%d shifted left by 1 = %d\n",a,a_shift_left);
    printf("%d shifted right by 1 = %d\n",b,b_shift_right);

    return 0;
}