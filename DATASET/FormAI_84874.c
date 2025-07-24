//FormAI DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include<stdio.h>

//Function to configure bitwise operation based on user's choice
int configureBitwiseOperation(int num1, int num2, int operation) {
    switch(operation) {
        case 1: return num1 & num2; //Bitwise AND
        case 2: return num1 | num2; //Bitwise OR
        case 3: return num1 ^ num2; //Bitwise XOR
        case 4: return ~num1; //Bitwise NOT
        case 5: return num1 << num2; //Left Shift
        case 6: return num1 >> num2; //Right Shift
        default: return 0;
    }
}

//Main function
int main() {
    int num1, num2, operation;
    
    printf("Enter two numbers:\n");
    scanf("%d%d", &num1, &num2);
    
    printf("Select a bitwise operation to perform:\n");
    printf("1. Bitwise AND\n2. Bitwise OR\n3. Bitwise XOR\n4. Bitwise NOT\n5. Left Shift\n6. Right Shift\n");
    scanf("%d", &operation);
    
    //Perform the selected bitwise operation and print the result
    printf("The result of the selected bitwise operation is: %d", configureBitwiseOperation(num1, num2, operation));
    
    return 0;
}