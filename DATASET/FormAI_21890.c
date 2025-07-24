//FormAI DATASET v1.0 Category: Bitwise operations ; Style: invasive
#include<stdio.h>

//Function to convert decimal to binary
void decToBin(int num){
    int binary[32];
    int index = 0;
    while(num > 0){
        binary[index] = num % 2;
        num = num / 2;
        index++;
    }
    for(int i = index - 1; i >= 0; i--){
        printf("%d", binary[i]);
    }
    printf("\n");
}

//Function to perform bitwise operations
void bitwiseOperation(int num1, int num2){
    printf("Bitwise AND: %d & %d = %d\n", num1, num2, num1 & num2);
    printf("Bitwise OR: %d | %d = %d\n", num1, num2, num1 | num2);
    printf("Bitwise XOR: %d ^ %d = %d\n", num1, num2, num1 ^ num2);
    printf("Bitwise NOT of %d: ~%d = %d\n", num1, num1, ~num1);
    printf("Bitwise NOT of %d: ~%d = %d\n", num2, num2, ~num2);
    printf("Left Shift of %d by 2 bits: %d<<2 = %d\n", num1, num1, num1<<2);
    printf("Right Shift of %d by 2 bits: %d>>2 = %d\n", num2, num2, num2>>2);
    printf("Binary of %d: ", num1);
    decToBin(num1);
    printf("Binary of %d: ", num2);
    decToBin(num2);
}

int main(){
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    printf("\nPerforming Bitwise Operations on %d and %d:\n\n", num1, num2);
    bitwiseOperation(num1, num2);

    return 0;
}