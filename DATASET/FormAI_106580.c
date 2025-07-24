//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include<stdio.h>

int printBinary(int num) {
    int rem = num % 2;
    if(num == 1) {
        printf("1");
        return 1;
    } else {
        printBinary(num/2);
        printf("%d", rem);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The binary representation of %d is ", num);
    printBinary(num);
    return 0;
}