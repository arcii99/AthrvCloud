//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include <stdio.h>

int checkBit(int num, int bit){
    return ((num & (1 << bit)) != 0);
}

int setBit(int num, int bit){
    return (num | (1 << bit));
}

int clearBit(int num, int bit){
    return (num & ~(1 << bit));
}

int toggleBit(int num, int bit){
    return (num ^ (1 << bit));
}

int main(){
    int num, bit;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The number in binary is: %d\n", num);
    printf("Enter a bit position (0-31): ");
    scanf("%d", &bit);
    printf("The bit at position %d is %d\n", bit, checkBit(num, bit));
    printf("Setting bit at position %d...\n", bit);
    num = setBit(num, bit);
    printf("The new number in binary is: %d\n", num);
    printf("Clearing bit at position %d...\n", bit);
    num = clearBit(num, bit);
    printf("The new number in binary is: %d\n", num);
    printf("Toggling bit at position %d...\n", bit);
    num = toggleBit(num, bit);
    printf("The new number in binary is: %d\n", num);
    return 0;
}